/*
 * usart.c
 *
 * Created: 14.04.2024 14:57:44
 *  Author: indie
 */ 

#include "usart.h"

void USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void USART_Transmit2(unsigned char *data){
	while(*data != 0x00){
		if(*data == '\n'){
			USART_Transmit('\r');
		}
		USART_Transmit(*data);
		data++;
	}
}

void USART_NewLine(){
	USART_Transmit('\n'); 
	USART_Transmit('\r');
}

//polling functions 
unsigned char USART_Receive( void )
{
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}