/*
 * SPI.h
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#ifndef MYLIBRARIES_MYSPI_SPI_H_
#define MYLIBRARIES_MYSPI_SPI_H_

//polling functions
void SPISendData(SPI_TypeDef *spi, uint8_t *data, uint32_t size);
void SPIReadData(SPI_TypeDef *spi, uint8_t *data, uint32_t size);

//interrupts functions
void SPIInterruptSend (SPI_TypeDef *spi, uint8_t data);
uint8_t SPIInterruptReceive (SPI_TypeDef *spi);

void SPIInterrruptEnable (SPI_TypeDef *spi);
void SPIInterrruptDisable (SPI_TypeDef *spi);

#endif /* MYLIBRARIES_MYSPI_SPI_H_ */
