/*
 * switch.h
 *
 *  Created on: May 7, 2024
 *      Author: DELL
 */

#ifndef VENDOR_TUONG_SWITCH_H_
#define VENDOR_TUONG_SWITCH_H_

#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#define TL_Key1 GPIO_PC2
#define TL_Key2 GPIO_PC0
#define TL_Key3 GPIO_PC3
#define TL_Key4 GPIO_PC1

#define SW_NOT_PRESS '\0'

#define LED1 GPIO_PB5
#define LED2 GPIO_PB7


#define  FUNC AS_GPIO

#define ONLED1  gpio_write(LED1, 1)
#define OFFLED1 gpio_write(LED1, 0)
#define ONLED2  gpio_write(LED2, 1)
#define OFFLED2 gpio_write(LED2, 0)

#define READ_LED1 gpio_read(LED1)
#define READ_LED2 gpio_read(LED2)

u8 stateSW;


void Pin_Switch_Config(void);
char ReadSW(void);


#endif /* VENDOR_TUONG_SWITCH_H_ */
