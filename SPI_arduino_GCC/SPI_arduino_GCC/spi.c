/*
 * spi.c
 *
 * Created: 14.04.2024 14:58:27
 *  Author: indie
 */ 

#include "spi.h"

//polling function
char SPI_SlaveTransceiver(char spi)
{
	SPDR = spi;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}