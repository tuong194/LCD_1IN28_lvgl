// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: lcd_gc9a01

#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

// IMAGE DATA: assets/h.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_h_png_data[] = {
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x11,0x09,0x00,0x10,0x08,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x1A,0x00,0x10,0x19,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x2B,0x00,0x10,0x2A,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x3B,0x00,0x10,0x3A,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x4C,0x00,0x10,0x4B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x5D,0x00,0x10,0x5C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x6E,0x00,0x10,0x6D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x7F,0x00,0x10,0x7E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x8F,0x00,0x10,0x8E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xA0,0x00,0x10,0x9F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xB1,0x00,0x10,0xB0,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xC2,0x00,0x10,0xC1,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xD3,0x00,0x10,0xD2,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xE4,0x00,0x10,0xE3,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xF4,0x00,0x10,0xF3,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x06,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x06,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x16,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x15,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x27,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x26,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x38,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x37,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x49,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x48,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x5A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x59,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x6A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x69,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x7B,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x7A,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x8C,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x8B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x9D,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x9C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xAD,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xAC,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xBE,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xBD,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xCF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xCE,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xE0,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xDF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xF1,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF0,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x15,0x03,0x00,0x10,0xFE,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFE,0x00,0x15,0x03,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x13,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x12,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0x00,0x10,0x23,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x22,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x34,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x33,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x45,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x44,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x56,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x55,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x67,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x66,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x78,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x77,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x88,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x87,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x99,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x98,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0x00,0x10,0xAA,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA9,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xBB,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xBA,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xCC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xCB,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xDC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xDB,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xED,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEC,0xFF,0xFF,0x00,0x00,0x00,0x01,0x00,0x10,0xFC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFC,0x00,0x00,0x01,0x00,0x11,0x0F,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x0E,0x00,0x10,0x20,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x1F,
    0x00,0x10,0x31,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x30,0x00,0x10,0x41,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x40,0x00,0x10,0x52,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x51,0x00,0x10,0x63,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x62,0x00,0x10,0x74,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x73,0x00,0x10,0x85,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x84,0x00,0x10,0x95,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x94,0x00,0x10,0xA6,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA5,
    0x00,0x10,0xB7,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB6,0x00,0x10,0xC8,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xC7,0x00,0x10,0xD5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xD6,0x00,0x10,0xE1,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE1,0x00,0x10,0xEB,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEC,0x00,0x10,0xF5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF0,0x00,0x10,0xFA,0x00,0x10,0xFF,0x00,0x10,0xC7,0x00,0x10,0x4B,0x00,0x10,0x4C,0x00,0x10,0xC9,0x00,0x10,0xFF,0x00,0x10,0xF4,0x00,0x10,0xFC,0x00,0x10,0xE9,0x00,0x11,0x0F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x10,0x00,0x10,0xEB,0x00,0x10,0xF7,
    0x00,0x10,0xFD,0x00,0x10,0xB1,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xB2,0x00,0x10,0xFB,0x00,0x10,0xF7,0x00,0x10,0xD1,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x01,0x00,0x10,0xD3,0x00,0x10,0xF7,0x00,0x10,0xE8,0x00,0x10,0xFF,0x00,0x10,0x79,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x10,0x7C,0x00,0x10,0xFF,0x00,0x10,0xE8,0x00,0x10,0xD9,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEC,0x00,0x10,0xED,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xD9,0x00,0x10,0xB8,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB6,0x00,0x10,0x87,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x85,0x00,0x10,0x56,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x54,0x00,0x10,0x26,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x23,
    0x00,0x10,0x02,0x00,0x10,0xF0,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEF,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x10,0xB2,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xAF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x70,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x6D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x2D,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x2B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x01,0x00,0x10,0xE7,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE8,0x00,0x00,0x01,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xA5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA4,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x5A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x58,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x10,0x00,0x10,0xFA,0x00,0x10,0xFB,0x00,0x10,0x11,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xC0,0x00,0x10,0xBE,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x73,0x00,0x10,0x72,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x26,0x00,0x10,0x26,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
};
const lv_img_dsc_t ui_img_h_png = {
    .header.always_zero = 0,
    .header.w = 8,
    .header.h = 83,
    .data_size = sizeof(ui_img_h_png_data),
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = ui_img_h_png_data
};

