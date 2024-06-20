/*
 * LED_LC8823.h
 *
 *  Created on: Jun 18, 2024
 *      Author: DELL
 */

#ifndef VENDOR_TUONG_LED_LC8823_H_
#define VENDOR_TUONG_LED_LC8823_H_

#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#define LED_DI GPIO_PA5
#define LED_CI GPIO_PA6

typedef enum{
	BLUE_LC8823,
	GREEN_LC8823,
	RED_LC8823,
}color_led_rgb;



void Config_Pin_Led_Lc8823(void);
void On_Led(u8 led_num, color_led_rgb color);
void On_20_Led_Blue(void);
void On_20_Led_Green(void);
void On_20_Led_Red(void);
void Blink_20_Led_Red(void);
void Blink_20_Led_Green(void);
void Blink_20_Led_Blue(void);
void Off_20_Led(void);

#endif /* VENDOR_TUONG_LED_LC8823_H_ */
