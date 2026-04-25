/**
 * @file fs_config.h
 * @brief Filesystem path configuration - SD card vs LittleFS
 */

#pragma once

#if CONFIG_SD_CARD_ENABLED
    #define BASE_FS_PATH     "/sdcard"
    #define FS_MOUNT_POINT   "/sdcard"
#else
    #define BASE_FS_PATH     "/littlefs"
    #define FS_MOUNT_POINT   "/littlefs"
#endif

// File names
#define SCENES_FILE          "scenes.json"
#define SCENES_TMP_FILE      "scenes.tmp"
#define NODEID_FILE          "nodeid.txt"
#define SPLASH_FILE          "SPLASH.JPG"
#define OPENMRN_CONFIG_FILE  "openmrn_config"
#define LCC_CONFIG_BIN_FILE  "lcc_config.bin"

// Full paths (these are the ones you should use everywhere)
#define SCENES_PATH          BASE_FS_PATH "/" SCENES_FILE
#define SCENES_TMP_PATH      BASE_FS_PATH "/" SCENES_TMP_FILE
#define NODEID_PATH          BASE_FS_PATH "/" NODEID_FILE
#define SPLASH_PATH          BASE_FS_PATH "/" SPLASH_FILE
#define OPENMRN_CONFIG_PATH  BASE_FS_PATH "/" OPENMRN_CONFIG_FILE
#define LCC_CONFIG_PATH      BASE_FS_PATH "/" LCC_CONFIG_BIN_FILE   // safe name