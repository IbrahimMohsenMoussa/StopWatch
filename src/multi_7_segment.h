/*
 * multi_7_segment.h
 *
 *  Created on: 9 Sept 2024
 *      Author: MSI
 */

#ifndef MULTI_7_SEGMENT_H_
#define MULTI_7_SEGMENT_H_

#include<avr/io.h>
#include<util/delay.h>
#include<stdint.h>
#include"gpio.h"
#include"timer_0.h"
struct multi_7_segment {

	uint8_t _7_segment_num ;
	volatile uint8_t *data_ddr;
	volatile uint8_t *multi_ddr;
	volatile uint8_t *data_port;
	volatile uint8_t *multi_port;
	uint8_t data_bitMask;
	uint8_t multi_bitMask;
	uint8_t decimal_port;
	uint8_t decimal_pin;




};




#define _7_SEGMENT_DATA_RESET_BIT_MASK 0xf0
void  Seven_Seg_INIT(  struct multi_7_segment* a_disp);
void Select_Disp(uint8_t a_dispNo);
void Disp_7_Segment(uint8_t *a_data);

#endif /* MULTI_7_SEGMENT_H_ */
