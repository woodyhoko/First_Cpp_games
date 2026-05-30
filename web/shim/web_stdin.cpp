/*
 * web_stdin.cpp — browser stdin shim.
 *
 * The games read interactive input two ways:
 *   - conio _getch()/_kbhit()  (handled by shim/conio.h via the xterm queue)
 *   - std::cin / scanf / getchar (Card 99, Reversi, …) which read libc stdin
 *
 * Without this file the libc-stdin path falls through to Emscripten's default
 * TTY, which pops up a blocking window.prompt() for every read — the annoying
 * "input popup that won't go away". Here we redirect libc read() for fd 0 to
 * the SAME xterm keystroke queue conio uses, so all input comes from the
 * in-page terminal instead of a modal.
 *
 * Wired up by the linker flag  -Wl,--wrap=read  in web/build.sh:
 *   references to read()  -> __wrap_read()  (this function)
 *   the original libc one -> __real_read()
 *
 * Blocking is cooperative via emscripten_sleep() (requires -sASYNCIFY, which
 * the build already enables), exactly like conio.h's _getch().
 */
#include <emscripten.h>
#include <unistd.h>
#include <cstddef>

extern "C" {

ssize_t __real_read(int fd, void* buf, size_t count);

ssize_t __wrap_read(int fd, void* buf, size_t count) {
    if (fd != 0) {
        /* Anything that isn't stdin keeps normal libc behaviour. */
        return __real_read(fd, buf, count);
    }

    unsigned char* out = static_cast<unsigned char*>(buf);
    size_t n = 0;
    while (n < count) {
        int c;
        /* Block until a key is queued, yielding to the browser each spin so
         * keystrokes can arrive and the page stays responsive. */
        for (;;) {
            c = EM_ASM_INT({ return (Module.getch ? Module.getch() : -1); });
            if (c >= 0) break;
            emscripten_sleep(8);
        }
        if (c == 13) c = 10;                                   /* Enter: CR -> LF */
        EM_ASM({ if (Module.echo) Module.echo($0); }, c);      /* echo to terminal */
        out[n++] = static_cast<unsigned char>(c);
        if (c == '\n') break;                                  /* line-buffered */
    }
    return static_cast<ssize_t>(n);
}

} /* extern "C" */
