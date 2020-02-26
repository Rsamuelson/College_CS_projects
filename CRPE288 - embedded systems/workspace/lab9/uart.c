/*
 * uart.c
 *
 *  Created on: Apr 6, 2017
 *      Author: jnachman
 */

#include "lcd.h"
#include "timer.h"
#include "stdio.h"
#include <inc/tm4c123gh6pm.h>

void uart_init(void) {
	//enable clock to GPIO, R1 = port B
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
	//enable clock to UART1, R1 = UART1. ***Must be done before setting Rx and Tx (SeeDataSheet)
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
	//enable alternate functions on port b pins 0 and 1
	GPIO_PORTB_AFSEL_R |= (BIT0 | BIT1);
	//enable Rx and Tx on port B on pins 0 and 1
	GPIO_PORTB_PCTL_R |= 0x00000011;
	//set pin 0 and 1 to digital
	GPIO_PORTB_DEN_R |= (BIT0 | BIT1 | BIT2);
	//set pin 0 to Rx or input
	GPIO_PORTB_DIR_R &= ~BIT0;
	//set pin 1 to Tx or output
	GPIO_PORTB_DIR_R |= BIT1 | BIT2;
	//calculate baudrate
	uint16_t iBRD = 16000000/(16*115200); //use equations
	uint16_t fBRD = 0.68*(64) + 0.5; //use equations
	//turn off uart1 while we set it up
	UART1_CTL_R &= ~(UART_CTL_UARTEN);
	//set baud rate
	UART1_IBRD_R = iBRD;
	UART1_FBRD_R = fBRD;
	//set frame, 8 data bits, 1 stop bit, no parity, no FIFO
	UART1_LCRH_R = UART_LCRH_WLEN_8 ;
	//use system clock as source
	UART1_CC_R = UART_CC_CS_SYSCLK;
	//re-enable enable RX, TX, and uart1
	UART1_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
}//END of uart_init()

void uart_sendChar(char data)
{
//wait until there is room to send data
	while(UART1_FR_R & 0x20)
		{
		}
	//send data
	UART1_DR_R = data;
}

void uart_sendStr(char data[], int len)
{
	//send data
	len = strlen(data);
	int i;
	for(i = 0; i<len; i++)
	{
		uart_sendChar(data[i]);
	}
}

char uart_receive(void){
	char data = 0;
	//wait to receive
	while(UART1_FR_R & UART_FR_RXFE)
	{
		lcd_printf("%c\n", data);
	}
	data =  UART1_DR_R;
	//mask the 4 error bits and grab only 8 data bitsklkjkl
	return data;
}


