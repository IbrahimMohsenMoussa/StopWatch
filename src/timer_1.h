/*
 * timer.h
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */


#ifndef TIMER_H_
#define TIMER_H_
#include"gpio.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

//Initiate timer 0 with prescale 8 and comp value 250 interrupt every 1 ms use millis(); to read time in ms;
void Timer1_Init_CTC_Mode(uint16_t a_tick_1);


void set_CallBack(void(*ptr2func)(void));
void Timer1_OFF();
void Timer1_ON();

#endif /* TIMER_H_ */
