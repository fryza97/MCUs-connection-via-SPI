/*
 * main.h
 *
 * Created: 14.04.2024 15:04:31
 *  Author: indie
 */ 

#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "init.h"
#include "spi.h"
#include "usart.h"

#ifndef MAIN_H_
#define MAIN_H_

#endif /* MAIN_H_ */