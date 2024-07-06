/********************************************************************************************************
 * @file	nlc_sensor.c
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
#include "tl_common.h"
#include "proj_lib/sig_mesh/app_mesh.h"
#include "nlc_sensor.h"
#include "drivers.h"

/**
 *	include: ALSMP(Ambient Light Sensor Mesh Profile),ENMMP(Energy Monitor Mesh Profile),
 *			 OCSMP(Occupancy Sensor Mesh Profile).
 */

#if (LIGHT_TYPE_SEL == LIGHT_TYPE_NLC_SENSOR)

const u8 NLC_SENSOR_LOCAL_NAME[NLC_LOCAL_NAME_LEN] = {NLC_LOCAL_NAME};

void mesh_scan_rsp_add_local_name(u8 *p_name, u32 len_max)
{
	memcpy(p_name, NLC_SENSOR_LOCAL_NAME, min(len_max, NLC_LOCAL_NAME_LEN - 1));
}

#if ((NLC_SENSOR_TYPE_SEL == NLCP_TYPE_OCS) || (NLC_SENSOR_TYPE_SEL == NLCP_TYPE_ALS))
/**
 * @brief       This function ZSIR sensor init
 * @return      none
 * @note        none
 */
	#if (NLC_SENSOR_SEL == SENSOR_ZSIR1000)
void sensor_init_zsir(void)
{
	#if (CHIP_TYPE==CHIP_TYPE_B91)
	i2c_set_pin(NLC_I2C_IO_SDA,NLC_I2C_IO_SCL);
	i2c_master_init();
	i2c_set_master_clk((unsigned char)(sys_clk.pclk*1000*1000/(4 * NLC_I2C_CLK_SPEED)));
	#elif (CHIP_TYPE==CHIP_TYPE_8258)
	i2c_gpio_set(NLC_I2C_GPIO_GROUP);
	i2c_master_init(I2C_IC_ID_SLAVE, (unsigned char)(CLOCK_SYS_CLOCK_HZ/(4 * NLC_I2C_CLK_SPEED)) );
	#endif
	
	#if ZSIR1000_MOTION_SENSED_EN
	gpio_set_func(OCCUPANCY_SENSOR_OUTPUT_PIN, AS_GPIO);
    gpio_set_input_en(OCCUPANCY_SENSOR_OUTPUT_PIN, 1);

	u8 data = 0;
	i2c_read_series(0x03, 1, &data, 1);
	data &= 0xf0;
	data |= 0x01;
	i2c_write_series(0x03, 1, &data, 1); // set DELAY_OFF_TIME to 3 second.
	
	data = 0x40;
	i2c_write_series(0x04, 1, &data, 1); // close PWM of OUT0
	#endif

	#if ZSIR1000_AMBIENT_LIGHT_SENSED_EN
	u8 data = 0;
	i2c_read_series(0x03, 1, &data, 1);
	data &= 0xf0;
	data |= 0x01;
	i2c_write_series(0x03, 1, &data, 1); // ambient value can not be updataed when OUT0 is high, so need to set to min value.
	
	data = 0x10;
	i2c_write_series(0x0f, 1, &data, 1); // bit4 0:digital ambient light detection. 1:simulated ambient light detection
	#endif
}
	#endif

/**
 * @brief       This function sensor init
 * @param[in]   void- none
 * @return      none
 * @note        none
 */
void nlc_sensor_init(void)
{
	#if (NLC_SENSOR_SEL == SENSOR_ZSIR1000)
	sensor_init_zsir();
	#endif
}

/**
 * @brief       This function get seneor value
 * @param[in]   void- none
 * @return      none
 * @note        none
 */
	#if (NLC_SENSOR_SEL != SENSOR_NONE)
u32 nlc_sensor_get(void)
{
#if (NLC_SENSOR_SEL == SENSOR_ZSIR1000)
	#if ZSIR1000_MOTION_SENSED_EN
	return (0 != gpio_read(OCCUPANCY_SENSOR_OUTPUT_PIN));
	#elif ZSIR1000_AMBIENT_LIGHT_SENSED_EN
	unsigned char data = 0;
	i2c_read_series(0x12, 1, &data, 1);
	data = 255 - data; // 255 is most dark, translate raw data to unit of lux.
	return data;
	#endif
#endif

	return 0;
}
	#endif
#endif
#endif

