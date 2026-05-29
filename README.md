# First C++ Games

Early C++ game projects written during freshman year — a record of first steps
into systems programming and game logic. Five small terminal games, bundled
behind a single menu and now playable straight from the browser.

> 🎮 **Play in your browser:** **<https://space.hoko.xyz/First_Cpp_games/>**
> — the whole collection runs as WebAssembly, no install required. Click the
> terminal to focus it, then press a number key.

---

## The games

Run `main` and pick from the menu:

| Key | Game | One-line description |
| --- | --- | --- |
| `1` | **Snake** | Classic snake with levels, walls, bonus food and a saved high-score table |
| `2` | **Whac-A-Mole** | Reaction game — whack moles for cash before your lives run out |
| `3` | **Reversi** *(Othello)* | The black-and-white disc-flipping board game, with a heuristic AI opponent |
| `4` | **99** *(card game)* | The running-total card game for 2–4 players |
| `5` | **Memory** | Flip-and-match concentration game with a memorise-then-recall timer |
| `0` | quit | Leave the program |

Controls are keyboard-only — typically `W` `A` `S` `D` to move and number keys
for menus.

Two parallel ports live side by side: [`English version/`](English%20version)
and [`Chinese version/`](Chinese%20version). They are identical apart from the
on-screen text language.

---

### 1 · Snake 🐍

A full take on the arcade classic: a title screen, a scrolling menu, multiple
**levels** with different wall layouts, **bonus food** that appears on a timer,
and a persistent **high-score table** written to `snakerank.txt`. Movement is
`W`/`A`/`S`/`D`; the speed (frame delay via `Sleep`) tightens as you progress.

### 2 · Whac-A-Mole 🔨

A 3×3 grid where moles and coins pop up and disappear on independent timers.
Hit a mole to earn money, but you start with **5 lives** — miss too often and
it's game over. A small economy (`money` / `turnintomoney`) tracks your score.

### 3 · Reversi (Othello) ⚫⚪

The disc-flipping board game played with black (`●`) and white (`○`) stones on
an 8×8 grid. It *looks* like Go, but the rule is different: you flank your
opponent's discs to flip them to your colour, and the most discs at the end
wins. Two modes — **human vs human** and **human vs computer**. The computer
opponent is the project's most interesting piece of logic; see
[The Reversi AI](#the-reversi-ai) below.

### 4 · "99" card game 🃏

A Taiwanese-style running-total card game for **2–4 players**. Each player holds
a hand; playing a card adds (or, for special cards, subtracts/skips/reverses)
its value to a shared running total. The total must never exceed **99** — if you
can't play without bursting, you lose the round. Cards `10`/`12` and others
carry special effects (direction reversal, minus, skips), tracked through the
`table`, `rota` and `minuscase` state.

### 5 · Memory game 🧠

A concentration / matching game. Symbols are revealed for a **countdown period**
(difficulty *Hard / Normal / Easy* sets how long), then hidden — you then enter
the coordinates of two cards you believe share a pattern. Match all pairs before
time runs out. Card faces are drawn by a small `shape()` routine.

---

## The Reversi AI

The Human-vs-Computer mode in Reversi runs a compact **positional + greedy**
heuristic (in [`compu()` and `sorting()`](English%20version/black%20and%20white%20test.cpp)).
It is not a random mover — it plays a recognisable Othello strategy:

1. **Simulate every legal move.** For each empty square the AI tentatively
   places a disc, runs the normal flip logic, and records **how many discs that
   move would flip** (its immediate gain). The board is then restored from a
   backup copy, so the search is non-destructive.

2. **Weight squares by position, not just by flips.** Candidate squares are
   scanned in deliberate **priority tiers** rather than left-to-right:
   - **Tier 1 — corners and edge-strategic squares** are evaluated first.
     Corners are the strongest squares in Othello because, once taken, they can
     never be flipped back.
   - **Tier 2 — the inner ring**, then
   - **Tier 3 — the remaining central squares.**

3. **Pick the best move in the highest tier that has one.** `sorting()` chooses
   the move with the largest flip count, but only *within the most valuable tier
   that contains a legal move* — so the AI prefers a corner/edge capture over a
   bigger central one, mirroring how strong human players value the board.

4. **Randomised tie-breaking.** When several moves tie, a small `rand()`-based
   nudge picks between them, so the computer isn't perfectly predictable across
   games.

5. **Pass detection.** If no move flips anything in any tier, the AI correctly
   **passes** its turn (`comskip`).

The result is a surprisingly capable opponent for a freshman project: it grabs
corners, maximises captures, and avoids the trap of always taking the locally
biggest flip in the centre.

---

## What this project explores

- Game-loop design and frame timing
- Terminal/console rendering (ASCII art, ANSI-style full-screen redraws)
- Real-time, non-blocking keyboard input (`_kbhit` / `_getch`)
- Collision detection and board logic
- A heuristic game AI (Reversi)
- Score tracking, save files, and state management

### Project layout

```
First_Cpp_games/
├── English version/        # all five games + the menu (main.cpp)
│   ├── main.cpp            #   unity build — #includes each game, runs the menu
│   ├── snake1.22.cpp       #   1 · Snake
│   ├── mole.cpp            #   2 · Whac-A-Mole
│   ├── black and white test.cpp  # 3 · Reversi (+ the AI)
│   ├── 99.cpp              #   4 · "99" card game
│   └── flip.cpp            #   5 · Memory game
├── Chinese version/        # same games, Chinese on-screen text
└── web/                    # WebAssembly port (shims + xterm.js frontend)
```

`main.cpp` `#include`s the individual `.cpp` files as a single translation unit,
so you only ever compile `main.cpp`.

---

## Build & run natively (Windows)

The original code targets the Windows console (`<conio.h>`, `<windows.h>`):

```bash
# from inside "English version" (or "Chinese version")
g++ -o main main.cpp
./main
```

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
and publishes it to GitHub Pages on every push to `main`. The live site is
**<https://space.hoko.xyz/First_Cpp_games/>**.

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
