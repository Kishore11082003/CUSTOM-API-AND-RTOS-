/*
 * spi.c
 *
 *  Created on: Sep 21, 2026
 *      Author: kisho
 */

#include "DEVICE_DRIVER/spi.h"

void SPI_INIT(){

	SPI1->CR1 &= ~SPI_CR1_SPE;
	SPI1->CR1 = SPI_CR1_MSTR | SPI_CR1_CPOL | SPI_CR1_SSM | SPI_CR1_SSI |SPI_CR1_CPHA | SPI_CR1_BR_0 | SPI_CR1_BR_2;
	SPI1->CR2 = SPI_CR2_FRXTH;
}

void SPI_ENABLE(){
	SPI1->CR1 |= SPI_CR1_SPE;
}

uint8_t SPI_TRANSMIT(uint8_t data){
	//transmitter part
	while(!(SPI1->SR & SPI_SR_TXE));
	*((volatile uint8_t *)&SPI1->DR)=data;

	//receiver part
	while(!(SPI1->SR & SPI_SR_RXNE)){

	}
		return *(volatile uint8_t *)&SPI1->DR;
}
