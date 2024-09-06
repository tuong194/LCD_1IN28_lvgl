/*
 * LED_TIMER.h
 *
 *  Created on: Jul 10, 2024
 *      Author: DELL
 */

#ifndef VENDOR_TUONG_LED_TIMER_H_
#define VENDOR_TUONG_LED_TIMER_H_

#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#define FREQ_LED 20000

#define LED_DI GPIO_PA5
#define LED_CI GPIO_PA6

typedef enum{
	BLUE_LC8823,
	GREEN_LC8823,
	RED_LC8823,
	YELLOW_LC8823,
	COLORx_LC8823,
}color_led_rgb;

typedef enum{
	ON_LED_SW1 = 0,
	OFF_LED_SW1,
}on_off_led_sw1;

typedef enum{
	ON_LED_SW2 = 0,
	OFF_LED_SW2,
}on_off_led_sw2;

typedef enum{
	ON_LED_SW3 = 0,
	OFF_LED_SW3,
}on_off_led_sw3;

typedef enum{
	ON_LED_SW4 = 0,
	OFF_LED_SW4,
}on_off_led_sw4;

typedef enum{
	START_FRAME,
	LED_FRAME,
	END_FRAME,

	END_GAME,
}frame_led8823;

typedef enum{
	Frame1,
	Frame2,
	Frame3,
	End_Frame,
}on_led;

#endif /* VENDOR_TUONG_LED_TIMER_H_ */
