
#include "stopwatch.h"
volatile uint8_t g_time[TIME_SIZE] = { MIN_mins_sec };
volatile uint8_t g_interrupt_0_flag_reset = FALSE;
volatile uint8_t g_interrupt_1_flag_pause = FALSE;
volatile uint8_t g_interrupt_2_flag_resume = FALSE;
volatile uint8_t g_end_countdown_flag = FALSE;
volatile uint8_t g_reset = FALSE;
uint8_t g_disp_data[NUM_7_SEGMETS] = { MIN_mins_sec };
uint8_t stateMachine = COUNT_UP;
uint8_t previousState = COUNT_UP;
struct pushbutton mode_button;
struct pushbutton sec_inc_button;
struct pushbutton sec_dec_button;
struct pushbutton min_inc_button;
struct pushbutton min_dec_button;
struct pushbutton hour_inc_button;
struct pushbutton hour_dec_button;
struct multi_7_segment display ;

int main() {

	Timer1_Init_CTC_Mode(COMP_VALUE_ONE_SEC_TIMER1);
	Timer0_Init_CTC_Mode(COMP_VALUE_ONE_mSEC_TIMER0);


	GPIO_Init();
	Init_display();
	Interrupt_INIT();
	Init_Stopwatch_Buttons();

	 StopWatch_Reset_time();


	for (;;) {


		Handle_Button_Presses();
		Handle_End_Count_Down();
		StopWatch_StateMachine();

	}

}
void Timer1_Counter_INC() {
	if (g_time[SECS] < MAX_mins_sec) {
		g_time[SECS]++;
	} else {
		if (g_time[MINS] < MAX_mins_sec) {
			g_time[MINS]++;
			g_time[SECS] = MIN_mins_sec;
		} else {
			g_time[HOURS]++;
			g_time[MINS] = MIN_mins_sec;
			g_time[SECS] = MIN_mins_sec;
		}
	}

}
void Timer1_Counter_DEC() {
	if (g_time[SECS] > MIN_mins_sec) {
		g_time[SECS]--;
	} else {
		if (g_time[MINS] > MIN_mins_sec) {
			g_time[MINS]--;
			g_time[SECS] = MAX_mins_sec;
		} else {
			if (g_time[HOURS] > MIN_HOURS) {
				g_time[HOURS]--;
				g_time[SECS] = MAX_mins_sec;
				g_time[MINS] = MAX_mins_sec;
			} else {
				g_end_countdown_flag = TRUE;

			}
		}
	}
	if (g_time[SECS] == MIN_mins_sec && g_time[MINS] == MIN_mins_sec
			&& g_time[HOURS] == MIN_HOURS) {
		g_end_countdown_flag = TRUE;
	}

}

// resets time in time_Calculator(uint8_t*) function
void  StopWatch_Reset_time() {
	TCNT0 = MIN_HOURS;
	g_time[HOURS] = MIN_HOURS;
	g_time[MINS] = MIN_mins_sec;
	g_time[SECS] = MIN_mins_sec;
}
void Display_time() {
	g_disp_data[0] = (uint8_t) (g_time[HOURS] / 10);
	g_disp_data[1] = g_time[HOURS] % 10;
	g_disp_data[2] = (uint8_t) (g_time[MINS] / 10);
	g_disp_data[3] = g_time[MINS] % 10;
	g_disp_data[4] = (uint8_t) (g_time[SECS] / 10);
	g_disp_data[5] = g_time[SECS] % 10;

	Disp_7_Segment(g_disp_data);
}
void GPIO_Init() {


	GPIO_SetPinDirection('D', BUZZER_PIN, OUTPUT);

	GPIO_SetPinDirection('A', ON_OFF_LED, OUTPUT);
	GPIO_SetPinDirection('D', RESET_D, INPUT_PULLUP);
	GPIO_SetPinDirection('B', RESUME_B, INPUT_PULLUP);
	GPIO_SetPinDirection('D', PAUSE_D, INPUT_PULLUP);

//PORTB |= (1 << PB7);


}
void Interrupt_INIT() {

	INT_0_Init(FALLING_EDGE, &g_interrupt_0_flag_reset);
	INT_1_Init(FALLING_EDGE, &g_interrupt_1_flag_pause);
	INT_2_Init(FALLING_EDGE, &g_interrupt_2_flag_resume);

}
void Init_Stopwatch_Buttons() {
	Pushbutton_Init(&mode_button, 'B', MODE_B, INPUT_PULLUP);
	Pushbutton_Init(&sec_inc_button, 'B', SECS_INC_B, INPUT_PULLUP);
	Pushbutton_Init(&sec_dec_button, 'B', SECS_DEC_B, INPUT_PULLUP);
	Pushbutton_Init(&min_inc_button, 'B', MINS_INC_B, INPUT_PULLUP);
	Pushbutton_Init(&min_dec_button, 'B', MINS_DEC_B, INPUT_PULLUP);
	Pushbutton_Init(&hour_inc_button, 'B', HOURS_INC_B, INPUT_PULLUP);
	Pushbutton_Init(&hour_dec_button, 'B', HOURS_DEC_B, INPUT_PULLUP);
}

void Handle_Button_Presses() {
	if (g_interrupt_0_flag_reset) {
		 StopWatch_Reset_time();
		g_interrupt_0_flag_reset = FALSE;

	} else if (g_interrupt_1_flag_pause) {
		if (stateMachine != PAUSE)
			previousState = stateMachine;
		stateMachine = PAUSE;
		g_interrupt_1_flag_pause = FALSE;

	} else if (g_interrupt_2_flag_resume) {

		Timer1_ON();
		g_interrupt_2_flag_resume = FALSE;
		if (g_end_countdown_flag) {

			g_end_countdown_flag = FALSE;
			stateMachine = COUNT_UP;
			set_CallBack(Timer1_Counter_INC);

		} else {
			stateMachine = previousState;
		}

	} else if (Pushbutton_Pressed(&mode_button)) {
		if (stateMachine == COUNT_UP) {
			stateMachine = COUNT_DOWN;
			set_CallBack(Timer1_Counter_DEC);
			GPIO_WritePin('D', COUNT_UP_LED_D, LOW);
			GPIO_WritePin('D', COUNT_DOWN_LED_D, HIGH);
		} else if (stateMachine == COUNT_DOWN) {
			stateMachine = COUNT_UP;
			set_CallBack(Timer1_Counter_INC);
			GPIO_WritePin('D', COUNT_UP_LED_D, HIGH);
			GPIO_WritePin('D', COUNT_DOWN_LED_D, LOW);
		} else if (stateMachine == PAUSE) {
			if (previousState == COUNT_UP) {
				previousState = COUNT_DOWN;
				set_CallBack(Timer1_Counter_DEC);
				GPIO_WritePin('D', COUNT_UP_LED_D, LOW);
				GPIO_WritePin('D', COUNT_DOWN_LED_D, HIGH);

			} else if (previousState == COUNT_DOWN) {
				previousState = COUNT_UP;
				set_CallBack(Timer1_Counter_INC);
				GPIO_WritePin('D', COUNT_UP_LED_D, HIGH);
				GPIO_WritePin('D', COUNT_DOWN_LED_D, LOW);

			}

		}
	}

}
void Handle_End_Count_Down() {
	if (g_end_countdown_flag) {
		stateMachine = PAUSE;
		GPIO_WritePin('D', BUZZER_PIN, HIGH);

	} else {
		GPIO_WritePin('D', BUZZER_PIN, LOW);

	}
}
void INC_SEC() {
	Timer1_Counter_INC();
}
void DEC_SEC() {
	Timer1_Counter_DEC();
}
void INC_MIN() {
	if (g_time[MINS] < MAX_mins_sec) {
		g_time[MINS]++;
	} else {
		g_time[HOURS]++;
		g_time[MINS] = MIN_mins_sec;

	}
}
void DEC_MIN() {
	if (g_time[MINS] > MIN_mins_sec) {
		g_time[MINS]--;
	} else {
		if (g_time[HOURS] > MIN_mins_sec) {
			g_time[HOURS]--;
			g_time[MINS] = MAX_mins_sec;
		}

	}
}

void INC_HOUR() {
	if (g_time[HOURS] < MAX_HOURS)
		g_time[HOURS]++;

	else
		g_time[HOURS] = MIN_HOURS;

}

void DEC_HOUR() {
	if (g_time[HOURS] > MIN_HOURS)
		g_time[HOURS]--;
}

void StopWatch_Adjust_Time() {
	if (Pushbutton_Pressed(&sec_inc_button)) {
		INC_SEC();
	} else if (Pushbutton_Pressed(&sec_dec_button)) {
		DEC_SEC();
	} else if (Pushbutton_Pressed(&min_dec_button)) {
		DEC_MIN();
	}

	else if (Pushbutton_Pressed(&min_inc_button)) {

		INC_MIN();

	}

	else if (Pushbutton_Pressed(&hour_inc_button)) {

		INC_HOUR();

	} else if (Pushbutton_Pressed(&hour_dec_button)) {

		DEC_HOUR();

	}

}
void StopWatch_StateMachine() {
	switch (stateMachine) {
	case COUNT_UP:
		set_CallBack(Timer1_Counter_INC);
		GPIO_WritePin('D', COUNT_UP_LED_D, HIGH);
		GPIO_WritePin('D', COUNT_DOWN_LED_D, LOW);
		GPIO_WritePin('A', ON_OFF_LED, HIGH);
		Display_time();
		break;
	case COUNT_DOWN:
		set_CallBack(Timer1_Counter_DEC);
		GPIO_WritePin('D', COUNT_DOWN_LED_D, HIGH);
		GPIO_WritePin('D', COUNT_UP_LED_D, LOW);
		GPIO_WritePin('A', ON_OFF_LED, HIGH);
		Display_time();
		break;
	case PAUSE:
		Timer1_OFF();
		GPIO_WritePin('A', ON_OFF_LED, LOW);
		Display_time();
		StopWatch_Adjust_Time();

		break;

	}

}
void Init_display(){
display._7_segment_num=NUM_7_SEGMETS;
display.data_bitMask=_7_SEGMENT_DATA_BIT_MASK;
display.multi_bitMask=_7_SEGMENT_MULTI_BIT_MASK;
display.data_ddr=&DDRC;
display.multi_ddr=&DDRA;
display.multi_port=&PORTA;
display.data_port=&PORTC;
display.decimal_pin=DECIMAL_POINT;
display.decimal_port='D';
Seven_Seg_INIT(&display);
}
