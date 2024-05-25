/*
 * my_Function.c
 *
 *  Created on: May 23, 2024
 *      Author: DELL
 */


#include "my_Function.h"
#include "switch.h"


extern u8 ui_ota_is_working;
extern u8 stateLed1, stateLed2;
extern u8 gio,phut,giay;
extern u32 timeOut;
extern uint8_t para[8];

extern u8 get_ota_check_type();
extern int access_cmd_set_light_hsl(u16 adr, u8 rsp_max, u16 lightness, u16 hue, u16 sat, int ack, transition_par_t *trs_par);

u8 buf[10];
u8 mode=0;

char swx;
u8 checkSuccess;
unsigned char buff[8];

void BlinkLed1(u8 number){
	for(u8 i=0;i<number; i++){
		ONLED1;
		sleep_ms(300);
		wd_clear();
		OFFLED1;
		sleep_ms(300);
		wd_clear();
	}
}
void getValue(void){
	flash_read_page(ADDR_START,6,buf);
	stateLed1 = buf[0];
	stateLed2 = buf[1];
	gio = buf[2];
	phut = buf[3];
	giay = buf[4];
	//checkProvision= buf[5];
	gpio_write(LED1,stateLed1); //Green
	gpio_write(LED2,stateLed2);  //red
}

void setValue(void){
	nowtime = 0;
	checkScene = 0;
	checkKickout = 0;
	checkOTA = 1;
	countBlinkLed2 = 0;
	checkPro = 1;
	checkSuccess = 1;
	hsvH = 0;

	dim_set = 0;
	ctt_set = 0;
}

void check_OTA(void){
	if(get_ota_check_type() == OTA_PACKET_INVALID && checkOTA == 1){
		checkScene = 3;

		ui_Screen1_screen_init();
		lv_disp_load_scr(ui_Screen1);

		lv_label_set_text(ui_Label1, "ota is working");
		checkOTA = 0;
	}
}

/*
 * 0: Unprov
 * 1: Provision success
 * 2: Provision unsuccess  -> kick out  5s later
 *    Proved, not messeage -> kick out 30s later
 */
void check_provision(void){
	if(get_provision_state() == STATE_DEV_UNPROV ){
		checkProvision = 0;
		for(u8 i=0; i<8; i++){
			para[i] = 0;
		}
		checkPro = 1;
		if(pm_get_32k_tick() - timeProvision >= 16000){
			stateLed2 = !stateLed2;
			gpio_write(LED2,stateLed2);
			timeProvision = pm_get_32k_tick();
		}
	}else if(get_provision_state() == STATE_DEV_PROVED){
		if(checkPro == 1){
			if(pm_get_32k_tick() - timeProvision >= 6400){
				stateLed2 = !stateLed2;
				gpio_write(LED2,stateLed2);
				countBlinkLed2++;

				timeProvision = pm_get_32k_tick();
			}
			if(countBlinkLed2 == 6){ // done!
				countBlinkLed2 = 0;
				checkPro =0;
			}
			timeOut = pm_get_32k_tick();
		}
//		if(pm_get_32k_tick() - timeOut >= 32000*TIMEOUT_SECURE){
//			if(para[0] == 0 && para[1] == 0 && para[2] == 0 && para[3] == 0 && para[4] == 0 && para[5] == 0 && para[6] == 0 && para[7] == 0){
//				uart_send_byte(UART0, 'N');
//				kick_out(0);
//			}
//		}
//		if(checkProvision == 2){
//			if(pm_get_32k_tick() - timeOut >= 32000*5){
//				uart_send_byte(UART0,'0');
//				kick_out(0);
//			}
//		}
	}
	if(checkProvision == 1){
		if(checkSuccess == 1){
			uart_send_byte(UART0,'1');
			if(pm_get_32k_tick() - timeProvision >= 6400){
					stateLed2 = !stateLed2;
					gpio_write(LED2,stateLed2);
					countBlinkLed2++;

					timeProvision = pm_get_32k_tick();
				}
				if(countBlinkLed2 == 6){ // done!
					countBlinkLed2 = 0;
					checkSuccess =0;
				}
		}
	}
}

void displayClock(void){
	if(pm_get_32k_tick() - nowtime >=32000){
		uart_send_byte(UART0, 'x');
		uart_send_byte(UART0, get_ota_check_type());
		uart_send_byte(UART0, 'z');
		uart_send_byte(UART0, checkProvision);

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
		 nowtime = pm_get_32k_tick();

		 if(!checkKickout){
			 timeKickout=nowtime;
		 }
	}
}

void setRotation(u8 gio, u8 phut, u8 giay){
	lv_img_set_angle(ui_gio, gio*60);
	lv_img_set_angle(ui_phut, phut*60);
	lv_img_set_angle(ui_giay, giay*60);
}

void check_Scene(void){
		if(checkScene == 0){
			timeScene = pm_get_32k_tick();
			setRotation(gio,phut,giay);
		}else if(checkScene == 1){
			if(mode == MODE_RGB_SET){
				if(pm_get_32k_tick() - timeScene >=8000){
					if(hsvH == 360){
						hsvH = 0;
					}
					lv_img_set_angle(ui_Image3, hsvH*10);
					if(hsvH<=180){
						color = lv_color_hsv_to_rgb(180-hsvH,100,100); //H,S,V
					}else{
						color = lv_color_hsv_to_rgb(540-hsvH,100,100);
					}

					lv_obj_set_style_bg_color(ui_Panel2, color, LV_PART_MAIN | LV_STATE_DEFAULT);
					hsvH++;
					timeScene = pm_get_32k_tick();

				}
			}
		}
		else if(checkScene == 3){
			if(get_ota_check_type() == OTA_SUCCESS){
				checkOTA = 1;
				checkScene=0;
				ui_Screen2_screen_init();
				lv_disp_load_scr(ui_Screen2);
			}
		}
}

void Set_RGB(void){
	transition_par_t trs_par = {0};
	trs_par.transit_t = 10;
	u16 hue;
	if(hsvH<=180){
		hue = (180-hsvH)*65535/360;
	}else{
		hue = (540-hsvH)*65535/360;
	}
	u16 lightness = 0x7fff; // 50%
	u16 sat = 0xffff;
	access_cmd_set_light_hsl(LED_ADDR,2,lightness,hue,sat,0,&trs_par);
}

void RD_Model_OPCODE_SET_DIMCCT(void)
{
	Struct_OPCODE_SET_DIMCCT_t *mess_buff;

	//mess_buff = (Struct_OPCODE_SET_DIMCCT_t*) vrts_GWIF_IncomeMessage;

	u8 dim_set	= mess_buff->Dim_Stt;
	u8 cct_set = mess_buff->Cct_Stt;

	//rdPrintf("OPCODE SET dim: %d% cct:%d %", dim_set, cct_set);
	access_cmd_set_light_ctl_100(LED_ADDR, 2 , dim_set, cct_set, 0);
	//access_cmd_set_light_ctl(0xffff, 2 , lum2_lightness(dim_set), cct_set, 0, &TTS_CTRL_DF);
}

void RD_Send_Relay_Stt(uint8_t Relay_ID, uint8_t Relay_Stt)
{
	uint8_t Mess_Buff[8] = {0};
	uint16_t Element_Add = 0x0000;

	Mess_Buff[0]		= Relay_Stt;
	Element_Add 		= ele_adr_primary + (Relay_ID-1);

	mesh_tx_cmd2normal(G_ONOFF_STATUS, Mess_Buff, 1, Element_Add, GATEWAY_ADDRESS, 2);

}


void read_sw(void){
	swx = ReadSW();
	if(swx == '5' ){
		checkKickout = 1;
		// press 1 & 2 in 3 sec -> kickout
		if(checkScene == 0 && (pm_get_32k_tick() - timeKickout >= (32000*3))){
			checkKickout = 0;
			checkProvision = 1;

			kick_out(0);
		}
	}else if(swx == '4'){
		if(checkScene == 1){
			if(mode == MODE_DIM_SET){
				dim_set--;
				if(dim_set >100) dim_set = 0;

				lv_arc_set_value(ui_Arc1, dim_set);
				sprintf(buff,"%d",dim_set);
				lv_label_set_text(ui_Label1, buff);
				access_set_lum(LED_ADDR,2,dim_set,0);

			}else if(mode == MODE_CTT_SET){
				ctt_set--;
				if(ctt_set > 100) ctt_set = 0;

				lv_arc_set_value(ui_Arc1, ctt_set);
				sprintf(buff,"%d",ctt_set);
				lv_label_set_text(ui_Label1, buff);
				access_cmd_set_light_ctl_temp_100(LED_ADDR,2,ctt_set,0);
			}
		}
	}else if(swx == '3'){
		if(checkScene == 1){
			if(mode == MODE_DIM_SET){
				dim_set++;
				if(dim_set > 100) dim_set = 100;

				lv_arc_set_value(ui_Arc1, dim_set);
				sprintf(buff,"%d",dim_set);
				lv_label_set_text(ui_Label1, buff);
				access_set_lum(LED_ADDR,2,dim_set,0);

			}else if(mode == MODE_CTT_SET){
				ctt_set++;
				if(ctt_set > 100) ctt_set = 100;

				lv_arc_set_value(ui_Arc1, ctt_set);
				sprintf(buff,"%d",ctt_set);
				lv_label_set_text(ui_Label1, buff);
				access_cmd_set_light_ctl_temp_100(LED_ADDR,2,ctt_set,0);
			}
		}

	}
	else if(swx == '2'){
		checkScene = 0;
		ui_Screen2_screen_init();
		lv_disp_load_scr(ui_Screen2);
		lv_obj_set_style_bg_color(ui_Screen2, color, LV_PART_MAIN | LV_STATE_DEFAULT);
		Set_RGB();
		checkScene = 0;
	}else if(swx == '1'){
		checkScene = 1;
		mode++;
		mode %= 3;
		if(mode == MODE_DIM_SET){
			ui_Screen1_screen_init();
			lv_disp_load_scr(ui_Screen1);
			lv_label_set_text(ui_Label1, "dim");
			lv_arc_set_value(ui_Arc1, dim_set);

		}if(mode == MODE_CTT_SET){
			ui_Screen1_screen_init();
			lv_disp_load_scr(ui_Screen1);
			lv_label_set_text(ui_Label1, "ctt");
			lv_arc_set_value(ui_Arc1, ctt_set);

		}if(mode == MODE_RGB_SET){
			ui_Screen3_screen_init();
			lv_disp_load_scr(ui_Screen3);
		}
	}
	else if(swx == SW_NOT_PRESS){
		checkKickout = 0;
	}
}


