/*
 * external_interrupts.c
 *
 *  Created on: 11 Sept 2024
 *      Author: MSI
 */
#include"external_interrupts.h"
uint8_t *ptr2_int_0_flag;
uint8_t *ptr2_int_1_flag;
uint8_t *ptr2_int_2_flag;
void INT_0_Init(uint8_t a_detect,volatile uint8_t *a_ptr2_flag)
{
	switch (a_detect)
	{
	case FALLING_EDGE:
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);

		break;
	case LOW_LEVEL:
		CLR_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);

		break;
	case TOGGLE:
		CLR_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;

	}
	SET_BIT(GICR, INT0);
	sei();
	ptr2_int_0_flag = a_ptr2_flag;

}
void INT_1_Init(uint8_t a_detect, volatile uint8_t *a_ptr2_flag)
{
	switch (a_detect)
	{
	case FALLING_EDGE:
		SET_BIT(MCUCR, ISC11);
		CLR_BIT(MCUCR, ISC10);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);

		break;
	case LOW_LEVEL:
		CLR_BIT(MCUCR, ISC11);
		CLR_BIT(MCUCR, ISC10);

		break;
	case TOGGLE:
		CLR_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		break;

	}
	SET_BIT(GICR, INT1);
	sei();
	ptr2_int_1_flag = a_ptr2_flag;

}
void INT_2_Init(uint8_t a_detect, volatile uint8_t *a_ptr2_flag)
{
	switch (a_detect)
	{
	case FALLING_EDGE:

		CLR_BIT(MCUCSR, ISC2);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR, ISC2);

		break;

	}
	SET_BIT(GICR, INT2);
	sei();
	ptr2_int_2_flag = a_ptr2_flag;

}
ISR (INT0_vect)
{
	*ptr2_int_0_flag = 1;
}
ISR (INT1_vect)
{
	*ptr2_int_1_flag = 1;
}
ISR (INT2_vect)
{
	*ptr2_int_2_flag = 1;
}

