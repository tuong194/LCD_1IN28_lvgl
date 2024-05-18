/*
 * main.h
 *
 *  Created on: May 7, 2024
 *      Author: DELL
 */
#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#ifndef VENDOR_MESH_MAIN_H_
#define VENDOR_MESH_MAIN_H_

 u8 stateLed,stateLed1;
 u8 gio, phut, giay;
 u8 buf[10];

unsigned int get_sys_elapse(void);

#endif /* VENDOR_MESH_MAIN_H_ */
