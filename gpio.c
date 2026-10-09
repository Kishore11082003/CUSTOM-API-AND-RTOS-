/*
 * gpio.c
 *
 *  Created on: Sep 10, 2026
 *      Author: kisho
 */

#include "DEVICE_DRIVER/gpio.h"

void GPIO_Init(GPIO_TypeDef * port,
		GPIO_PIN pin,
		GPIO_MODE mode,
		GPIO_OTYPER output_type,
		GPIO_SPEED output_speed,
		GPIO_PU pullupdown){
	port->MODER &= ~(0X3UL << (pin*2));
	port->MODER |= ((uint32_t)mode<<(pin*2U));

	port->OTYPER &= ~(0x1UL << pin);
	port->OTYPER |=(uint32_t)(output_type << pin);

	port->OSPEEDR &= ~(0X3UL << (pin*2));
	port->OSPEEDR |= ((uint32_t)output_speed<<(pin*2U));

	port->PUPDR&= ~(0X3UL << (pin*2));
	port->PUPDR |= ((uint32_t)pullupdown<<(pin*2U));
}

void GPIO_WRITE(GPIO_TypeDef * port,
        GPIO_PIN pin,
		 GPIO_VALUE value){
	if(value==1U){
		port->BSRR |=(0x1UL<<pin);
	}
	if(value==0U){
		port->BSRR |=(0x0UL<<(pin+16));
	}

}


GPIO_VALUE GPIO_READ(GPIO_TypeDef * port,
        GPIO_PIN pin){
	uint32_t n=0U;
	n=port->IDR & (1UL<<pin);
	if(n!=0){
		return GPIO_HIGH;
	}
	else{
		return GPIO_LOW;
	}
}

void GPIO_ALTER(GPIO_TypeDef * port,
		         GPIO_PIN pin,
				 GPIO_AF afvalue){
if(pin<=7){
	//low pins
	port->AFR[0]&=~(uint32_t)(0xFU<<(pin*4));
	port->AFR[0]|=(uint32_t)(afvalue<<(pin*4));
}
else{
	//high pins
	port->AFR[1]&=~(uint32_t)(0XFU<<((pin-8)*4));
	port->AFR[1]|=(uint32_t)(afvalue<<((pin-8)*4));
}
}








