/**
 * @file waveshare_lcd.h
 * @brief RGB LCD Driver for Waveshare ESP32-S3 Touch LCD 4.3B
 */

#pragma once

#include "esp_err.h"
#include <stdbool.h>          // Needed for the dummy callback type in headless mode

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_HEADLESS_MODE
    #include "esp_lcd_panel_ops.h"
    #include "esp_lcd_panel_rgb.h"
    #include "ch422g.h"

    #define LCD_GPIO_VSYNC      GPIO_NUM_3
    #define LCD_GPIO_HSYNC      GPIO_NUM_46
    #define LCD_GPIO_DE         GPIO_NUM_5
    #define LCD_GPIO_PCLK       GPIO_NUM_7

    #define LCD_GPIO_DATA0      GPIO_NUM_14
    #define LCD_GPIO_DATA1      GPIO_NUM_38
    #define LCD_GPIO_DATA2      GPIO_NUM_18
    #define LCD_GPIO_DATA3      GPIO_NUM_17
    #define LCD_GPIO_DATA4      GPIO_NUM_10
    #define LCD_GPIO_DATA5      GPIO_NUM_39
    #define LCD_GPIO_DATA6      GPIO_NUM_0
    #define LCD_GPIO_DATA7      GPIO_NUM_45
    #define LCD_GPIO_DATA8      GPIO_NUM_48
    #define LCD_GPIO_DATA9      GPIO_NUM_47
    #define LCD_GPIO_DATA10     GPIO_NUM_21
    #define LCD_GPIO_DATA11     GPIO_NUM_1
    #define LCD_GPIO_DATA12     GPIO_NUM_2
    #define LCD_GPIO_DATA13     GPIO_NUM_42
    #define LCD_GPIO_DATA14     GPIO_NUM_41
    #define LCD_GPIO_DATA15     GPIO_NUM_40
#endif

typedef struct {
    int h_res;
    int v_res;
    int pixel_clock_hz;
    int num_fb;
    int bounce_buffer_size_px;
#ifndef CONFIG_HEADLESS_MODE
    ch422g_handle_t ch422g_handle;
#else
    void *ch422g_handle;
#endif
} waveshare_lcd_config_t;

#ifndef CONFIG_HEADLESS_MODE
    typedef esp_lcd_rgb_panel_vsync_cb_t waveshare_vsync_cb_t;
#else
    typedef bool (*waveshare_vsync_cb_t)(void *panel_handle, void *user_ctx);
#endif

esp_err_t waveshare_lcd_init(const waveshare_lcd_config_t *config, void **panel_handle);

esp_err_t waveshare_lcd_register_vsync_callback(
    void *panel_handle,
    waveshare_vsync_cb_t callback,
    void *user_ctx
);

esp_err_t waveshare_lcd_get_frame_buffer(
    void *panel_handle,
    int num_fbs,
    void **fb0,
    void **fb1
);

#ifdef __cplusplus
}
#endif