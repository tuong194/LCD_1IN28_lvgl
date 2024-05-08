/*
 * switch.c
 *
 *  Created on: May 7, 2024
 *      Author: DELL
 */

#include "switch.h"

#define SET_ROW1 gpio_write(TL_Key1,1)
#define SET_ROW2 gpio_write(TL_Key2,1)

#define RESET_ROW1 gpio_write(TL_Key1,0)
#define RESET_ROW2 gpio_write(TL_Key2,0)

#define READ_COL1 gpio_read(TL_Key3)
#define READ_COL2 gpio_read(TL_Key4)

void Pin_Switch_Config(void){
	gpio_set_func(LED1, FUNC);
	gpio_output_en(LED1);
	gpio_set_func(LED2, FUNC);
	gpio_output_en(LED2);

	gpio_set_func(TL_Key1, FUNC);
	gpio_output_en(TL_Key1);

	gpio_set_func(TL_Key2, FUNC);
	gpio_output_en(TL_Key2);

	gpio_set_func(TL_Key3, FUNC);
	gpio_input_en(TL_Key3);
	gpio_set_up_down_res(TL_Key3,GPIO_PIN_PULLUP_10K);

	gpio_set_func(TL_Key4, FUNC);
	gpio_input_en(TL_Key4);
	gpio_set_up_down_res(TL_Key4,GPIO_PIN_PULLUP_10K);
}

char sw[2][2] = {
		{'1','2'},
		{'3','4'},
};

static char read_col(u8 row){
	if(!READ_COL1){
		return sw[row-1][0];   // hang row cot 0
	}
	if(!READ_COL2){
		return sw[row-1][1];
	}
	return SW_NOT_PRESS;
}

u8 count = 0;

char ReadSW(void){
	char check;

	// check row 1
	SET_ROW2;
	RESET_ROW1;
	check = read_col(1);
	if(check != SW_NOT_PRESS && count == 250){
		count =0;
		stateSW = 1;
		return check;
	}

	//check row 2
	SET_ROW1;
	RESET_ROW2;
	check = read_col(2);
	if(check != SW_NOT_PRESS && count == 250){
		count = 0;
		stateSW = 1;
		return check;
	}
	if(stateSW == 0){
		count++;
	}
	stateSW = 0;

	return SW_NOT_PRESS;
}

