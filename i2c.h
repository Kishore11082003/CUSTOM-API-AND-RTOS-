/*
 * i2c.h
 *
 *  Created on: Sep 23, 2026
 *      Author: kisho
 */

#ifndef DEVICE_DRIVER_I2C_H_
#define DEVICE_DRIVER_I2C_H_

#include <stdint.h>
#include "DEVICE_HEADERS/stm32l432xx.h"

void I2C_INIT(void);

void I2C_WRITE(uint8_t add,uint8_t cmt,uint8_t data);

void I2C_CMT(uint8_t cmt);

void I2C_DATA(uint8_t data);
#endif /* DEVICE_DRIVER_I2C_H_ */
