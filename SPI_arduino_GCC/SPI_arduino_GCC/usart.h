/*
 * usart.h
 *
 * Created: 14.04.2024 14:57:55
 *  Author: indie
 */ 

#include "init.h"

#ifndef USART_H_
#define USART_H_

void USART_Transmit(unsigned char data);
void USART_Transmit2(unsigned char *data);
void USART_NewLine();
unsigned char USART_Receive( void );

#endif /* USART_H_ */