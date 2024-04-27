/*
 * USART.c
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#include "main.h"
#include "USART.h"

void UsartSendByte(USART_TypeDef* UART_PORT, uint8_t Value){
	while(!LL_USART_IsActiveFlag_TXE(UART_PORT));
	LL_USART_TransmitData8(UART_PORT, (uint8_t)Value);
}

void UsartSendString(USART_TypeDef* UART_PORT, uint8_t* Value){
	while(*Value != 0x00){
		if(*Value == '\n'){
			UsartSendByte(UART_PORT, '\r');
		}
		UsartSendByte(UART_PORT, *Value);
		Value++;
	}
}

void UsartNewLine(USART_TypeDef* UART_PORT){
	UsartSendByte(USART2, '\n');
	UsartSendByte(USART2, '\r');
}
