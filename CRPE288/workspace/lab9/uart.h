/*
 * uart.h
 *
 *  Created on: Apr 6, 2017
 *      Author: jnachman
 */

#ifndef UART_H_
#define UART_H_
#include "lcd.h"
#include "timer.h"
#include "stdio.h"
#include <inc/tm4c123gh6pm.h>

void uart_init();

void uart_sendChar(char data);

void uart_sendStr(char data[], int len);

#endif /* UART_H_ */
