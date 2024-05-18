/********************************************************************************************************
 * @file	main.c
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
#include "tl_common.h"
#include "proj/mcu/watchdog_i.h"
#include "vendor/common/user_config.h"
#include "drivers.h"
#include "proj_lib/ble/blt_config.h"
#include "proj_lib/ble/ll/ll.h"
#include "proj_lib/sig_mesh/app_mesh.h"

#include "../lvgl/lvgl.h"
#include "../tuong/LCD_128.h"
#include "../tuong/LCD_lvgl.h"
#include "../tuong/switch.h"
#include "../lvgl/demos/benchmark/lv_demo_benchmark.h"
//#include "../lvgl/demos/music/lv_demo_music.h"
#include "../lvgl/examples/lv_examples.h"


#include "../UI/ui.h"


extern void user_init();
extern void main_loop ();
void blc_pm_select_none();

#define ADDR_START 0x20FFE000

char swx;
int16_t indx;
u8 dim_set;

u8 stateLed2,stateLed1;
u8 gio, phut, giay;
u8 buf[10];

u32 nowtime; u32 timeScene; u32 timeKickout;
u32 sumSec;u32 sumMin; u32 sumHour;


u8 checkScene;
u8 checkKickout=0;
u8 checkProvision = 0;


unsigned int get_sys_elapse(void)
{
	static unsigned int my_sys_pre_tick;
	unsigned int now = stimer_get_tick();
	unsigned int ms;
	static unsigned int elapseFullCnt = 0;

	if( now <  my_sys_pre_tick) //overflow
	{
        elapseFullCnt++;
	}

	ms = now / 24000;

	my_sys_pre_tick = now;

	return (ms + elapseFullCnt * (0xFFFFFFFF/24000));
}



#define GATEWAYADDRESS 0xFFFF
void RD_Send_Relay_Stt(uint8_t Relay_ID, uint8_t Relay_Stt)
{
	uint8_t Mess_Buff[8] = {0};
	uint16_t Element_Add = 0x0000;

	Mess_Buff[0]		= Relay_Stt;
	Element_Add 		= ele_adr_primary + (Relay_ID-1);

	mesh_tx_cmd2normal(G_ONOFF_STATUS, Mess_Buff, 1, Element_Add, GATEWAYADDRESS, 2);

//	char UART_TempSend[128];
//	sprintf(UART_TempSend,"Messenger On-Off Gw:0x%x- Relay: %d--%d--%d--%d  \n",RD_GATEWAYADDRESS, relay_Stt[0], relay_Stt[1], relay_Stt[2], relay_Stt[3]);
//	uart_CSend(UART_TempSend);
}

typedef struct {
	uint8_t Header[2];
	uint8_t Length;
	uint8_t OpCode[2];
	uint8_t Dim_Stt;
	uint8_t Cct_Stt;
	uint8_t CRC;
} Struct_OPCODE_SET_DIMCCT_t;
#define LED_ADDR 0xFFFF

/*
static void RD_Model_OPCODE_SET_DIMCCT(void)
{
	Struct_OPCODE_SET_DIMCCT_t *mess_buff;

	mess_buff = (Struct_OPCODE_SET_DIMCCT_t*) vrts_GWIF_IncomeMessage;

	u8 dim_set	= mess_buff->Dim_Stt;
	u8 cct_set = mess_buff->Cct_Stt;

	//rdPrintf("OPCODE SET dim: %d% cct:%d %", dim_set, cct_set);
	access_cmd_set_light_ctl_100(LED_ADDR, 2 , dim_set, cct_set, 0);
	//access_cmd_set_light_ctl(0xffff, 2 , lum2_lightness(dim_set), cct_set, 0, &TTS_CTRL_DF);
}
*/



#if (HCI_ACCESS==HCI_USE_UART)
#include "proj/drivers/uart.h"
extern my_fifo_t hci_rx_fifo;

u16 uart_tx_irq=0, uart_rx_irq=0;

_attribute_ram_code_ void irq_uart_handle()
{
	unsigned char irqS = reg_dma_rx_rdy0;
	if(irqS & FLD_DMA_CHN_UART_RX)	//rx
	{
		uart_rx_irq++;
		reg_dma_rx_rdy0 = FLD_DMA_CHN_UART_RX;
		u8* w = hci_rx_fifo.p + (hci_rx_fifo.wptr & (hci_rx_fifo.num-1)) * hci_rx_fifo.size;
		if(w[0]!=0)
		{
			my_fifo_next(&hci_rx_fifo);
			u8* p = hci_rx_fifo.p + (hci_rx_fifo.wptr & (hci_rx_fifo.num-1)) * hci_rx_fifo.size;
			reg_dma0_addr = (u16)((u32)p);
		}
	}

	if(irqS & FLD_DMA_CHN_UART_TX)	//tx
	{
		uart_tx_irq++;
		reg_dma_rx_rdy0 = FLD_DMA_CHN_UART_TX;
	}
}
#endif

#if IRQ_TIMER1_ENABLE
_attribute_ram_code_ void irq_timer_handle()
{
    u32 src = reg_irq_src;
    static u32 A_debug_irq_cnt =0;
    if(src & FLD_IRQ_TMR1_EN){
       A_debug_irq_cnt++;
       reg_tmr_sta = FLD_TMR_STA_TMR1;
       gpio_write(GPIO_PA1,A_debug_irq_cnt%2);
    }
}
#endif

#if	IRQ_GPIO_ENABLE

void irq_gpio_handle()
{
	u32 src = reg_irq_src;
	if(src & FLD_IRQ_GPIO_EN){
		gpio_irq_user_handle();
		reg_irq_src = FLD_IRQ_GPIO_EN;        // clear irq_gpio irq flag		
	}

	/************* gpio irq risc0 *************/
	if(src & FLD_IRQ_GPIO_RISC0_EN){
		gpio_risc0_user_handle();
		reg_irq_src = FLD_IRQ_GPIO_RISC0_EN;        // clear irq_gpio irq flag				
	}

	/************* gpio irq risc1 *************/
	if(src & FLD_IRQ_GPIO_RISC1_EN){
		gpio_risc1_user_handle();
		reg_irq_src = FLD_IRQ_GPIO_RISC1_EN;        // clear irq_gpio irq flag		
	}
	#if (!(__TL_LIB_8258__ || (MCU_CORE_TYPE && MCU_CORE_TYPE == MCU_CORE_8258) || (MCU_CORE_TYPE == MCU_CORE_8278)))
	if(src & FLD_IRQ_GPIO_RISC2_EN){
		gpio_risc2_user_handle();
		reg_irq_src = FLD_IRQ_GPIO_RISC2_EN;
	}
	#endif
}
#endif

_attribute_ram_code_ void irq_handler(void)
{
	#if ACTIVE_SCAN_ENABLE
	rp_active_scan_req_proc();
	#endif
	#if DUAL_MESH_ZB_BL_EN
	if(rf_mode == RF_MODE_ZIGBEE){
		irq_zigbee_sdk_handler();
	}else
	#endif
	{
		irq_blt_sdk_handler ();  //ble irq proc
	}

#if IRQ_TIMER1_ENABLE
	irq_timer_handle();
#endif

}

/**
 * @brief		BLE SDK RF interrupt handler.
 * @param[in]	none
 * @return      none
 */
_attribute_ram_code_
void rf_irq_handler(void)
{

	DBG_CHN10_HIGH;

	irq_handler();
	DBG_CHN10_LOW;

}

_attribute_ram_code_
void stimer_irq_handler(void)
{
	DBG_CHN9_HIGH;

	irq_handler();

	DBG_CHN9_LOW;
}

_attribute_ram_code_
void uart0_irq_handler(void)
{
#if (HCI_ACCESS==HCI_USE_UART)
	irq_uart_handle();
#endif
}

FLASH_ADDRESS_DEFINE;
#if(MCU_CORE_TYPE == MCU_CORE_8269)
int main (void) {
	FLASH_ADDRESS_CONFIG;
	cpu_wakeup_init();

	clock_init();
	set_tick_per_us(CLOCK_SYS_CLOCK_HZ/1000000);

	gpio_init();

	rf_drv_init(CRYSTAL_TYPE);

	user_init ();

    irq_enable();

	while (1) {
#if (MODULE_WATCHDOG_ENABLE)
		wd_clear(); //clear watch dog
#endif
		main_loop ();
	}
}
#elif((MCU_CORE_TYPE == MCU_CORE_8258) || (MCU_CORE_TYPE == MCU_CORE_8278)||(MCU_CORE_TYPE == MCU_CORE_9518))
_attribute_ram_code_ int main (void)    //must run in ramcode
{
	FLASH_ADDRESS_CONFIG;
#if (PINGPONG_OTA_DISABLE && (0 == FW_START_BY_BOOTLOADER_EN))
    ota_fw_check_over_write();  // must at first for main_
#endif

#if SLEEP_FUNCTION_DISABLE
    blc_pm_select_none();
#else
	blc_pm_select_internal_32k_crystal();
#endif
#if(MCU_CORE_TYPE == MCU_CORE_8258)
	cpu_wakeup_init();
#elif(MCU_CORE_TYPE == MCU_CORE_8278)
	cpu_wakeup_init(LDO_MODE,EXTERNAL_XTAL_24M);
#elif(MCU_CORE_TYPE == MCU_CORE_9518)
	sys_init(DCDC_1P4_LDO_1P8,VBAT_MAX_VALUE_GREATER_THAN_3V6); // need to confirm if want to use DCDC.
#endif

	/* detect if MCU is wake_up from deep retention mode */
	int deepRetWakeUp = pm_is_MCU_deepRetentionWakeup();  //MCU deep retention wakeUp

#if (MCU_CORE_TYPE == MCU_CORE_9518)
	clock_init_B91();
	#if (MODULE_WATCHDOG_ENABLE)
	wd_set_interval_ms(WATCHDOG_INIT_TIMEOUT);
	wd_start();
	#endif
	rf_drv_ble_init();
	gpio_init(!deepRetWakeUp);
	if(!deepRetWakeUp){//read flash size

		//blc_readFlashSize_autoConfigCustomFlashSector(); called in global init.

		#if (FLASH_FIRMWARE_CHECK_ENABLE)
			blt_firmware_completeness_check();
		#endif

		#if FIRMWARES_SIGNATURE_ENABLE
			blt_firmware_signature_check();
		#endif
	}

	/* load customized freq_offset cap value. */
	blc_app_loadCustomizedParameters();
#else
	rf_drv_init(RF_MODE_BLE_1M);
	gpio_init( !deepRetWakeUp );  //analog resistance will keep available in deepSleep mode, so no need initialize again
    clock_init(SYS_CLK_CRYSTAL);
#endif


#if	(PM_DEEPSLEEP_RETENTION_ENABLE)
	if( deepRetWakeUp ){ // MCU wake_up from deepSleep retention mode
		user_init_deepRetn ();
	}
	else // MCU power_on or wake_up from deepSleep mode
#endif
	{
		user_init();

		//timer0_irq_handler();

		uart_init(UART0,12,15,UART_PARITY_NONE,UART_STOP_BIT_ONE); // sysclock = 24M
		uart_set_pin(UART0_TX_PD2,UART0_RX_PD3);

		PWM_Confing();
		SPI_Config();
		Pin_Switch_Config();

		lv_init();
		lv_port_disp_init();

		ui_init();

		nowtime = 0;
		checkScene = 0;
		blc_pm_select_external_32k_crystal();
		dim_set=0;

		ONLED1;
		sleep_ms(300);
		wd_clear();
		OFFLED1;
		sleep_ms(300);
		wd_clear();

		ONLED1;
		sleep_ms(300);
		wd_clear();
		OFFLED1;
		sleep_ms(300);
		wd_clear();

		ONLED1;
		sleep_ms(300);
		wd_clear();
		OFFLED1;
		sleep_ms(300);
		wd_clear();

		flash_read_page(ADDR_START,5,buf);
		stateLed1 = buf[0];
		stateLed2 = buf[1];
		gio = buf[2];
		phut = buf[3];
		giay = buf[4];
		gpio_write(LED1,stateLed1); //Green
		gpio_write(LED2,stateLed2);  //red

	}

    irq_enable();
	#if (DEBUG_LOG_SETTING_DEVELOP_MODE_EN || (MESH_USER_DEFINE_MODE == MESH_IRONMAN_MENLO_ENABLE))
	LOG_USER_MSG_INFO(0, 0,"[mesh] Start from SIG Mesh", 0);
	#endif

	void setRotation(u8 gio, u8 phut, u8 giay){
		lv_img_set_angle(ui_gio, gio*60);
		lv_img_set_angle(ui_phut, phut*60);
		lv_img_set_angle(ui_giay, giay*60);
	}

	while (1) {
#if (MODULE_WATCHDOG_ENABLE)
		wd_clear(); //clear watch dog
#endif
		main_loop ();
		lv_timer_handler();

		if(is_provision_success()){
			if(checkProvision == 0){
				ONLED2;
				checkProvision =1;
			}
		}

		if(!checkScene){
			if(pm_get_32k_tick() - nowtime >=32000){
				giay++;
				if(giay == 60){
					phut++;
					giay=0;
					if(phut == 60){
						phut=0;
					}
					if(phut%12 == 0){
						gio++;
					}
					if(gio==60){
						gio=0;
					}
				}
//				if(!checkProvision){
//					gpio_write(LED2,stateLed);
//					stateLed = !stateLed;
//				}
				timeScene = nowtime = pm_get_32k_tick();

				 if(!checkKickout){
					 timeKickout=nowtime;
				 }
			}
			setRotation(gio,phut,giay);
		}else{
			ui_Screen1_screen_init();
			lv_disp_load_scr(ui_Screen1);

			if(pm_get_32k_tick() - timeScene >= 160000){ //5s
				ui_Screen2_screen_init();
				lv_disp_load_scr(ui_Screen2);

				sumSec = (pm_get_32k_tick()-nowtime)/32000;

			if(giay + sumSec <60){
				giay += (sumSec-1);
			}else{
				giay = (giay+sumSec) % 60 -1;
				sumMin = (giay+sumSec) / 60;
				if(phut + sumMin < 60){
					phut += sumMin;
				}else{
					phut = (phut + sumMin)%60;
					sumHour = (phut + sumMin) / 60;
					if(gio + sumHour <24){
						gio += sumHour;
					}else{
						gio = (gio+sumHour)%24;
					}
				}
			}
				checkScene = 0;
			}
		}
		swx = ReadSW();
		if(swx == '5' ){
			checkKickout = 1;
			// press 1 & 2 in 3 sec -> kickout
			if(checkScene == 0 && (pm_get_32k_tick() - timeKickout >= (32000*3))){

				flash_erase_sector(ADDR_START);

				buf[0] = stateLed1;
				buf[1] = stateLed2;
				buf[2] = gio;
				buf[3] = phut;
				buf[4] = giay;
				flash_write_page(ADDR_START,5,buf);

				checkKickout = 0;
				checkProvision = 0;

				kick_out(0);

			}
		}else if(swx == '4'){

			checkScene = 1;



		}else if(swx == '3'){
			if(!gpio_read(GPIO_PB5)){
				stateLed1 = 0;
			}else{
				stateLed1 = 1;
			}

			if(!gpio_read(GPIO_PB7)){
				stateLed2 = 0;
			}else{
				stateLed2 = 1;
			}
			uart_send_byte(UART0,'G');
			uart_send_byte(UART0,stateLed1); // led1
			uart_send_byte(UART0,'R');
			uart_send_byte(UART0,stateLed2); //led2
//			ui_Screen2_screen_init();
//			lv_disp_load_scr(ui_Screen2);

		}else if(swx == SW_NOT_PRESS){
			checkKickout = 0;
		}

	}
	return 0;
}
#endif
