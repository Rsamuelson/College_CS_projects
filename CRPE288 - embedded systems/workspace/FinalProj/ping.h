#include "lcd.h"
#include "timer.h"
#include "stdio.h"
#include "math.h"
#include "driverlib/interrupt.h"


/* start and read the ping sensor once, return distance in mm */

/* ping sensor related to ISR */
void TIMER3B_Handler(void);

void timer_Ping_init();
void GPIO_Ping_init();
void send_pulse();
unsigned time2dist(unsigned time);
unsigned ping_read();
/*
void main()
{
	GPIO_init();
	timer_init();
	lcd_init();

	while(1)
	{
		int val = ping_read();

		lcd_printf("Value: %d", val);
		timer_waitMillis(350);

	}

}

*/



