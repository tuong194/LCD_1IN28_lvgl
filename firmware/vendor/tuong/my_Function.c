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


u8 buf[10];

char swx;

u8 checkSuccess;

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
	//checkProvision= 1;
	checkPro = 1;
	checkSuccess = 1;
	hsvH = 0;
}

void check_OTA(void){
	if(ui_ota_is_working == 1 && ota_condition_enable()==1 && checkOTA == 1){
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
		if(pm_get_32k_tick() - timeOut >= 32000*TIMEOUT_SECURE){
			if(para[0] == 0 && para[1] == 0 && para[2] == 0 && para[3] == 0 && para[4] == 0 && para[5] == 0 && para[6] == 0 && para[7] == 0){
				uart_send_byte(UART0, 'N');
				kick_out(0);
			}
		}
		if(checkProvision == 2){
			if(pm_get_32k_tick() - timeOut >= 32000*5){
				uart_send_byte(UART0,'0');
				kick_out(0);
			}
		}
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
//		uart_send_byte(UART0, 'x');
//		uart_send_byte(UART0, ui_ota_is_working);
//		uart_send_byte(UART0, 'y');
//		uart_send_byte(UART0, ota_condition_enable());

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
		 uart_send_byte(UART0, 'z');
		 uart_send_byte(UART0, checkProvision);
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
			ui_Screen1_screen_init();
			lv_disp_load_scr(ui_Screen1);
			lv_label_set_text(ui_Label1, "wait for 5s");
			if(pm_get_32k_tick() - timeScene >= 160000){ //5s
				ui_Screen2_screen_init();
				lv_disp_load_scr(ui_Screen2);

				checkScene = 0;
			}
		}else if(checkScene == 2){
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
		else if(checkScene == 3){
			if(!ota_condition_enable()){
				// timeOTA = pm_get_32k_tick();
				lv_label_set_text(ui_Label1, "ota fail");
				ui_Screen2_screen_init();
				lv_disp_load_scr(ui_Screen2);
				checkOTA = 1;
				checkScene=0;

			}
		}
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
		checkScene = 1;
	}else if(swx == '3'){
		checkScene = 2;
		ui_Screen3_screen_init();
		lv_disp_load_scr(ui_Screen3);
	}
	else if(swx == '2'){
		ui_Screen2_screen_init();
		lv_disp_load_scr(ui_Screen2);
		lv_obj_set_style_bg_color(ui_Screen2, color, LV_PART_MAIN | LV_STATE_DEFAULT);
		checkScene = 0;
	}
	else if(swx == SW_NOT_PRESS){
		checkKickout = 0;
	}
}

