/********************************************************************************************************
 * @file	app_config_B91.h
 *
 * @brief	for TLSR chips
 *
 * @author	telink
 * @date	Sep. 30, 2010
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

/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
extern "C" {
#endif

#include "vendor/common/version.h"    // include mesh_config.h inside.
//////////////////board sel/////////////////////////////////////
#define PCBA_ADK80D_C1T213A20_V13          	1	// development board
#define PCBA_C1T213A16_V13_PA_DONGLE 		2	// PA dongle
#define PCBA_C1T213A3_V11_DONGLE			3 	// dongle without PA
#define PCBA_C1T216A20_V1_2                 4	//  without SWS for this PCBA.

#ifndef PCBA_B91_SEL // user can define in user_app_config.h
#define PCBA_B91_SEL			PCBA_ADK80D_C1T213A20_V13
#endif


#define _USER_CONFIG_DEFINED_	1	// must define this macro to make others known
#define	__LOG_RT_ENABLE__		0
//#define	__DEBUG_PRINT__			0

#define	FIRMWARE_SIZE_EXCEED_512K_EN	1	// be used to select correct flash map even though firmware size of bootloader is less than 512k
#if FIRMWARE_SIZE_EXCEED_512K_EN
#define FLASH_PLUS_ENABLE     	1	// means 2M flash for B91, 1M flash for B85m
#define PINGPONG_OTA_DISABLE    1 // it can disable only when flash plus.
#endif

// #define APP_FLASH_PROTECTION_ENABLE	1	// no need, becasue it will be protected in application firmware.

//////////// product  Information  //////////////////////////////
#define ID_VENDOR				0x248a			// for report
#define ID_PRODUCT_BASE			0x880C
#define STRING_VENDOR			L"Telink"
#define STRING_PRODUCT			L"BLE Mesh"
#define STRING_SERIAL			L"TLSR825X"

#define DEV_NAME                "SigMesh"

#define APPLICATION_DONGLE		0					// or else APPLICATION_DEVICE
#define	USB_PRINTER				1
#define	FLOW_NO_OS				1

/////////////////////HCI ACCESS OPTIONS///////////////////////////////////////
#define HCI_USE_NONE	0
#define HCI_USE_UART	1
#define HCI_USE_USB		2

#if WIN32
#define HCI_ACCESS		HCI_USE_USB
#else
#define HCI_ACCESS		HCI_USE_NONE
#endif 

#if (HCI_ACCESS==HCI_USE_UART)
#define UART_TX_PIN				UART0_TX_PB2
#define UART_RX_PIN				UART0_RX_PB3
#define UART_DMA_BAUDRATE		115200
#endif

#ifndef HCI_LOG_FW_EN
#define HCI_LOG_FW_EN   (0 || DEBUG_LOG_SETTING_DEVELOP_MODE_EN)
#if HCI_LOG_FW_EN
#define DEBUG_INFO_TX_PIN           		GPIO_PC4
#define PRINT_DEBUG_INFO                    1	// baudrate define by BAUD_USE
#endif
#endif

#define BATT_CHECK_ENABLE       			0   // need to connect GPIO_BAT_DETECT pin to VCC on PCBA when VBAT_CHANNEL_EN is 0.
#if (BATT_CHECK_ENABLE)
#define VBAT_CHANNEL_EN						0

#if VBAT_CHANNEL_EN
	/**		The battery voltage sample range is 1.8~3.5V    **/
#else
	/** 	if the battery voltage > 3.6V, should take some external voltage divider	**/
	#define GPIO_BAT_DETECT					GPIO_PB0
	#define PB0_FUNC						AS_GPIO
	#define PB0_INPUT_ENABLE				0
	#define PB0_OUTPUT_ENABLE				0
	#define PB0_DATA_OUT					0
	#define ADC_INPUT_PIN_CHN				ADC_GPIO_PB0
#endif
#endif

#define JTAG_DEBUG_ENABLE					0
#if (JTAG_DEBUG_ENABLE)//2-wire jtag mode

#define PE4_FUNC	AS_TDI  //JTAG 4-WIRE FUNCTION
#define PE5_FUNC	AS_TDO  //JTAG 4-WIRE FUNCTION
#define PE6_FUNC	AS_TMS  //JTAG 4-WIRE FUNCTION
#define PE7_FUNC	AS_TCK  //JTAG 4-WIRE FUNCTION

#define PE4_INPUT_ENABLE	1 //JTAG 4-WIRE FUNCTION
#define PE5_INPUT_ENABLE	1 //JTAG 4-WIRE FUNCTION
#define PE6_INPUT_ENABLE	1 //JTAG 4-WIRE FUNCTION
#define PE7_INPUT_ENABLE	1 //JTAG 4-WIRE FUNCTION

#define PULL_WAKEUP_SRC_PE4	GPIO_PIN_PULLUP_10K //JTAG 4-WIRE FUNCTION
#define PULL_WAKEUP_SRC_PE5	GPIO_PIN_PULLUP_10K //JTAG 4-WIRE FUNCTION
#define PULL_WAKEUP_SRC_PE6	GPIO_PIN_PULLUP_10K //JTAG 4-WIRE FUNCTION
#define PULL_WAKEUP_SRC_PE7	GPIO_PIN_PULLDOWN_100K //JTAG 4-WIRE FUNCTION
#endif


#define ADC_ENABLE		0
#if ADC_ENABLE
#define ADC_MODE				ADC_GPIO_MODE
#define ADC_CHNM_ANA_INPUT 		ADC_GPIO_PB3 // one of adc_input_pin_def_e
#define ADC_PRESCALER			ADC_PRESCALE_1F4
#endif

#define ONLINE_STATUS_EN        0

#define DUAL_MODE_ADAPT_EN 			0   // dual mode as master with Zigbee
#if (0 == DUAL_MODE_ADAPT_EN)
#define DUAL_MODE_WITH_TLK_MESH_EN  0   // dual mode as slave with Telink mesh
#endif

/////////////////// mesh project config /////////////////////////////////
#define TRANSITION_TIME_DEFAULT_VAL (0)

/////////////////// MODULE /////////////////////////////////
#define BLE_REMOTE_PM_ENABLE			0
#define PM_DEEPSLEEP_RETENTION_ENABLE   0
#define BLE_REMOTE_SECURITY_ENABLE      0
#define BLE_IR_ENABLE					0
#define BLE_SIG_MESH_CERTIFY_ENABLE 	0

#ifndef BLT_SOFTWARE_TIMER_ENABLE
#define BLT_SOFTWARE_TIMER_ENABLE		0
#endif

//////////////////////////// KEYSCAN/MIC  GPIO //////////////////////////////////
#ifndef UI_KEYBOARD_ENABLE
#define UI_KEYBOARD_ENABLE				0
#endif

#if UI_KEYBOARD_ENABLE
#define	MATRIX_ROW_PULL					PM_PIN_PULLDOWN_100K // drive pin pull
#define	MATRIX_COL_PULL					PM_PIN_PULLUP_10K    // scan pin pull

#define	KB_LINE_HIGH_VALID				0   // dirve pin output 0 when keyscan(no drive pin in KB_LINE_MODE=1), scanpin read 0 is valid
#define DEEPBACK_FAST_KEYSCAN_ENABLE	1   //proc fast scan when deepsleep back triggered by key press, in case key loss
#define KEYSCAN_IRQ_TRIGGER_MODE		0
#define LONG_PRESS_KEY_POWER_OPTIMIZE	1   //lower power when pressing key without release

//stuck key
#define STUCK_KEY_PROCESS_ENABLE		0
#define STUCK_KEY_ENTERDEEP_TIME		60  //in s

//repeat key
#define KB_REPEAT_KEY_ENABLE			0
#define	KB_REPEAT_KEY_INTERVAL_MS		200
#define KB_REPEAT_KEY_NUM				1
//

//----------------------- GPIO for UI --------------------------------
#if ((0 == PM_DEEPSLEEP_RETENTION_ENABLE) && DUAL_VENDOR_EN)
#define SLEEP_FUNCTION_DISABLE          1
#endif

#if ((PCBA_B91_SEL == PCBA_ADK80D_C1T213A20_V13) || (PCBA_B91_SEL == PCBA_ADK80D_C1T213A20_V13))
// keymap
#define KEY_SW1		1			// PCB mark SW4		
#define KEY_SW2		2			
#define KEY_SW3		3			
#define KEY_SW5		5			
#define	KB_MAP_NORMAL			{\
								{KEY_SW2,	KEY_SW3},	 \
								{KEY_SW1,	KEY_SW5},	 }

#define KB_DRIVE_PINS 		 	{GPIO_PC3, GPIO_PC1}
#define KB_SCAN_PINS   			{GPIO_PC2, GPIO_PC0}

#define	SW1_GPIO				GPIO_PC0
#define	SW2_GPIO				GPIO_PC2

//drive pin as gpio
#define	PC1_FUNC				AS_GPIO
#define	PC3_FUNC				AS_GPIO

//drive pin need 100K pulldown
#define	PULL_WAKEUP_SRC_PC1		MATRIX_ROW_PULL
#define	PULL_WAKEUP_SRC_PC3		MATRIX_ROW_PULL

//drive pin open input to read gpio wakeup level
#define PC1_INPUT_ENABLE		1
#define PC3_INPUT_ENABLE		1

//scan pin as gpio
#define	PC0_FUNC				AS_GPIO
#define	PC2_FUNC				AS_GPIO

//scan  pin need 10K pullup
#define	PULL_WAKEUP_SRC_PC0		MATRIX_COL_PULL
#define	PULL_WAKEUP_SRC_PC2		MATRIX_COL_PULL

//scan pin open input to read gpio level
#define PC0_INPUT_ENABLE		1
#define PC2_INPUT_ENABLE		1

#if	IRQ_GPIO_ENABLE
#define IRQ_GPIO_SELECT			GPIO_PD2
#endif

#elif (PCBA_B91_SEL == PCBA_C1T213A16_V13_PA_DONGLE)
// key mode, KB_LINE_MODE default 0(key matrix), set to 1 in button mode.
#define KB_LINE_MODE			1 			

// keymap
#define KEY_SW1		1
#define KEY_SW2		2
#define KB_MAP_NORMAL			{{KEY_SW1},	{KEY_SW2}}

#define KB_DRIVE_PINS			{GPIO_PB1} 	// make no sense, just for compile, not driver pin in KB_LINE_MODE=1.
#define KB_SCAN_PINS			{GPIO_PB1, GPIO_PB2}

#define	SW1_GPIO				GPIO_PB1	// PCB mark SW1
#define	SW2_GPIO				GPIO_PB2	// PCB mark SW2

// scan pin as gpio
#define PB1_FUNC				AS_GPIO
#define PB2_FUNC				AS_GPIO

//scan  pin pullup
#define PULL_WAKEUP_SRC_PB1     PM_PIN_PULLUP_1M	//btn
#define PULL_WAKEUP_SRC_PB2     PM_PIN_PULLUP_1M	//btn

//scan pin open input to read gpio level
#define PB1_INPUT_ENABLE		1
#define PB2_INPUT_ENABLE		1
#elif (PCBA_B91_SEL == PCBA_C1T213A3_V11_DONGLE)
// key mode, KB_LINE_MODE default 0(key matrix), set to 1 in button mode.
#define KB_LINE_MODE			1 			

// keymap
#define KEY_SW1		1
#define KEY_SW2		2
#define KB_MAP_NORMAL			{{KEY_SW1},	{KEY_SW2}}

#define KB_DRIVE_PINS			{GPIO_PB3} 	// make no sense, just for compile, not driver pin in KB_LINE_MODE=1.
#define KB_SCAN_PINS			{GPIO_PB3, GPIO_PB2}

#define	SW1_GPIO				GPIO_PB3	// PCB mark SW7
#define	SW2_GPIO				GPIO_PB2	// PCB mark SW2

// scan pin as gpio
#define PB2_FUNC				AS_GPIO
#define PB3_FUNC				AS_GPIO

//scan  pin pullup
#define PULL_WAKEUP_SRC_PB2     PM_PIN_PULLUP_1M	//btn
#define PULL_WAKEUP_SRC_PB3     PM_PIN_PULLUP_1M	//btn

//scan pin open input to read gpio level
#define PB2_INPUT_ENABLE		1
#define PB3_INPUT_ENABLE		1
#else
	#error "Current board do not support keyboard !"
#endif
#endif

#define XIAOMI_MODULE_ENABLE	MI_API_ENABLE
#define XIAOMI_TEST_CODE_ENABLE 	0

//---------------  LED / PWM
#if(PCBA_B91_SEL == PCBA_ADK80D_C1T213A20_V13)
#define PWM_R       PWM_PWM2_PB7	//red
#define PWM_G       PWM_PWM1_PB5	//green
#define PWM_B       PWM_PWM0_PB4	//blue
#define PWM_W       PWM_PWM5_PB0	//white // GPIO_PB6 is not PWM IO // please connect TL_PB0 to LED_W for J34 from C1T213A20_V1_3.pdf.
#elif(PCBA_B91_SEL == PCBA_C1T213A16_V13_PA_DONGLE)
#define PWM_R       PWM_PWM0_PB4	//red
#define PWM_G       PWM_PWM5_PB0	//green
#define PWM_B       PWM_PWM2_PB7	//blue
#define PWM_W       PWM_PWM1_PB5	//white
#elif(PCBA_B91_SEL == PCBA_C1T213A3_V11_DONGLE)
#define PWM_R       PWM_PWM0_PB4	//red
#define PWM_G       PWM_PWM5_PB0	//green
#define PWM_B       PWM_PWM2_PB7	//blue
#define PWM_W       PWM_PWM1_PB5	//white
#elif(PCBA_B91_SEL == PCBA_C1T216A20_V1_2)
#define PWM_R       PWM_PWM3_PB1	//red
#define PWM_G       PWM_PWM1_PB5	//green
#define PWM_B       PWM_PWM5_PB0	//blue
#define PWM_W       GPIO_PB6		//white // TODO: PB6 is not PWM.
#endif

#define PWM_FUNC_R  0  // no use, just for compile
#define PWM_FUNC_G  0  // no use, just for compile
#define PWM_FUNC_B  0  // no use, just for compile
#define PWM_FUNC_W  0  // no use, just for compile

#define PWMID_R     get_pwmid(PWM_R)
#define PWMID_G     get_pwmid(PWM_G)
#define PWMID_B     get_pwmid(PWM_B)
#define PWMID_W     get_pwmid(PWM_W)
                    
#define PWM_INV_R   get_pwm_invert_val(PWM_R)
#define PWM_INV_G   get_pwm_invert_val(PWM_G)
#define PWM_INV_B   get_pwm_invert_val(PWM_B)
#define PWM_INV_W   get_pwm_invert_val(PWM_W)

#ifndef GPIO_LED
#define GPIO_LED	PWM_R
#endif

/////////////open SWS digital pullup to prevent MCU err, this is must ////////////
//#define PA7_DATA_OUT			1 // TODO, no need for B91 ?


/////////////////// Clock  /////////////////////////////////
#define CLOCK_SYS_CLOCK_HZ  	48000000
#define     PWM_PCLK_SPEED				12000000 //pwm clock 12M.
enum{
	CLOCK_PWM_CLOCK_1S = PWM_PCLK_SPEED,
	CLOCK_PWM_CLOCK_1MS = (CLOCK_PWM_CLOCK_1S / 1000),
	CLOCK_PWM_CLOCK_1US = (CLOCK_PWM_CLOCK_1S / 1000000),
};


/////////////////// watchdog  //////////////////////////////
#define MODULE_WATCHDOG_ENABLE		0
#define WATCHDOG_INIT_TIMEOUT		2000  //in mi mode the watchdog timeout is 20s



/////////////////// set default   ////////////////

#include "../common/default_config.h"

/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
}
#endif
