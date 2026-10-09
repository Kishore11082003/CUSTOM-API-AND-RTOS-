/*
 * i2c.c
 *
 *  Created on: Sep 23, 2026
 *      Author: kisho
 */

#include "DEVICE_DRIVER/i2c.h"

#define SSD1306_ADDR  0x3C
#define SSD1306_CMT   0x00
#define SSD1306_DATA  0x40

void I2C_INIT(){

	I2C1->CR1 &= ~I2C_CR1_PE; // DISABLE I2C PERIPERAL

    /* 100kHz timing for 4MHz I2C clock */
    I2C1->TIMINGR = 0x0010061A;

    //ENABLE THE I2C PERIPERAL

    I2C1->CR1 |= I2C_CR1_PE;
}

void I2C_WRITE(uint8_t add,uint8_t cmt,uint8_t data){
	/* Clear flags */
	    I2C1->ICR |= I2C_ICR_STOPCF | I2C_ICR_NACKCF;

	    /* Clear CR2 */
	    I2C1->CR2 = 0;

	    /* Slave address + WRITE */
	    I2C1->CR2 |= (add << 1);

	    /* NBYTES = 1 */
	    I2C1->CR2 |= (2U << 16);

	    /* Automatic STOP */
	    I2C1->CR2 |= I2C_CR2_AUTOEND;

	    /* START */
	    I2C1->CR2 |= I2C_CR2_START;

	    /* Wait for TXIS */
	    while (!(I2C1->ISR & I2C_ISR_TXIS));

	    /* Send data */
	    I2C1->TXDR = cmt;

	    /* Wait for TXIS */
	    while (!(I2C1->ISR & I2C_ISR_TXIS));

	    /* Send data */
	    I2C1->TXDR = data;

	    /* Wait for STOP/NACK */
	    while (!(I2C1->ISR & (I2C_ISR_STOPF | I2C_ISR_NACKF)));
	}



void I2C_CMT(uint8_t cmt)
{
   I2C_WRITE(SSD1306_ADDR,SSD1306_CMT,cmt);
}

void I2C_DATA(uint8_t data){
	I2C_WRITE(SSD1306_ADDR,SSD1306_DATA,data);
}
