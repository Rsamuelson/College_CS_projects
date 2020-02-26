/*
 * main.c
 *  Created on: Feb 17, 2017
 *      Author: joel16
 */
#include "lcd.h"
#include "ping.h"
#include "timer.h"
//#include "stdio.h"
#include "driverlib/interrupt.h"
#include "WiFi.h"
#include <math.h>
#include "movement.h"
#include "open_interface.h"
#include "music.h"




unsigned mid_width = 8000;//23000==90, 37000==180, 8000==0;		//Higher value, more counter-clockwise  BOT0
unsigned pulse_period = 320000;
void timer_init()
{ //timer 3b


	SYSCTL_RCGCTIMER_R |= 0x02;//return clk for timer
	TIMER1_CTL_R &= ~0x100;//Disable timer config
	TIMER1_TBMR_R = 0x0A ; //periodic & PWM
	TIMER1_CFG_R = 0x04;//set size to 16

	TIMER1_TBILR_R =320000 & 0xFFFF; //lower 16 bits of the interval;
//	TIMER1_TBPS_R = 0xFF;//Used to check for overflow
	TIMER1_TBPR_R = 320000 >> 16; //set the upper 8 bits of the interval ;
	TIMER1_TBMATCHR_R =(pulse_period - mid_width) & 0xFFFF; // if you want to move servo to the middle
	TIMER1_TBPMR_R = (pulse_period - mid_width) >> 16;
	TIMER1_CTL_R |= 0x100;//Enable timer config



}
void GPIO_init()
{
	SYSCTL_RCGCGPIO_R |=  0x02; //Port B
	GPIO_PORTB_DEN_R |=0x20;	//PB5
	GPIO_PORTB_DIR_R |=0x20;
	GPIO_PORTB_AFSEL_R |=0x20;
	GPIO_PORTB_PCTL_R |=0x700000;

	//DEN
}

void move_servo(unsigned degree)
{

	if(degree<=180 && degree>=0)
	{

		mid_width = (161*degree) + 8167;
		TIMER1_TBMATCHR_R =(pulse_period - mid_width) & 0xFFFF; // if you want to move servo to the middle
		TIMER1_TBPMR_R = (pulse_period - mid_width) >> 16;
		timer_waitMillis(50);
	}

//unsigned pulse_width = 0; // pulse width in cycles
// calculate pulse width in cycles
//	TIMER1_TBMATCHR_R = (pulse_period - mid_width) & 0xFFFF; // set pulse width
//	TIMER1_TBPMR_R = (pulse_period - mid_width) >> 16;
////// you need to call timer_waitMillis( ) here to enforce a delay for the servo to
//	timer_waitMillis(500);
////// move to the position
}

double getDiameter(double angle, int startDist, int endDist)
{
		double val =  sqrt(((startDist*startDist)+(endDist*endDist))-((2*startDist*endDist)*cos((angle*3.14159/180))));
		return val;
}

void detect()
{
	int detect=0;
	double degreeStart=0.0; //Starting degree point of smallest object
	double degreeEnd = 0.0;	//Ending degree point of smallest object
	int startDist=0;	//Distance from bot to starting point
	int endDist=0; //Distance from bot to ending point

	int numObj = 0;	//Number of objects
	double smallest = 0; //smallest obj size

	int smallestLoc = 0; //smallest obj location

	char data[100];
	double degree = 0.0;

			while(degree<180.0)
			{
				int pingVal = ping_read();
				int irVal = ADC_read(0);
				irVal = 109860*pow(irVal,-1.179);

				if(pingVal<70)
				{

					if(detect == 0)
					{
						startDist = pingVal;
						degreeStart = degree;
						degreeEnd = degree;
						detect = 1;
					}
					else
					{
							endDist = pingVal;
							degreeEnd = degree;

					}
				}
				else
				{
					if(detect != 0)
					{
						if(degreeEnd - degreeStart >3)
						{
						if(smallest == 0 || smallest>getDiameter(degreeEnd-degreeStart, startDist, endDist))
						{
							smallest = getDiameter(degreeEnd-degreeStart, startDist, endDist);
							smallestLoc = (degreeEnd + degreeStart)/2;

						}

						numObj++;
					}
						degreeEnd = 0;
						degreeStart = 0;
						startDist = 0;
						endDist =0;
					}
					detect = 0;
				}
	//		(original degree and mov_servolocations)
				timer_waitMillis(50);
				sprintf(data, "%lf %i  %i",degree, irVal, pingVal);

				//uart_sendStr(data);


				degree +=1.0;
				move_servo(degree);

				lcd_printf(data);
				timer_waitMillis(30);

				//lcd_printf("%i, %i cm", pingVal, cent);
			}

			int j;
			double min = 0;
			int loc = 0;

			move_servo(smallestLoc);
			sprintf(data, "Smallest:%f Number of Objects: %i",smallest, numObj);
			lcd_printf(data);

}

void scanForObjects()
{
	int detect=0;
	double degreeStart=0.0; //Starting degree point of smallest object
	double degreeEnd = 0.0;	//Ending degree point of smallest object
	int startDist=0;	//Distance from bot to starting point
	int endDist=0; //Distance from bot to ending point

	int numObj = 0;	//Number of objects
	double loc[100];//degree of object from bot
	double dist[100];//distance of object from bot
	int i = 0; //for arrays
	int smallestLoc = 0; //smallest obj location


	char data[100];
	double degree = 0.0;

			while(degree<180.0)
			{
				int pingVal = ping_read();
				int irVal = ADC_read(0);
				irVal = 109860*pow(irVal,-1.179);

				if(pingVal<70)
				{

					if(detect == 0)
					{
						startDist = pingVal;
						degreeStart = degree;
						degreeEnd = degree;
						detect = 1;
					}
					else
					{
							endDist = pingVal;
							degreeEnd = degree;

					}
				}
				else
				{
					if(detect != 0)
					{
						if(degreeEnd - degreeStart >3)
						{
							numObj++;
							double base = getDiameter(degreeEnd-degreeStart, startDist, endDist)/2;
							loc[i] = (degreeEnd + degreeStart)/2;
							dist[i]= sqrt((endDist*endDist)-(base*base));
						}
						degreeEnd = 0;
						degreeStart = 0;
						startDist = 0;
						endDist =0;
					}
					i++;
					detect = 0;
				}
	//		(original degree and mov_servolocations)
				//timer_waitMillis(50);

				//uart_sendStr(data);
				degree +=1.0;
				move_servo(degree);
				timer_waitMillis(30);

				//lcd_printf("%i, %i cm", pingVal, cent);
			}

			int j;
			double min = 0;

			move_servo(90);

			uart_sendStr("Object: \t Degree: \t Distance: \n\r", 32);
			for(j = 0; j<=i; j++)
			{
				sprintf(data, "%i \t %lf \t %lf \n\r",j,loc[j],dist[j]);
				uart_sendStr(data, strlen(data));
			}
}

int cliffFrontDetect(oi_t *sensor_data)
{
	if(sensor_data->cliffFrontLeftSignal | sensor_data->cliffFrontRightSignal){
		return 0;
	}
	else
	{
		return 1;
	}
}




void main()
{
	ADC_init();
	GPIO_init();
	timer_init();
	lcd_init();
	GPIO_Ping_init();
	timer_Ping_init();
	uart_init();
	WiFi_start();
	oi_t *sensor_data = oi_alloc();
	oi_init(sensor_data);

	oi_setWheels(0,0);
	while(1)
	{
		oi_update(sensor_data);

		char cmd = uart_receive();
		lcd_printf("char %s", cmd);
		if(cmd == 'a')
		{
			turn(sensor_data, 90);

		}
		else if(cmd == 'w')
		{
			movement(sensor_data, 50);
		}
		else if(cmd == 'd')
		{
			turn(sensor_data, 90);
		}
		else if(cmd == 's')
		{
			movement(sensor_data, -50);
		}
		if(cmd == '1')
		{
			detect();
		}
		if(cmd == '2')
		{
			scanForObjects();
		}

		//movement(sensor_data, 1000);
		//oi_loadSong(1, 5, a, 5);
		//oi_play_song(5);
		//load_songs();
	}


	//oi_free(sensor_data); //dont need







}







