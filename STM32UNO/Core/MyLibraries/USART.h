/*
 * USART.h
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#ifndef MYLIBRARIES_MYUSART_USART_H_
#define MYLIBRARIES_MYUSART_USART_H_

void UsartSendByte(USART_TypeDef* UART_PORT, uint8_t Value);
void UsartSendString(USART_TypeDef* UART_PORT, uint8_t* Value);
void UsartNewLine(USART_TypeDef* UART_PORT);

#endif /* MYLIBRARIES_MYUSART_USART_H_ */
