/*
 * windows.h — Emscripten/browser compatibility shim.
 *
 * The original games use a small slice of the Win32 console API:
 *   - Sleep(ms)                          frame timing
 *   - system("cls")                      clear the screen
 *   - GetStdHandle / SetConsoleTextAttribute   text colour (Snake only)
 *
 * None of that exists outside Windows, so for the web build we put this
 * folder on the include path (`-I web/shim`) and map each call to an
 * Emscripten / ANSI-escape equivalent. The game sources stay untouched.
 */
#ifndef WEB_SHIM_WINDOWS_H
#define WEB_SHIM_WINDOWS_H

#include <emscripten.h>
#include <cstdio>
#include <cstring>

/* ------------------------------------------------------------------ *
 *  Make stdout unbuffered so each frame reaches the terminal promptly.
 *  (Emscripten's stdout is a pipe, hence fully buffered by default.)
 * ------------------------------------------------------------------ */
namespace web_compat_detail {
struct StdoutUnbuffer {
    StdoutUnbuffer() { setvbuf(stdout, 0, _IONBF, 0); }
};
static StdoutUnbuffer _stdout_unbuffer_instance;
} /* namespace web_compat_detail */

/* ------------------------------------------------------------------ *
 *  Sleep — yield to the browser event loop (needs -sASYNCIFY).
 * ------------------------------------------------------------------ */
static inline void Sleep(unsigned long milliseconds) {
    emscripten_sleep(milliseconds);
}

/* ------------------------------------------------------------------ *
 *  Console colour: SetConsoleTextAttribute -> ANSI SGR colour codes.
 *
 *  Win32 packs the foreground colour in the low nibble:
 *      bit0 = blue, bit1 = green, bit2 = red, bit3 = intensity.
 *  ANSI foreground codes are 30 + (R + 2G + 4B), bright base 90.
 *  e.g. attribute 2 (green)  -> \033[32m ; 7 (grey/white) -> \033[37m.
 * ------------------------------------------------------------------ */
typedef void* HANDLE;
#define STD_INPUT_HANDLE  (-10)
#define STD_OUTPUT_HANDLE (-11)
#define STD_ERROR_HANDLE  (-12)

static inline HANDLE GetStdHandle(int /*which*/) { return (HANDLE)0; }

static inline void SetConsoleTextAttribute(HANDLE /*h*/, int attribute) {
    int fg = attribute & 0x0F;
    int code = 30 + ((fg & 4) ? 1 : 0)   /* red   */
                  + ((fg & 2) ? 2 : 0)   /* green */
                  + ((fg & 1) ? 4 : 0);  /* blue  */
    if (fg & 8) code += 60;              /* intensity -> bright (90-97) */
    std::printf("\033[%dm", code);
}

/* ------------------------------------------------------------------ *
 *  system("cls") -> ANSI clear screen + scrollback + home cursor.
 *  Any other command (there are none in these games) is ignored.
 * ------------------------------------------------------------------ */
static inline int web_system(const char* command) {
    if (command && std::strstr(command, "cls")) {
        std::printf("\033[2J\033[3J\033[H");
    }
    return 0;
}
#define system(command) web_system(command)

#endif /* WEB_SHIM_WINDOWS_H */
