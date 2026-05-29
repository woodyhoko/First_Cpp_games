/*
 * conio.h — Emscripten/browser compatibility shim.
 *
 * The original games include <conio.h> for non-blocking console input
 * (_kbhit / _getch), which only exists on Windows. When building for the
 * web we put this folder on the include path (`-I web/shim`) so the games
 * compile unmodified and these definitions are used instead.
 *
 * Input arrives asynchronously in the browser, so we read from a small
 * JavaScript-side queue that index.html fills from xterm.js keystrokes.
 * _getch() blocks by yielding to the browser event loop via emscripten_sleep
 * (requires the build flag -sASYNCIFY).
 */
#ifndef WEB_SHIM_CONIO_H
#define WEB_SHIM_CONIO_H

#include <emscripten.h>

/* Returns non-zero if a key is waiting in the browser input queue. */
static inline int _kbhit(void) {
    return EM_ASM_INT({ return (Module.kbhit ? Module.kbhit() : 0); });
}

/* Blocks until a key is available, then returns its character code. */
static inline int _getch(void) {
    for (;;) {
        int c = EM_ASM_INT({ return (Module.getch ? Module.getch() : -1); });
        if (c >= 0) return c;
        emscripten_sleep(8); /* yield to the browser so keystrokes can arrive */
    }
}

/* POSIX-style aliases, in case any source uses the un-underscored names. */
static inline int kbhit(void) { return _kbhit(); }
static inline int getch(void) { return _getch(); }

#endif /* WEB_SHIM_CONIO_H */
