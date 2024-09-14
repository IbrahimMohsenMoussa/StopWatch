/*
 * pushbutton.c
 *
 *  Created on: 10 Sept 2024
 *      Author: MSI
 */
#include"pushbutton.h"
void Pushbutton_Init(struct pushbutton *a_button, uint8_t a_port, uint8_t a_pin,
		uint8_t a_int_pull)
{
	a_button->port = a_port;
	a_button->pin = a_pin;
	a_button->state = 0;
	a_button->debounce_time=0;

	if (a_int_pull == INPUT_PULLUP)
	{
		GPIO_SetPinDirection(a_button->port, a_button->pin, INPUT_PULLUP);
	}
	else
	{
		GPIO_SetPinDirection(a_button->port, a_button->pin, INPUT);
	}

}
uint8_t Pushbutton_Pressed(struct pushbutton *a_button)
{
	uint8_t l_val = 0;

	if (!GPIO_ReadPin(a_button->port, a_button->pin))
	{
		if (!a_button->state)
		{
			l_val = 1;
			a_button->state = 1;
		}
	}
	else
	{
		l_val = 0;
		a_button->state = 0;

	}
	return l_val;
}

