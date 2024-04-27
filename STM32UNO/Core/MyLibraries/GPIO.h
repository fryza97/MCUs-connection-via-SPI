/*
 * GPIO.h
 *
 *  Created on: Apr 8, 2024
 *      Author: indie
 */

#ifndef MYLIBRARIES_MYGPIO_GPIO_H_
#define MYLIBRARIES_MYGPIO_GPIO_H_

#include <stdbool.h>

void GPIO_set(bool state, GPIO_TypeDef * GPIO_Port, uint32_t PIN);
void GPIO_change(GPIO_TypeDef * GPIO_Port, uint32_t PIN);

#endif /* MYLIBRARIES_MYGPIO_GPIO_H_ */
