#include"timer_1.h"


static  void (*PTR2_Timer1_CallBack)(void)=NULL_PTR;






ISR(TIMER1_COMPA_vect)
{  PTR2_Timer1_CallBack();
    }
// Initiate timer 1 with prescale 1024 and comp value 15625 interrupt every 1 sec use time_Calculator(uint8_t*); to get time in hours minutes and seconds
void Timer1_Init_CTC_Mode(uint16_t a_tick_1)
{
    sei();
    TCNT1 = 0; // Set Timer initial value to 0

    OCR1A = a_tick_1; // Set Compare Value

    TIMSK |= (1 << OCIE1A); // Enable Timer0 Compare Interrupt

    // TCCR1A |= (1<<FOC1A);
    TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
}


// get time in ms from start of initiating timer0


void set_CallBack(void(*ptr2func)(void)){
	PTR2_Timer1_CallBack=ptr2func;
}
void Timer1_OFF(){
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}
void Timer1_ON(){
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
}
