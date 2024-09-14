/*
 * external_interrupts.h
 *
 *  Created on: 11 Sept 2024
 *      Author: MSI
 */

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_
#include<avr/interrupt.h>
#include"gpio.h"
void INT_0_Init(uint8_t a_detect,volatile uint8_t *a_ptr2_flag);
void INT_1_Init(uint8_t a_detect,volatile uint8_t *a_ptr2_flag);
void INT_2_Init(uint8_t a_detect,volatile uint8_t *a_ptr2_flag);
typedef enum{
	RISING_EDGE,FALLING_EDGE,TOGGLE,LOW_LEVEL
}external_interrupt;


#endif /* EXTERNAL_INTERRUPTS_H_ */
