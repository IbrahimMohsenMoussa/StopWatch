/*
 * timer_0.h
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */

#ifndef TIMER_0_H_
#define TIMER_0_H_

//Initiate timer 1 with prescale 1024 and comp value 15625 interrupt every 1 sec use time_Calculator(uint8_t*); to get time in hours minutes and seconds
void Timer0_Init_CTC_Mode(uint16_t a_tick_0);
//get time in ms from start of initiating timer0
uint64_t millis();
void delay(uint64_t a_time);

#endif /* TIMER_0_H_ */
