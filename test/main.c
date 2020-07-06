/*
 * test.c
 *
 * Created: 06/07/2020 16:22:37
 * Author : Victor
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include "i2c.h"
#include <stdio.h>


int main(void)
{
	init_usart0(9600,_8N1);
	init_usart1(9600,_8N1);
	init_usart2(9600,_8N1);
	init_usart3(9600,_8N1);
	
	send_string_usart0((unsigned char*)"hello world from uart0\r\n");
	send_string_usart1((unsigned char*)"hello world from uart1\r\n");
	send_string_usart2((unsigned char*)"hello world from uart2\r\n");
	send_string_usart3((unsigned char*)"hello world from uart3\r\n");
	
	while (1)
	{
		if(RX0_msg_complete == TRUE)
		{	
			send_string_usart0(msg_from_usart0);
			RX0_msg_complete = FALSE;
		}
		if(RX1_msg_complete == TRUE)
		{
			send_string_usart0(msg_from_usart1);
			RX1_msg_complete = FALSE;
			
		}
		if(RX2_msg_complete == TRUE)
		{
			send_string_usart0(msg_from_usart2);
			RX2_msg_complete = FALSE;
			
		}
		if(RX3_msg_complete == TRUE)
		{
			send_string_usart0(msg_from_usart3);
			RX3_msg_complete = FALSE;
			
		}
		_delay_ms(10);
		
	}
}