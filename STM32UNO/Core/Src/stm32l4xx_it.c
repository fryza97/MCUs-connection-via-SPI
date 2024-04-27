#include "main.h"
#include "stm32l4xx_it.h"
#include "../MyLibraries/SPI.h"
#include "../MyLibraries/USART.h"

uint8_t buffer;

const uint8_t usart_string[] = "(STM32) Value received by USART: ";
const uint8_t spi_string[] = "(STM32) Value received by SPI: ";


void SPI2_IRQHandler(void){
	if(LL_SPI_IsActiveFlag_TXE(SPI2) && LL_SPI_IsEnabledIT_TXE(SPI2))
	{
		SPIInterruptSend(SPI2, buffer);
		LL_SPI_EnableIT_RXNE(SPI2);
		LL_SPI_DisableIT_TXE(SPI2);
	}

	if(LL_SPI_IsActiveFlag_RXNE(SPI2) && LL_SPI_IsEnabledIT_RXNE(SPI2)){
		buffer = LL_SPI_ReceiveData8(SPI2);

		SPIInterrruptDisable(SPI2);

		UsartSendString(USART2, (uint8_t*)spi_string);
		UsartSendByte(USART2, buffer); UsartNewLine(USART2); UsartNewLine(USART2);

		LL_USART_EnableIT_RXNE(USART2);
	}
}

void USART2_IRQHandler(void){
	if(LL_USART_IsEnabledIT_TXE(USART2) && LL_USART_IsActiveFlag_TXE(USART2)){
		UsartSendString(USART2, (uint8_t*)usart_string);
		UsartSendByte(USART2, buffer); UsartNewLine(USART2);

		LL_USART_DisableIT_TXE(USART2);

		SPIInterrruptEnable(SPI2);
	}

	if(LL_USART_IsEnabledIT_RXNE(USART2) && LL_USART_IsActiveFlag_RXNE(USART2)){
		buffer = LL_USART_ReceiveData8(USART2);

		LL_USART_DisableIT_RXNE(USART2);
		LL_USART_EnableIT_TXE(USART2);
	}
}
