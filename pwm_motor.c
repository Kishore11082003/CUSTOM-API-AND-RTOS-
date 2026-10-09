/*
 * pwm_motor.c
 *
 *  Created on: Sep 17, 2026
 *      Author: kisho
 */

#include "DEVICE_DRIVER/pwm_motor.h"

volatile uint16_t MOTOR_FRE =0;

void MOTOR_INITAL(TIM_TypeDef * port){
	TIM2->CR1   = 0x80;   //ENABLE THE AUTO RELOAD MODE
	TIM2->CCMR1 = 0x50;   //ENAMBE THE CHANNEL 1 AS OUTPUT
	TIM2->PSC   = 39;     //PRESCALAR
	TIM2->ARR   = CLK_SPEED_TESTING/(MOTOR_PRESCALAR * MOTOR_FRE)-1;     //MAXIMUM COUNT LIMIT
	TIM2->CCR1  = 0;      //DUTY CYCLE
	TIM2->CCER = 0x01;    //ENABLE OUTPUT THROUGH THE CHANNEL 1
	TIM2->EGR   = 0x01;   //UPDATE EVENT
	TIM2->CR1  |= 0x01;   //TURN ON THE TIMER
}

void MOTOR_FREQ(uint16_t FREQ){
	MOTOR_FRE = FREQ;
}

void MOTOR_DUTYCYCLE(uint8_t DUTY){
	volatile uint32_t arr =TIM2->ARR;
	TIM2->CCR1=(arr+1) * DUTY/ 100;
}
