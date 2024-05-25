/*
 * my_Function.h
 *
 *  Created on: May 23, 2024
 *      Author: DELL
 */

#ifndef VENDOR_TUONG_MY_FUNCTION_H_
#define VENDOR_TUONG_MY_FUNCTION_H_

#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "../UI/ui.h"

#define ADDR_START 0x20FFE000  //sector1: 4kB
#define ADDR_START2 0x20FFF000 //sector2: 4kB
#define GATEWAY_ADDRESS 0xFFFF
#define LED_ADDR 0xFFFF
#define TIMEOUT_SECURE 30

#define MODE_DIM_SET 0
#define MODE_CTT_SET 1
#define MODE_RGB_SET 2
u8 dim_set;
u8 ctt_set;

lv_color_t color;
u16 hsvH;
u32 timeProvision;
u8 countBlinkLed2;
u32 nowtime; u32 timeScene; u32 timeKickout; u32 timeOTA;

u8 checkOTA ;
u8 checkScene;
u8 checkKickout;
u8 checkProvision; u8 checkPro;


typedef struct {
	uint8_t Header[2];
	uint8_t Length;
	uint8_t OpCode[2];
	uint8_t Dim_Stt;
	uint8_t Cct_Stt;
	uint8_t CRC;
} Struct_OPCODE_SET_DIMCCT_t;


void BlinkLed1(u8 number);
void getValue(void);
void setValue(void);
void check_OTA(void);
void check_provision(void);
void displayClock(void);
void check_Scene(void);
void read_sw(void);
void Set_RGB(void);

#endif /* VENDOR_TUONG_MY_FUNCTION_H_ */
