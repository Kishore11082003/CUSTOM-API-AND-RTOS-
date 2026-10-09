/*
 * pwm_motor.h
 *
 *  Created on: Sep 17, 2026
 *      Author: kisho
 */

#ifndef DEVICE_DRIVER_PWM_MOTOR_H_
#define DEVICE_DRIVER_PWM_MOTOR_H_
#include <stdint.h>
#include "DEVICE_HEADERS/stm32l432xx.h"


#define CLK_SPEED_TESTING 4000000U
#define MOTOR_PRESCALAR 40U

void MOTOR_INITAL(TIM_TypeDef * port);

void MOTOR_FREQ(uint16_t FREQ);

void MOTOR_DUTYCYCLE(uint8_t DUTY);



#endif /* DEVICE_DRIVER_PWM_MOTOR_H_ */
