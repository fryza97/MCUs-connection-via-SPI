/*
 * init.h
 *
 * Created: 14.04.2024 14:59:10
 *  Author: indie
 */ 

#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef INIT_H_
#define INIT_H_

void init_atmega(unsigned int ubrr);

#endif /* INIT_H_ */