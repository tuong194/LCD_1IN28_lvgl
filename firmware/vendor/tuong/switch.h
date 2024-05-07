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

#define  FUNC AS_GPIO

u8 stateSW;

void Pin_Switch_Config(void);
char ReadSW(void);


#endif /* VENDOR_TUONG_SWITCH_H_ */
