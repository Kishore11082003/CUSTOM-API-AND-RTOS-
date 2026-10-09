/*
 * pwm.c
 *
 *  Created on: Sep 15, 2026
 *      Author: kisho
 */

#include "DEVICE_DRIVER/pwm.h"

void PWM_INITAL(TIM_TypeDef * port){
	TIM2->CR1   = 0x80;   //ENABLE THE AUTO RELOAD MODE
	TIM2->CCMR1 = 0x50;   //ENAMBE THE CHANNEL 1 AS OUTPUT
	TIM2->PSC   = 39;     //PRESCALAR
	TIM2->ARR   = 20;     //MAXIMUM COUNT LIMIT
	TIM2->CCR1  = 10;     //DUTY CYCLE
	TIM2->CCER = 0x01;    //ENABLE OUTPUT THROUGH THE CHANNEL 1
	TIM2->EGR   = 0x01;   //UPDATE EVENT
}

void PWM_BEGIN(){
	TIM2->CR1  |= 0x01;    //ON TIMER
}

void PWM_END(){
	TIM2->CR1  |= 0x00;    //OFF TIMER
}
