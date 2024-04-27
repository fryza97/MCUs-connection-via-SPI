/*
 * SPI_arduino_GCC.c
 *
 * Created: 05.08.2023 12:19:51
 * Author : indie
 */ 

#include "init.h"
#include "usart.h"
#include "spi.h"

//const variables
const char usart_string[] = "(ATMEGA) Value received by USART: ";
const char spi_string[] = "(ATMEGA) Value received by SPI: ";
//global variables


//intterupts
ISR(USART_RX_vect){
	unsigned char a;
	a = UDR0;
	USART_Transmit2((unsigned char*)usart_string);
	USART_Transmit(a); USART_NewLine();
	
	SPDR = a;
}

ISR(SPI_STC_vect){
	unsigned char spi;
	spi = SPDR;
	USART_Transmit2((unsigned char*)spi_string);
	USART_Transmit(spi); USART_NewLine(); USART_NewLine();
}

//main function
int main(void)
{
	init_atmega(MYUBRR);
	
    while (1) {
    }
}