#!/usr/bin/env bash
# Build (and optionally flash) LCCLightingTouchscreen with ESP-IDF 5.1.6 only.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PORT="${IDF_PORT:-/dev/ttyACM1}"
IDF_PATH="${IDF_PATH_OVERRIDE:-${HOME}/esp/esp-idf-v5.1.6}"

if [[ ! -f "${IDF_PATH}/export.sh" ]]; then
  echo "ERROR: IDF 5.1.6 not found at ${IDF_PATH}" >&2
  exit 1
fi

# shellcheck source=/dev/null
. "${IDF_PATH}/export.sh"

VER="$(idf.py --version 2>/dev/null || true)"
case "${VER}" in
  *v5.1.6*|*5.1.6*) echo "Using ${VER}" ;;
  *)
    echo "ERROR: expected ESP-IDF v5.1.6, got: ${VER:-unknown}" >&2
    echo "Hint: run 'esp5' — do NOT use esp6 / IDF 6.x with this project" >&2
    exit 1
    ;;
esac

cd "${ROOT}"

if [[ ! -f build/CMakeCache.txt ]]; then
  echo "First-time configure: set-target esp32s3"
  idf.py set-target esp32s3
fi

ACTION="${1:-build}"
case "${ACTION}" in
  build)
    idf.py build
    ;;
  flash)
    idf.py build
    idf.py -p "${PORT}" flash
    ;;
  flash-monitor|monitor)
    idf.py build
    idf.py -p "${PORT}" flash monitor
    ;;
  fullclean)
    idf.py fullclean
    echo "Cleaned build/. Re-run: $0 build"
    ;;
  *)
    echo "Usage: $0 [build|flash|flash-monitor|fullclean]" >&2
    exit 2
    ;;
esac
