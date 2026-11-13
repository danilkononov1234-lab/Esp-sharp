#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
command -v emcmake
emcmake cmake -S components/kgui/sim -B build-web -DCMAKE_BUILD_TYPE=Release
cmake --build build-web --parallel 4
mkdir -p dist
cp build-web/kgui_sim.html dist/index.html
cp build-web/kgui_sim.js build-web/kgui_sim.wasm dist/
