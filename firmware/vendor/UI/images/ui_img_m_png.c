// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: lcd_gc9a01

#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

// IMAGE DATA: assets/m.png
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_m_png_data[] = {
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x0A,0x00,0x11,0x09,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x1C,0x00,0x10,0x1B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x2D,0x00,0x10,0x2C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x3F,0x00,0x10,0x3E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x51,0x00,0x10,0x50,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x63,0x00,0x10,0x62,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0x00,0x10,0x75,0x00,0x10,0x74,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x86,0x00,0x10,0x85,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x98,0x00,0x10,0x97,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xA9,0x00,0x10,0xA8,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xBB,0x00,0x10,0xBA,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xCD,0x00,0x10,0xCC,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xDF,0x00,0x10,0xDE,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xF1,0x00,0x10,0xF0,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x04,0x00,0x10,0xFE,0x00,0x10,0xFE,0x00,0x10,0x04,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x15,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x14,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x27,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x26,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x39,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x38,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x4B,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x4A,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0x00,0x10,0x5C,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x5B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x6E,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x6D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x80,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x7F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x91,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x90,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xA3,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA2,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xB5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB4,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xC6,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0xC5,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xD8,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xD7,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xEA,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE9,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x01,0x00,0x10,0xFB,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFB,0x00,0x00,0x01,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x11,0x0F,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x0E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x20,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x1F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x32,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x31,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x44,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x43,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x56,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x55,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x68,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x67,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x79,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x78,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x8A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x89,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x9C,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x9B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xAE,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xAD,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xC0,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xBF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xD2,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xD1,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xE3,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE2,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xF5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF4,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x12,0x07,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x12,0x07,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x1A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0x19,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x2C,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x2B,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x3D,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x3C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x4F,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x4E,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x61,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x60,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x73,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x72,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x84,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x83,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x96,
    0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x95,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xA7,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA6,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xB9,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB8,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xCB,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xCA,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xDD,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xDC,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xEF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEE,0xFF,0xFF,0x00,0x00,0x15,0x03,0x00,0x10,0xFD,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFD,0x00,0x15,0x03,0x00,0x10,0x13,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x12,0x00,0x10,0x25,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x24,0x00,0x10,0x37,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x36,0x00,0x10,0x49,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x48,0x00,0x10,0x5A,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x59,0x00,0x10,0x6C,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x6B,
    0x00,0x10,0x7E,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x7D,0x00,0x10,0x8F,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x8E,0x00,0x10,0xA1,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xA0,0x00,0x10,0xB3,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB2,0x00,0x10,0xC3,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xC3,0x00,0x10,0xD1,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xD0,0x00,0x10,0xDC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xDA,0x00,0x10,0xE7,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE5,0x00,0x10,0xF2,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF0,0x00,0x10,0xF8,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF7,0x00,0x10,0xFA,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF8,0x00,0x10,0xFC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFA,0x00,0x10,0xFC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0xFB,0x00,0x10,0xF2,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB9,0x00,0x10,0x51,0x00,0x10,0x54,0x00,0x10,0xBB,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xF2,0x00,0x10,0xE3,0x00,0x10,0xFF,0x00,0x10,0xC4,0x00,0x10,0x04,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x15,0x03,0x00,0x10,0xC5,0x00,0x10,0xFF,0x00,0x10,0xE2,0x00,0x10,0xD3,0x00,0x10,0xFF,0x00,0x10,0x6F,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x72,0x00,0x10,0xFF,0x00,0x10,0xD3,0x00,0x10,0xBB,0x00,0x10,0xFF,0x00,0x10,0x91,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x93,0x00,0x10,0xFF,0x00,0x10,0xBA,0x00,0x10,0x90,0x00,0x10,0xFF,0x00,0x10,0xF6,0x00,0x10,0x50,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x52,0x00,0x10,0xF8,0x00,0x10,0xFF,0x00,0x10,0x8F,0x00,0x10,0x65,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE2,0x00,0x10,0xE5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x62,0x00,0x10,0x2F,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x2B,0x00,0x10,0x02,0x00,0x10,0xF0,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xEF,0x00,0x10,0x02,0xFF,0xFF,0x00,0x00,0x10,0xB8,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xB5,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x74,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x71,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x2D,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x2A,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0x01,0x00,0x10,0xE5,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xE4,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x9F,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,
    0x00,0x10,0xFF,0x00,0x10,0x9D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x59,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x57,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x14,0x00,0x10,0xFC,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xFB,0x00,0x10,0x13,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xBF,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0xBD,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x6E,0x00,0x10,0xFF,0x00,0x10,0xFF,0x00,0x10,0x6C,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x1C,0x00,0x10,0xFE,0x00,0x10,0xFE,0x00,0x10,0x1D,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0xCB,0x00,0x10,0xCA,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
    0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x7A,0x00,0x10,0x79,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x10,0x29,0x00,0x10,0x29,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,
};
const lv_img_dsc_t ui_img_m_png = {
    .header.always_zero = 0,
    .header.w = 10,
    .header.h = 98,
    .data_size = sizeof(ui_img_m_png_data),
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = ui_img_m_png_data
};
