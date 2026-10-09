/*
 * servo_motor.h
 *
 *  Created on: Sep 19, 2026
 *      Author: kisho
 */
#include <stdint.h>
#ifndef DEVICE_DRIVER_SERVO_MOTOR_H_
#define DEVICE_DRIVER_SERVO_MOTOR_H_

#include "DEVICE_HEADERS/stm32l432xx.h"

#define CLK 4000000U
#define PSC1 4U

void SERVO_INIT(uint32_t PERIOD);

void SERVO_ROTATE(uint32_t PERIOD,uint8_t ANGEL);

#endif /* DEVICE_DRIVER_SERVO_MOTOR_H_ */
