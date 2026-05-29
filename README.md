# First C++ Games

Early C++ game projects written during freshman year — a record of first steps
into systems programming and game logic. Five small terminal games, bundled
behind a single menu.

> 🎮 **Play in your browser:** once GitHub Pages is enabled (see
> [Run on the web](#run-on-the-web)), the whole collection runs as WebAssembly —
> no install required.

---

## The games

Launch `main` and pick from the menu:

| Key | Game | What it is |
| --- | --- | --- |
| `1` | **Snake** | Classic snake with levels, walls, bonuses and a high-score table |
| `2` | **Whac-A-Mole** | Reaction game — hit the moles, bank the money before lives run out |
| `3` | **Reversi** | Othello/Reversi against a simple AI |
| `4` | **Card game 99** | The "99" card game for up to 4 players |
| `5` | **Memory** | Flip-and-match memory game |
| `0` | quit | |

Controls are keyboard-only — typically `W` `A` `S` `D` to move and number keys
to choose menu items.

Two parallel ports live side by side: [`English version/`](English%20version)
and [`Chinese version/`](Chinese%20version). They are identical apart from the
on-screen text language.

---

## What this project explores

- Game-loop design and frame timing
- Terminal/console rendering (ASCII art, ANSI-style redraws)
- Real-time, non-blocking keyboard input (`_kbhit` / `_getch`)
- Collision detection and board logic
- Score tracking, save files, and state management

---

## Build & run natively (Windows)

The original code targets the Windows console (`<conio.h>`, `<windows.h>`):

```bash
# from inside "English version" (or "Chinese version")
g++ -o main main.cpp
./main
```

`main.cpp` `#include`s the individual games as one translation unit, so you
only ever compile `main.cpp`.

---

## Run on the web

The games are compiled to **WebAssembly** with [Emscripten](https://emscripten.org)
and rendered in a browser terminal ([xterm.js](https://xtermjs.org)). The
original sources are **not modified** — instead, [`web/shim/`](web/shim)
provides drop-in replacements for the two Windows-only headers:

| Windows API | Browser replacement |
| --- | --- |
| `Sleep(ms)` | `emscripten_sleep` (cooperative yield via Asyncify) |
| `system("cls")` | ANSI clear-screen escape |
| `SetConsoleTextAttribute` | ANSI SGR colour codes |
| `_kbhit` / `_getch` | keystroke queue fed by xterm.js |

### Automatic deployment

[`.github/workflows/web.yml`](.github/workflows/web.yml) compiles the project
and publishes it to GitHub Pages on every push to `main`. To turn it on:

1. **Settings → Pages → Build and deployment → Source: GitHub Actions.**
2. Push to `main` (or run the workflow manually). The live URL appears in the
   workflow's *deploy* step.

### Build the web version locally

Requires the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)
on your `PATH`:

```bash
bash web/build.sh            # builds the English version into web/public/
python -m http.server --directory web/public 8000
# open http://localhost:8000
```

Pass `"Chinese version"` as an argument to build that port instead.

> **Note:** high scores (`snakerank.txt`) are written to Emscripten's in-memory
> filesystem, so they reset on page reload. Persisting them across sessions
> (e.g. via `IDBFS`) is a possible enhancement.

---

## License

See [LICENSE](LICENSE).
