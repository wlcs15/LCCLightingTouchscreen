# The following lines must be in this exact order
cmake_minimum_required(VERSION 3.16)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================================
# Build configuration defines
# =============================================================================
# Force headless mode (no display / touch)
add_compile_definitions(CONFIG_HEADLESS_MODE=1)

# Enable / disable SD card (set to 0 to use internal LittleFS instead)
add_compile_definitions(CONFIG_SD_CARD_ENABLED=0)

# LittleFS support — we will enable the component properly below
# (the if() block you had was in the wrong place)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(LCCLightingTouchscreen)

# LittleFS is already included in ESP-IDF v5.1 — no need for EXTRA_COMPONENT_DIRS
# We will enable it via REQUIRES in the component that uses it (or in main)