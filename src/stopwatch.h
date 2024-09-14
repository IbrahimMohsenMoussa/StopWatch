/*
 * stopwatch.h
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

/* AVR specific libraries*/
#include <avr/io.h>
#include<stdint.h>
#include <avr/interrupt.h>
#include<util/delay.h>
/*project specific files*/
#include "timer_1.h"
#include "timer_0.h"
#include"gpio.h"
#include"multi_7_segment.h"
#include"pushbutton.h"
#include "external_interrupts.h"

/* */
#define SECS 0
#define MINS 1
#define HOURS 2
#define TIME_SIZE 3
#define MAX_mins_sec 59
#define MIN_mins_sec 0
#define MAX_HOURS 99
#define MIN_HOURS 0
#define COMP_VALUE_ONE_SEC_TIMER1 15625
#define COMP_VALUE_ONE_mSEC_TIMER0 250
#define NUM_7_SEGMETS 6
#define HOURS_INC_B PB1
#define HOURS_DEC_B PB0
#define MINS_INC_B PB4
#define MINS_DEC_B PB3
#define SECS_INC_B PB6
#define SECS_DEC_B PB5
#define BUZZER_PIN PD0
#define ON_OFF_LED PA6
#define RESET_D PD2
#define PAUSE_D PD3
#define RESUME_B PB2
#define MODE_B PB7
#define COUNT_UP_LED_D PD4
#define COUNT_DOWN_LED_D PD5
#define FALSE 0
#define TRUE 1
#define _7_SEGMENT_MULTI_BIT_MASK 0x3f
#define _7_SEGMENT_DATA_BIT_MASK 0xf
#define DECIMAL_POINT PD6
#define DATA_PORT PORTC
#define MULTI_PORT PORTA
void Init_display();
/**
 * @brief Initiates All GPIO pins used in project
 * */
void GPIO_Init();
/*
 * @brief  Initiates All external interrupts to detect falling edge
 *  */
void Interrupt_INIT();
/**
 * @brief separates each digit in hours minutes and seconds and call Disp_7_segment to display time
 * */
void Display_time();
/**
 * @brief reset all elements of  g_time -hours , minutes , seconds- and the timer counter register
 * */
void StopWatch_Reset_time();
/**
 * @brief timer callback function increments 1 sec for each time its called
 * */
void Timer1_Counter_INC();
/**
 * @brief timer callback function decrements 1 sec for each time its called
 * */
void Timer1_Counter_DEC();
/**
 * @brief initiates all buttons in input pull up mode
 * */
void Init_Stopwatch_Buttons();
/**
 * @brief polling handles all button presses except time adjust buttons
 * */
void Handle_Button_Presses();

/**
 * @brief polling handles the end of count down activating the buzzer
 * */
void Handle_End_Count_Down();
/**
 * @brief increments time by 1 minutes
 * */
void INC_MIN();
/**
 * @brief decrements time by 1 minutes
 * */
void DEC_MIN();
/**
 * @brief increments time by 1 seconds
 * */
void INC_SEC();
/**
 * @brief decrements time by 1 second
 * */
void DEC_SEC();
/**
 * @brief increments time by 1 hour
 * */
void INC_HOUR();
/**
 * @brief decrements time by 1 hour
 * */
void DEC_HOUR();
/**
 * @brief adjust time in the global g_time[] array  by checking time increment and decrement buttons
 * */
void StopWatch_Adjust_Time();
/**
 * @brief Handles the stopWatch stateMachine switching between state COUNT_UP COUNT_DOWN and PAUSE
 * */
void StopWatch_StateMachine();
/*@brief handle all the cases for changing the stopwatch  mode  */
void Mode_Switching();

typedef enum {

	  COUNT_UP /* StopWatch in count up mode*/
	, COUNT_DOWN/* StopWatch in count Down mode*/
	, PAUSE/* StopWatch in Pause timer 1 stopped */
} StopWatch_State;

#endif /* STOPWATCH_H_ */
