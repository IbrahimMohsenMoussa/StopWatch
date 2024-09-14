/*
 * gpio.c
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */
#include "gpio.h"

void GPIO_SetPinDirection(uint8_t a_port, uint8_t a_pin, uint8_t state) {
	switch (a_port) {
	case 'A':

		switch (state) {
		case INPUT:
			CLR_BIT(DDRA, a_pin);
			break;
		case OUTPUT:
			SET_BIT(DDRA, a_pin);
			break;
		case INPUT_PULLUP:
			CLR_BIT(DDRA, a_pin);
			SET_BIT(PORTA, a_pin);
			break;
		}

		break;
	case 'B':

		switch (state) {
		case INPUT:
			CLR_BIT(DDRB, a_pin);
			break;
		case OUTPUT:
			SET_BIT(DDRB, a_pin);
			break;
		case INPUT_PULLUP:
			CLR_BIT(DDRB, a_pin);
			SET_BIT(PORTB, a_pin);
			break;
		}

		break;
	case 'C':

		switch (state) {
		case INPUT:
			CLR_BIT(DDRC, a_pin);
			break;
		case OUTPUT:
			SET_BIT(DDRC, a_pin);
			break;
		case INPUT_PULLUP:
			CLR_BIT(DDRC, a_pin);
			SET_BIT(PORTC, a_pin);
			break;
		}

		break;

	case 'D':

		switch (state) {
		case INPUT:
			CLR_BIT(DDRD, a_pin);
			break;
		case OUTPUT:
			SET_BIT(DDRD, a_pin);
			break;
		case INPUT_PULLUP:
			CLR_BIT(DDRD, a_pin);
			SET_BIT(PORTD, a_pin);
			break;
		}

		break;
	}
}
void GPIO_WritePin(uint8_t a_port, uint8_t a_pin, uint8_t a_state) {
	switch (a_port) {
	case 'A':

		switch (a_state) {
		case LOW:
			CLR_BIT(PORTA, a_pin);
			break;
		case HIGH:
			SET_BIT(PORTA, a_pin);
			break;
		}

		break;
	case 'B':

		switch (a_state) {
		case LOW:
			CLR_BIT(PORTB, a_pin);
			break;
		case HIGH:
			SET_BIT(PORTB, a_pin);
			break;
		}

		break;
	case 'C':

		switch (a_state) {
		case LOW:
			CLR_BIT(PORTC, a_pin);
			break;
		case HIGH:
			SET_BIT(PORTC, a_pin);
			break;
		}

		break;

	case 'D':

		switch (a_state) {
		case LOW:
			CLR_BIT(PORTD, a_pin);
			break;
		case HIGH:
			SET_BIT(PORTD, a_pin);
			break;
		}

		break;
	}
}
void GPIO_TooglePin(uint8_t a_port, uint8_t pin) {
	switch (a_port) {
	case 'A':
		TOGGLE_BIT(PORTA, pin);
		break;
	case 'B':
		TOGGLE_BIT(PORTB, pin);
		break;
	case 'C':
		TOGGLE_BIT(PORTC, pin);
		break;
	case 'D':
		TOGGLE_BIT(PORTD, pin);
		break;
	}
}

uint8_t GPIO_ReadPin(uint8_t a_port, uint8_t pin) {
	switch (a_port) {
	case 'A':
		return( PINA & (1 << pin));
		break;
	case 'B':
		return (PINB & (1 << pin));
		break;
	case 'C':
		return (PINC & (1 << pin));
		break;
	case 'D':
		return (PIND & (1 << pin));
		break;
	default:
		return 0;
		break;
	}
}
