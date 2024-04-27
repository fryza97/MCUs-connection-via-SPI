/*
 * GPIO.c
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#include "main.h"
#include "GPIO.h"

void GPIO_set(bool state, GPIO_TypeDef * GPIO_Port, uint32_t PIN){
	if(state){
		LL_GPIO_SetOutputPin(GPIO_Port, PIN);
	}
	else{
		LL_GPIO_ResetOutputPin(GPIO_Port, PIN);
	}
}

void GPIO_change(GPIO_TypeDef * GPIO_Port, uint32_t PIN){
		LL_GPIO_TogglePin(GPIO_Port, PIN);
}
