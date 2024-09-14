/*
 * multi_7_segment.c
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */
#include"multi_7_segment.h"

struct multi_7_segment* g_7_segment_disp = 0;
void Seven_Seg_INIT( struct multi_7_segment* a_disp) {

	g_7_segment_disp=a_disp;
	*(a_disp->data_ddr) |= (g_7_segment_disp->data_bitMask);
	*(a_disp->multi_ddr) |= (g_7_segment_disp->multi_bitMask);
	GPIO_SetPinDirection(g_7_segment_disp->decimal_port, g_7_segment_disp->decimal_pin, OUTPUT);

}

void Disp_7_Segment(uint8_t *a_data) {
	*(g_7_segment_disp->multi_port) &= ~(g_7_segment_disp->multi_bitMask);
	for (uint8_t i = 0; i < g_7_segment_disp->_7_segment_num; i++) {
		//Select_Disp(i);

		SET_BIT(*(g_7_segment_disp->multi_port), i);
		*(g_7_segment_disp->data_port)&= ~(g_7_segment_disp->data_bitMask);
		a_data[i] &= ~(_7_SEGMENT_DATA_RESET_BIT_MASK);
		*(g_7_segment_disp->data_port) |= (a_data[i]);
		if (i == 1 || i == 3)
			GPIO_WritePin(g_7_segment_disp->decimal_port, g_7_segment_disp->decimal_pin, LOW);

		else
			GPIO_WritePin(g_7_segment_disp->decimal_port, g_7_segment_disp->decimal_pin, HIGH);

		_delay_ms(1);
		//delay(1);
		*(g_7_segment_disp->multi_port) &= ~(g_7_segment_disp->multi_bitMask);

	}
}

