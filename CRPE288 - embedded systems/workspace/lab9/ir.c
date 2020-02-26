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

void ADC_init(void)
{
	//enable ADC 0 module on port D
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
	//enable clock for ADC
	SYSCTL_RCGCADC_R |= 0x1;
	//enable port D pin 0 to work as alternate functions
	GPIO_PORTD_AFSEL_R |= 0x10;
	//set pin to input - 0
	GPIO_PORTD_DEN_R &= 0b11101111;
	//disable analog isolation for the pin
	GPIO_PORTD_AMSEL_R |= 0x10;
	//initialize the port trigger source as processor (default)
	GPIO_PORTD_ADCCTL_R = 0x00;
	//enable ADC 0 module on port D

	//disable SS0 sample sequencer to configure it
	ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN0;
	//initialize the ADC trigger source as processor (default)
	ADC0_EMUX_R = ADC_EMUX_EM0_PROCESSOR;
	//set 1st sample to use the AIN10 ADC pin
	ADC0_SSMUX0_R |= 0x000A;
	//enable raw interrupt
	ADC0_SSCTL0_R |= (ADC_SSCTL0_IE0 | ADC_SSCTL0_END0);
	//enable oversampling to average
	ADC0_SAC_R |= ADC_SAC_AVG_64X;
	//re-enable ADC0 SS0
	ADC0_ACTSS_R |= ADC_ACTSS_ASEN0;


}


unsigned ADC_read(char channel)
{
//disable ADC0SS0 sample sequencer to configure it
ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN0;
//set 1st sample to use the channel ADC pin
ADC0_SSMUX0_R |= channel;
//re-enable ADC0 SS0
ADC0_ACTSS_R |= ADC_ACTSS_ASEN0;
//initiate SS0 conversion
ADC0_PSSI_R=ADC_PSSI_SS0;
//wait for ADC conversion to be complete
while((ADC0_RIS_R & ADC_RIS_INR0) == 0){}
//clear interrupt
ADC0_ISC_R=ADC_ISC_IN0;
return ADC0_SSFIFO0_R;
}

/*void main()
{
	ADC_init();
	lcd_init();

	while(1)
	{
		int val = ADC_read(0);

		int cent = 109860*pow(val,-1.179);



			lcd_printf("%i, %i cm", val, cent);

			timer_waitMillis(500);
	}
	return 0;
}*/




