#!/usr/bin/env bash
#
# Compile the C++ game collection to WebAssembly with Emscripten.
#
# Usage:   web/build.sh ["English version" | "Chinese version"]
# Requires: the Emscripten SDK on PATH (emcc).  Install from
#           https://emscripten.org/docs/getting_started/downloads.html
#
# Output:  web/public/{index.html, game.js, game.wasm}  — a static site you
#          can open with any web server (e.g. `python -m http.server`).

set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/.." && pwd)"

VERSION="${1:-English version}"
SRC="$ROOT/$VERSION/main.cpp"
OUT="$HERE/public"

if ! command -v emcc >/dev/null 2>&1; then
  echo "error: emcc not found on PATH. Install the Emscripten SDK first." >&2
  exit 1
fi
if [ ! -f "$SRC" ]; then
  echo "error: source not found: $SRC" >&2
  exit 1
fi

mkdir -p "$OUT"

echo "Building \"$VERSION\" -> $OUT/game.js"
emcc "$SRC" \
  -I "$HERE/shim" \
  -std=c++14 \
  -O2 \
  -sASYNCIFY \
  -sASYNCIFY_STACK_SIZE=131072 \
  -sALLOW_MEMORY_GROWTH=1 \
  -sEXPORTED_RUNTIME_METHODS=FS,callMain \
  -sEXIT_RUNTIME=0 \
  -sINVOKE_RUN=1 \
  -o "$OUT/game.js"

cp "$HERE/index.html" "$OUT/index.html"

echo "Done. Serve it locally with:"
echo "    python -m http.server --directory \"$OUT\" 8000"
echo "then open http://localhost:8000"
