/*
 * clock.c
 *
 *  Created on: Oct 3, 2026
 *      Author: kisho
 */


#include "DEVICE_DRIVER/clock.h"

// Configure the system clock to 80 MHz using the PLL.
void rcc_pll80mhz_init(void){

	// Enable the internal high-speed oscillator (HSI16).
	RCC->CR |= RCC_CR_HSION;

	// Wait until HSI is ready.
	while (!(RCC->CR & RCC_CR_HSIRDY));

	// Configure Flash memory for 4 wait states.
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |= FLASH_ACR_LATENCY_4WS;

	// Disable the PLL before reconfiguring it.
	RCC->CR &= ~RCC_CR_PLLON;

	// Wait until the PLL is fully disabled.
	while (RCC->CR & RCC_CR_PLLRDY);

	// Configure the PLL.
	// Source = HSI16
	// M = 1
	// N = 10
	// R = 2
	// PLL output enabled
	RCC->PLLCFGR =
		RCC_PLLCFGR_PLLSRC_HSI
	|	(0 << RCC_PLLCFGR_PLLM_Pos)
	|	(10 << RCC_PLLCFGR_PLLN_Pos)
	|	(0 << RCC_PLLCFGR_PLLR_Pos)
	|	RCC_PLLCFGR_PLLREN;

	// Enable the PLL.
	RCC->CR |= RCC_CR_PLLON;

	// Wait until the PLL is locked and ready.
	while (!(RCC->CR & RCC_CR_PLLRDY));

	// Select the PLL as the system clock.
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	// Wait until the PLL is being used as the system clock.
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
