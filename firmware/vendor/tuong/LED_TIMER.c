/*
 * LED_TIMER.c
 *
 *  Created on: Jul 10, 2024
 *      Author: DELL
 */

#include"LED_TIMER.h"

int cnt_led_tick;
int last_tick;

u8 flag_bit;
u8 cnt;

frame_led8823 FRAME_LED = START_FRAME;
u8 check_chose = 0;

void start_frame(void){
	if(last_tick != cnt_led_tick && flag_bit == 0){
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,0);
		flag_bit = 1;
		cnt++;
	}else if(last_tick != cnt_led_tick && flag_bit == 1){
		gpio_write(LED_CI,0);
		flag_bit = 0;
	}
}


void on_led_blue_frame(void){
	if(last_tick != cnt_led_tick && flag_bit == 0){
		gpio_write(LED_CI,0);
		cnt++;
		if(cnt >= 1 && cnt <=16){
			gpio_write(LED_DI,1);
		}else{
			gpio_write(LED_DI,0);
		}
		flag_bit = 1;

	}else if(last_tick != cnt_led_tick && flag_bit == 1){
		gpio_write(LED_CI,0);
		flag_bit = 0;
	}

}

void off_led_frame(void){
	if(last_tick != cnt_led_tick && flag_bit == 0){
		gpio_write(LED_CI,0);
		cnt++;
		if(cnt >= 1 && cnt <=3){
			gpio_write(LED_DI,1);
		}else{
			gpio_write(LED_DI,0);
		}
		flag_bit = 1;

	}else if(last_tick != cnt_led_tick && flag_bit == 1){
		gpio_write(LED_CI,0);
		flag_bit = 0;
	}

}

void end_frame(void){
	if(last_tick != cnt_led_tick && flag_bit == 0){
		gpio_write(LED_CI,0);
		gpio_write(LED_DI,0);
		flag_bit = 1;
		cnt++;
	}else if(last_tick != cnt_led_tick && flag_bit == 1){
		gpio_write(LED_CI,0);
		flag_bit = 0;
	}
	if(cnt == 32){
		cnt = 0;
		FRAME_LED = END_GAME;
		check_chose = 0;
	}
}

void On_Led(u8 led_num, on_led ON_LED){  // on 1 led (9-20)
	if(ON_LED == Frame1){
		u8 check_loop = 0;
		for(u8 i =1; i<led_num;i++){
			if(!check_loop){
				off_led_frame();
				if(cnt == 32){
					cnt = 0;
					check_loop = !check_loop;
				}
			}else{
				off_led_frame();
				if(cnt == 32){
					cnt = 0;
					check_loop = !check_loop;
				}
			}
			if(i==led_num-1) ON_LED = Frame2;
		}
	}else if(ON_LED == Frame2){
		on_led_blue_frame();
		if(cnt == 32){
			ON_LED = Frame3;
			cnt = 0;
		}
	}else if(ON_LED == Frame3){
		u8 check_loop = 0;
		for(u8 i =led_num; i<=20;i++){
			if(!check_loop){
				on_led_blue_frame();
				if(cnt == 32){
					cnt = 0;
					check_loop = !check_loop;
				}
			}else{
				on_led_blue_frame();
				if(cnt == 32){
					cnt = 0;
					check_loop = !check_loop;
				}
			}
			if(i==20){
				ON_LED = End_Frame;
			}
		}
	}
}


void func_led_r(void){
	if(!check_chose){
		FRAME_LED = START_FRAME;
		check_chose = 1;
	}
	if(FRAME_LED == START_FRAME){

	}else if(FRAME_LED == LED_FRAME){
		for(u8 i = 9;i<=20; i ++){
			On_Led(i, Frame1);
			if(i==20) FRAME_LED = END_FRAME;
		}
	}else if(FRAME_LED == END_FRAME){
		end_frame();
	}
}
