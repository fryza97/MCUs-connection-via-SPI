/*
 * init.c
 *
 * Created: 14.04.2024 14:59:02
 *  Author: indie
 */ 

#include "init.h"

void init_atmega(unsigned int ubrr){
	//ports
	DDRB = 0b00010000; // 0 - input, 1 - output
	DDRC = 0b00000000; // DDR 7 - 0
	DDRD = 0b10000000; // PB4 (MISO) output, PD7 output (LED)
	
	PORTB = 0xFF;
	PORTC = 0xFF;
	PORTD = 0x7F; // PORTS PULL_UP
	
	//usart
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0); //recive interrupt, recive on, transmit on
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //two stop bits, eight data bits
	
	//SPI
	SPCR = (1<<SPIE)|(1<<SPE); //spi interrupt enable
	//SPCR = (1<<SPE); //spi interrupt disable
	
	//global_interrupts
	sei();
}