/*
 * LED_LC8823.c
 *
 *  Created on: Jun 18, 2024
 *      Author: DELL
 */

#include"LED_LC8823.h"

void Config_Pin_Led_Lc8823(void){
	gpio_set_func(LED_DI, AS_GPIO);
	gpio_output_en(LED_DI);
	gpio_set_func(LED_CI, AS_GPIO);
	gpio_output_en(LED_CI);
}

void start_frame_led(void){
	gpio_write(LED_DI,0);
	for(int i=0;i<32;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	wd_clear();
}

void end_frame_led(void){
	for(int i=0;i<32;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,1);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
}

void EN_Frame_Color(void){
	for(int i=0;i<8;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,1);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	wd_clear();
}

void DIS_Frame_Color(void){
	for(int i=0;i<8;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,0);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	wd_clear();
}

void Frame_On_Led(void){    // dim 100%
	for(int i=0;i<8;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,1);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	wd_clear();
}
void Frame_Off_Led(void){
	for(int i=0;i<3;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,1);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	for(int i=0;i<5;i++){
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,0);
		sleep_us_clear_dog(250);
		gpio_write(LED_CI,1);
	}
	wd_clear();
}

void Off_Led(void){
	Frame_Off_Led();
	DIS_Frame_Color();
	DIS_Frame_Color();
	DIS_Frame_Color();
}


void On_Led(u8 led_num, color_led_rgb color){
	start_frame_led();
	for(u8 i =1; i<led_num;i++){
		Off_Led();
	}
	Frame_On_Led();
	if(color == BLUE_LC8823){
		EN_Frame_Color();
		DIS_Frame_Color();
		DIS_Frame_Color();
	}else if(color == GREEN_LC8823){
		DIS_Frame_Color();
		EN_Frame_Color();
		DIS_Frame_Color();
	}else if(color == RED_LC8823){
		DIS_Frame_Color();
		DIS_Frame_Color();
		EN_Frame_Color();
	}
	for(u8 j = led_num+1;j<=20;j++){
		Off_Led();
	}
	end_frame_led();
}

void Off_20_Led(void){
	start_frame_led();
	for(u8 i = 0; i<20;i++){
		Off_Led();
	}
	end_frame_led();
}

void On_20_Led_Blue(void){
	start_frame_led();
	for(u8 i=0; i<20;i++){
		Frame_On_Led();
		EN_Frame_Color();
		DIS_Frame_Color();
		DIS_Frame_Color();
	}
	end_frame_led();
}
void On_20_Led_Green(void){
	start_frame_led();
	for(u8 i=0; i<20;i++){
		Frame_On_Led();
		DIS_Frame_Color();
		EN_Frame_Color();
		DIS_Frame_Color();
	}
	end_frame_led();
}
void On_20_Led_Red(void){
	start_frame_led();
	for(u8 i=0; i<20;i++){
		Frame_On_Led();
		DIS_Frame_Color();
		DIS_Frame_Color();
		EN_Frame_Color();
	}
	end_frame_led();
}

void Blink_20_Led_Red(void){
	On_20_Led_Red();
	Off_20_Led();
}
void Blink_20_Led_Green(void){
	On_20_Led_Green();
	Off_20_Led();
}
void Blink_20_Led_Blue(void){
	On_20_Led_Blue();
	Off_20_Led();
}

