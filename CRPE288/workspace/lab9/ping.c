/*
 * main.c
 *
 *  Created on: Feb 17, 2017
 *      Author: joel16
 */
#include "lcd.h"
#include "timer.h"
#include "stdio.h"
#include "math.h"
#include "driverlib/interrupt.h"


volatile enum {LOW, HIGH, DONE} state;
volatile unsigned rising_time; // start time of the return pulse
volatile unsigned falling_time; // end time of the return pulse
int overflowCount = 0;


/* start and read the ping sensor once, return distance in mm */

/* ping sensor related to ISR */
void TIMER3B_Handler(void)
{
	TIMER3_ICR_R |= 0x0400;
	if(state == LOW)
	{
		rising_time = TIMER3_TBR_R;
		state = HIGH;

	}
	else if(state == HIGH)
	{
		falling_time = TIMER3_TBR_R;
		state = DONE;
	}


}

void timer_Ping_init()
{ //timer 3b

	SYSCTL_RCGCTIMER_R |= 0x08;
	TIMER3_CTL_R &= ~0x100;
	TIMER3_CTL_R |= 0xC00; //Correct?
	TIMER3_CFG_R = 0x04;
	TIMER3_TBMR_R = 0x17;
	TIMER3_TBILR_R = 0xFFFF;
//	TIMER3_TBPS_R = 0xFF;//Used to check for overflow
//	TIMER3_TBR_R = 0xFFFF;



	TIMER3_IMR_R |= 0x0400;
//	TIMER3_MIS_R |= 0x0400;
	TIMER3_ICR_R |= 0x0400;
	NVIC_EN1_R |= 0x010;

	IntRegister(INT_TIMER3B, TIMER3B_Handler);
	IntMasterEnable();

}
void GPIO_Ping_init()
{
	SYSCTL_RCGCGPIO_R |=  0x02;
	GPIO_PORTB_DEN_R |=0x08;
	//DEN
}
/* send out a pulse on PB3 */
void send_pulse()
{

	TIMER3_CTL_R &= ~TIMER_CTL_TBEN;
	GPIO_PORTB_AFSEL_R &= ~0x08;


	GPIO_PORTB_DIR_R |= 0x08; // set PB3 as output
	GPIO_PORTB_DATA_R |= 0x08; // set PB3 to high
	timer_waitMicros(5); // wait at least 5 microseconds based on data sheet
	GPIO_PORTB_DATA_R &= 0xF7; // set PB3 to low
	GPIO_PORTB_DIR_R &= 0xF7; // set PB3 as input
	GPIO_PORTB_AFSEL_R |= 0x08;
	GPIO_PORTB_PCTL_R |= 0x7000;
	TIMER3_CTL_R |= TIMER_CTL_TBEN;
}
/* convert time in clock counts to single-trip distance in mm */
unsigned time2dist(unsigned time)
{
	int val = time/935;
	return val;
}


unsigned ping_read()
{
	send_pulse(); // send the starting pulse to PING
// get time of the rising edge of the pulse
// get time of the falling edge of the pulse
	while(state != DONE)
	{
	}
	if(falling_time<rising_time)
	{
		overflowCount++;
		falling_time += 16777216;
	}
	state = LOW;

// Calculate the width of the pulse; convert to centimeters
	int time = falling_time - rising_time;
	return time2dist(time);

}





