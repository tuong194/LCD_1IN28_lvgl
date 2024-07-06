/********************************************************************************************************
 * @file	nlc_sensor.h
 *
 * @brief	for TLSR chips
 *
 * @author	telink
 * @date	April. 21, 2023
 *
 * @par     Copyright (c) 2017, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#pragma once

#include "tl_common.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#if ((NLC_SENSOR_TYPE_SEL == NLCP_TYPE_OCS) || (NLC_SENSOR_TYPE_SEL == NLCP_TYPE_ALS))
// -------- sensor define ----------------
#define SENSOR_NONE							0 // use BDT or button to simulate.
#define SENSOR_ZSIR1000						1

#define NLC_SENSOR_SEL						SENSOR_ZSIR1000

// -------- sensor define end ------------
#if (NLC_SENSOR_SEL == SENSOR_ZSIR1000)
#define I2C_IC_ID_SLAVE						(0x54)			// has been left shift one bit
#define	NLC_I2C_CLK_SPEED					(200 * 1000) 	// unit: Hz
#elif
//
#endif

#if (CHIP_TYPE==CHIP_TYPE_8258)
#define	NLC_I2C_GPIO_GROUP					I2C_GPIO_GROUP_C2C3
#elif (CHIP_TYPE==CHIP_TYPE_B91)
#define NLC_I2C_IO_SDA						I2C_GPIO_SDA_B3
#define NLC_I2C_IO_SCL						I2C_GPIO_SCL_B2
#endif

#if (NLC_SENSOR_SEL == SENSOR_ZSIR1000)
	#if (NLC_SENSOR_TYPE_SEL == NLCP_TYPE_OCS)
#define ZSIR1000_MOTION_SENSED_EN			1
	#elif (NLC_SENSOR_TYPE_SEL == NLCP_TYPE_ALS)
#define ZSIR1000_AMBIENT_LIGHT_SENSED_EN	1
	#endif

	#if ZSIR1000_MOTION_SENSED_EN
#define OCCUPANCY_SENSOR_OUTPUT_PIN			GPIO_PD7
	#endif
#endif


void sensor_init_zsir(void);
void nlc_sensor_init(void);
u32 nlc_sensor_get(void);

#endif


