/*
 * clock.h
 *
 *  Created on: Oct 3, 2026
 *      Author: kisho
 */

#ifndef DEVICE_DRIVER_CLOCK_H_
#define DEVICE_DRIVER_CLOCK_H_

#include <stdint.h>
#include "device_headers/stm32l432xx.h"

// Configures the system clock to 80 MHz using the PLL.
void rcc_pll80mhz_init(void);


#endif /* DEVICE_DRIVER_CLOCK_H_ */
