/*
 * timer_0.c
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint64_t time_ms = 0;

ISR(TIMER0_COMP_vect)
{
    time_ms++;
}
// Initiate timer 0 with prescale 64 and comp value 250 interrupt every 1 ms use millis(); to read time in ms;
void Timer0_Init_CTC_Mode(uint16_t a_tick0)
{
    sei();
    TCNT0 = 0; // Set Timer initial value to 0

    OCR0 = a_tick0; // Set Compare Value

    TIMSK |= (1 << OCIE0); // Enable Timer0 Compare Interrupt

    TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << CS01)|(1 << CS00);
}
unsigned long long  millis()
{
    return time_ms;
}
void delay(uint64_t a_time){
	sei();
	volatile unsigned long long previous=millis();
	while((millis()-previous)<=a_time){

	}
}
