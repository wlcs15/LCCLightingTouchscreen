# Build notes (local dual-IDF discipline)

**Required ESP-IDF: v5.1.6 only.**

Do **not** build or reconfigure this project with ESP-IDF 5.3+ or 6.x. OpenMRN fails to compile cleanly with newer GCC/newlib (libstdc++ incompatibilities). This is a hard project constraint, not a preference.

## Activate the correct toolchain

In a shell that has loaded `~/.bashrc` helpers:

```bash
esp5
cd ~/Git/wlcs15/vsi5004/LCCLightingTouchscreen
```

Or without aliases:

```bash
export IDF_PATH=~/esp/esp-idf-v5.1.6
. "$IDF_PATH/export.sh"
```

Confirm:

```bash
idf.py --version    # must show v5.1.6
idf_which           # optional helper
```

JTAG helpers in `~/.bashrc` (`flashjtag`, `erasejtag`, `gdbjtag`) already call **`esp5`** so they stay on 5.1.6.

## Build directories (do not mix IDFs)

| Directory | Purpose |
|-----------|---------|
| `build/` | **Active** ESP32-S3 firmware build under IDF **5.1.6 only** |

```bash
esp5
idf.py set-target esp32s3   # first time only
idf.py build
idf.py -p PORT flash monitor
```

Optional helper:

```bash
./utils/build_idf5.sh              # build
./utils/build_idf5.sh flash        # build + flash
```

Do **not** point this tree at IDF 6.1 “just to try.” Use a separate clone if you ever experiment.

## If the wrong IDF was used (recovery)

```bash
esp5
idf.py fullclean
# or: rm -rf build
idf.py set-target esp32s3
idf.py build
```

If `managed_components/` or `dependencies.lock` look wrong after a bad configure, restore from git / re-run build under 5.1.6 so Component Manager resolves against the correct IDF.

## Related projects on this machine

| Project | IDF | Activate |
|---------|-----|----------|
| This repo (`LCCLightingTouchscreen`) | **5.1.6** | `esp5` |
| `…/bobscott45/esp32_lever_frame` | **6.1** | `esp6` |

Prefer a **new terminal** when switching major IDF versions.
