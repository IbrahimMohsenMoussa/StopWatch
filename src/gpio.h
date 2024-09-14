/*
 * gpio.h
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <avr/io.h>
#define NULL_PTR ((void*)0)
#define SET_BIT(REG,BIT_NO)(REG|=(1<<BIT_NO))
#define FG_SBI(mem_addr, bit) asm volatile("sbi %0, %1\n" : \
   : "I" (mem_addr - __SFR_OFFSET), "I" (bit))
#define FG_CBI(mem_addr, bit) asm volatile("cbi %0, %1\n" : \
    : "I" (mem_addr - __SFR_OFFSET), "I" (bit))
#define CLR_BIT(REG,BIT_NO)(REG&=~(1<<BIT_NO))
#define TOGGLE_BIT(REG,BIT_NO)(REG^=(1<<BIT_NO))
#define GETBIT(REG,BIT_NO)(((REG)&(1<<BIT_NO))>>BIT_NO)
typedef enum {
	INPUT, OUTPUT, INPUT_PULLUP
} pinDirection;
typedef enum {
	LOW, HIGH
} pinState;
void GPIO_SetPinDirection(uint8_t a_port, uint8_t a_pin, uint8_t state);
void GPIO_WritePin(uint8_t a_port, uint8_t a_pin, uint8_t a_state);
void GPIO_TooglePin(uint8_t a_port, uint8_t pin);
uint8_t GPIO_ReadPin(uint8_t a_port, uint8_t pin);

#endif /* GPIO_H_ */
