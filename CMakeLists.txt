# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Set C++ standard globally for GCC 14.x compatibility with ESP-IDF newlib
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================================
# FORCE HEADLESS MODE (no display, no SD card, no touch)
# =============================================================================
# This disables all RGB LCD / touch / SD code so the project builds on the
# Arduino Nano ESP32. Change to =0 when you want full hardware support later.
add_compile_definitions(CONFIG_HEADLESS_MODE=1)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(LCCLightingTouchscreen)