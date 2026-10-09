/*
 * gpio.h
 *
 *  Created on: Sep 10, 2026
 *      Author: kisho
 */

#ifndef DEVICE_DRIVER_GPIO_H_
#define DEVICE_DRIVER_GPIO_H_
#include "DEVICE_HEADERS/stm32l432xx.h"

typedef enum{
 GPIO_PIN0 =0U,
 GPIO_PIN1,
 GPIO_PIN2,
 GPIO_PIN3,
 GPIO_PIN4,
 GPIO_PIN5,
 GPIO_PIN6,
 GPIO_PIN7,
 GPIO_PIN8,
 GPIO_PIN9,
 GPIO_PIN10,
 GPIO_PIN11,
 GPIO_PIN12,
 GPIO_PIN13,
 GPIO_PIN14,
 GPIO_PIN15,
}GPIO_PIN;

typedef enum{
 GPIO_MODE_INPUT =0U,
GPIO_MODE_OUTPUT,
GPIO_MODE_ALTERNATE,
GPIO_MODE_ANALOG
}GPIO_MODE;

typedef enum{
 GPIO_SPEED_LOW =0U,
GPIO_SPEED_MEDIUM ,
GPIO_SPEED_HIGH ,
GPIO_SPEED_VERYHIGH
}GPIO_SPEED;

typedef enum{
 GPIO_OTYPER_PUSHPULL =0U,
 GPIO_OTYPER_OPENDRAIN
}GPIO_OTYPER;

typedef enum{
 GPIO_NO_PUSHPULL =0U,
 GPIO_PULLUP,
 GPIO_PULLDOWN,
 GPIO_RESERVED
}GPIO_PU;

typedef enum{
 GPIO_LOW =0U,
GPIO_HIGH  =1U
}GPIO_VALUE;

typedef enum{
 AF0 = 0U,
 AF1,
 AF2,
 AF3,
 AF4,
 AF5,
 AF6,
 AF7,
 AF8,
 AF9,
 AF10,
 AF11,
 AF12,
 AF13,
 AF14,
 AF15
}GPIO_AF;

void GPIO_Init(GPIO_TypeDef * port,
		GPIO_PIN pin,
		GPIO_MODE mode,
		GPIO_OTYPER output_type,
		GPIO_SPEED output_speed,
		GPIO_PU pullupdown);

void GPIO_WRITE(GPIO_TypeDef * port,
		         GPIO_PIN pin,
				 GPIO_VALUE value);

GPIO_VALUE GPIO_READ(GPIO_TypeDef * port,
		         GPIO_PIN pin);

void GPIO_ALTER(GPIO_TypeDef * port,
		         GPIO_PIN pin,
				 GPIO_AF afvalue);

#endif /* DEVICE_DRIVER_GPIO_H_ */
