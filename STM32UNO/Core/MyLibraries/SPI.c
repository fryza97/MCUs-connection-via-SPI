/*
 * SPI.c
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#include "main.h"
#include "SPI.h"
#include "GPIO.h"

#define DUMMY_BYTE 0x2F

//polling functions
void SPISendData(SPI_TypeDef *spi, uint8_t *data, uint32_t size){

	uint32_t count = 0;

	LL_SPI_Enable(spi);
	GPIO_set(0, CS1_GPIO_Port, CS1_Pin);

	while(count < size)
	{
		while (!LL_SPI_IsActiveFlag_TXE(spi));
		LL_SPI_TransmitData8(spi, *(data+count));
		count++;
	}

	while (LL_SPI_GetTxFIFOLevel(spi) != LL_SPI_TX_FIFO_EMPTY);
	while (LL_SPI_IsActiveFlag_BSY(spi) != 0);

	LL_SPI_Disable(spi);
	GPIO_set(1, CS1_GPIO_Port, CS1_Pin);

	while (LL_SPI_GetRxFIFOLevel(spi) != LL_SPI_RX_FIFO_EMPTY)
	{
		LL_SPI_ReceiveData8(spi);
	}

	LL_SPI_ClearFlag_OVR(spi);
}

//interrupt functions
void SPIInterruptSend (SPI_TypeDef *spi, uint8_t data){
	LL_SPI_TransmitData8(spi, data);
}

uint8_t SPIInterruptReceive (SPI_TypeDef *spi){
	return LL_SPI_ReceiveData8(spi);
}

void SPIInterrruptEnable (SPI_TypeDef *spi){
	LL_SPI_Enable(spi);
	GPIO_set(0, CS1_GPIO_Port, CS1_Pin);
	LL_SPI_EnableIT_TXE(spi);
}

void SPIInterrruptDisable (SPI_TypeDef *spi){
	LL_SPI_DisableIT_TXE(spi);
	LL_SPI_DisableIT_RXNE(spi);

	while (LL_SPI_GetRxFIFOLevel(spi) != LL_SPI_RX_FIFO_EMPTY);
	while (LL_SPI_IsActiveFlag_BSY(spi) != 0);

	LL_SPI_Disable(spi);

	while (LL_SPI_GetRxFIFOLevel(spi) != LL_SPI_RX_FIFO_EMPTY)
	{
		LL_SPI_ReceiveData8(spi);
	}

	LL_SPI_ClearFlag_OVR(spi);

	GPIO_set(1, CS1_GPIO_Port, CS1_Pin);
}






