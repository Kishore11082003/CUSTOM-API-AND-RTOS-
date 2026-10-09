/*
 * spi.h
 *
 *  Created on: Sep 21, 2026
 *      Author: kisho
 */

#ifndef DEVICE_DRIVER_SPI_H_
#define DEVICE_DRIVER_SPI_H_

#include<stdint.h>
#include "DEVICE_HEADERS/stm32l432xx.h"

void SPI_INIT();

void SPI_ENABLE();

uint8_t SPI_TRANSMIT( uint8_t data);

#endif /* DEVICE_DRIVER_SPI_H_ */
