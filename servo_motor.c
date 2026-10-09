/*
 * servo_motor.c
 *
 *  Created on: Sep 19, 2026
 *      Author: kisho
 */
#include "DEVICE_DRIVER/servo_motor.h"

volatile uint8_t u=0;


void SERVO_INIT(uint32_t PERIOD){
	TIM2->CR1   = 0x80;   //ENABLE THE AUTO RELOAD MODE
	TIM2->CCMR1 = 0x60;   //ENAMBE THE CHANNEL 1 AS OUTPUT
	TIM2->PSC   = PSC1-1U;   //PRESCALAR
	TIM2->ARR   = CLK * PERIOD / (PSC1 *1000)-1;  //MAXIMUM COUNT LIMIT
	TIM2->CCR1  = 0;      //DUTY CYCLE
	TIM2->CCER = 0x01;    //ENABLE OUTPUT THROUGH THE CHANNEL 1
	TIM2->EGR   = 0x01;   //UPDATE EVENT
	TIM2->CR1  |= 0x01;   //TURN ON THE TIMER
}

void SERVO_ROTATE(uint32_t PERIOD,uint8_t ANGEL){
	uint32_t arr = TIM2->ARR;
	uint32_t pulse_us =  500 + (uint32_t)(ANGEL * 2000)/180;
	TIM2->CCR1 = (pulse_us * (arr + 1)) / (PERIOD * 1000);
}
