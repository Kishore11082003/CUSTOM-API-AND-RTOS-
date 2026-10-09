/*
 * pwm.h
 *
 *  Created on: Sep 15, 2026
 *      Author: kisho
 */
#include <stdint.h>
#include "DEVICE_HEADERS/stm32l432xx.h"
void PWM_INITAL(TIM_TypeDef * port);

void PWM_BEGIN();

void PWM_END();

