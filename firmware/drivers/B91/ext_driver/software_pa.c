/********************************************************************************************************
 * @file     software_pa.c
 *
 * @brief    This is the source file for BLE SDK
 *
 * @author	 BLE GROUP
 * @date         06,2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
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
 *******************************************************************************************************/
#include "tl_common.h"
#include "compiler.h"
#include "software_pa.h"
#include "../gpio.h"

#define USE_SOFTWARE_PA		0

#if (PA_ENABLE && (0 == USE_SOFTWARE_PA))
STATIC_ASSERT(((u32)PA_RXEN_PIN==(u32)RF_RFFE_RX_PB1)||((u32)PA_RXEN_PIN==(u32)RF_RFFE_RX_PD6)||((u32)PA_RXEN_PIN==(u32)RF_RFFE_RX_PE4));
STATIC_ASSERT(((u32)PA_TXEN_PIN==(u32)RF_RFFE_TX_PB0)||((u32)PA_TXEN_PIN==(u32)RF_RFFE_TX_PB6)||((u32)PA_TXEN_PIN==(u32)RF_RFFE_TX_PD7)||((u32)PA_TXEN_PIN==(u32)RF_RFFE_TX_PE5));
#endif

_attribute_data_retention_	rf_pa_callback_t  blc_rf_pa_cb = 0;

_attribute_ram_code_
void app_rf_pa_handler(int type)
{
#if(PA_ENABLE)
	if(type == PA_TYPE_TX_ON){
	    gpio_write(PA_RXEN_PIN, 0);
	    gpio_write(PA_TXEN_PIN, 1);
	}
	else if(type == PA_TYPE_RX_ON){
	    gpio_write(PA_TXEN_PIN, 0);
	    gpio_write(PA_RXEN_PIN, 1);
	}
	else{
	    gpio_write(PA_RXEN_PIN, 0);
	    gpio_write(PA_TXEN_PIN, 0);
	}
#endif
}


void rf_pa_init(void)
{
#if(PA_ENABLE)
	extern u8 my_rf_power_index;
	rf_set_power_level_index (my_rf_power_index);
#if	USE_SOFTWARE_PA
    gpio_set_func(PA_TXEN_PIN, AS_GPIO);
    gpio_set_output_en(PA_TXEN_PIN, 1);
    gpio_write(PA_TXEN_PIN, 0);

    gpio_set_func(PA_RXEN_PIN, AS_GPIO);
    gpio_set_output_en(PA_RXEN_PIN, 1);
    gpio_write(PA_RXEN_PIN, 0);

    blc_rf_pa_cb = app_rf_pa_handler;
#else
	rf_set_rffe_pin(PA_TXEN_PIN,PA_RXEN_PIN);
#endif
#endif
}

