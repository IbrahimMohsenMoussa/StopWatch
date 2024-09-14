/*
 * pushbutton.h
 *
 *  Created on: 10 Sept 2024
 *      Author: MSI
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include"gpio.h"
#include"timer_0.h"

struct pushbutton
{
	uint8_t port;
	uint8_t pin;
	uint8_t state;
	uint8_t debounce_time;


};
void Pushbutton_Init(struct pushbutton*a_button , uint8_t a_port , uint8_t a_pin , uint8_t a_int_pull);
uint8_t Pushbutton_Pressed (struct pushbutton*a_button);
#endif /* PUSHBUTTON_H_ */
