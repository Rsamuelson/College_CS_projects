/*
 * WiFi.c
 *
 *  Created on: Sep 25, 2016
 *      Author: ericm
 */

#include <string.h>

#include "WiFi.h"
#include "uart.h"

#define COMMAND_PIN		0x04

#define COMMAND_START	0
#define COMMAND_STOP	1

#define RETVAL_SUCCESS	0


void WiFi_start()
{
	//int commandPin = 1; //Enter command mode
	GPIO_PORTB_DATA_R |=BIT2; //0b100
	GPIO_PORTB_PCTL_R |= 0x100;
	GPIO_PORTB_DIR_R |=BIT2;
	GPIO_PORTB_DEN_R |=BIT2;

	uart_sendChar(0); //Send command
	uart_sendStr("password", strlen("password")); //Send WiFi PSK

	uart_sendChar(0x00); //NULL terminator

	char response = uart_receive(); //Wait for response
	//commandPin = 0 //Leave command mode
	GPIO_PORTB_DATA_R &=0b011;
	if(response != 0)
	{
		//An error occurred…
	}
}

void WiFi_stop()
{
	//int commandPin = 1 //Enter command mode
	GPIO_PORTB_DATA_R |=BIT2; //0b100
	uart_sendChar(1); //Send command
	char response = uart_receive(); //Wait for response
	//commandPin = 0; //Leave command mode
	GPIO_PORTB_DATA_R &=0b011;
	if(response != 0)
	{
		//An error occurred…
	}

}
