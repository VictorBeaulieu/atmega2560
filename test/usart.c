/*
 * usart.c
 *
 * Created: 16/01/2019 11:29:15
 *  Author: VictorBeaulieu
 */ 


#include "usart.h"

void init_usart0(unsigned int bd,unsigned int config){
	unsigned int ubrr = (CLOCK / 16/bd)-1;	
	unsigned char data_size = config / 100;
	unsigned char parity = (config % 100)/10;
	unsigned char stop_bit = (config % 100)%10;	
	UBRR0H = (unsigned char) (ubrr >> 8);
	UBRR0L = (unsigned char) ubrr;	
	UCSR0A = 0x00;
	UCSR0B = 0x98;
	UCSR0C = 0x00;	
	switch (data_size)
	{
		case 5:
			UCSR0C &= 0xF9;
			break;
		case 6:
			UCSR0C |= 0x02;
			break;
		case 7:
			UCSR0C |= 0x04;
			break;
		case 8:
			UCSR0C |= 0x06;
			break;
	}
	switch (parity)
	{
		case 0:
			UCSR0C &= 0xCF;
			break;
		case 1:
			UCSR0C |= 0x20;
			break;
		case 2:
			UCSR0C |= 0x60;
			break;		
	}
	switch (stop_bit)
	{
		case 1:
			UCSR0C &= 0xF7;
			break;
		case 2:
			UCSR0C |= 0x08;
			break;
	}
	RX0_index=0;
	RX0_msg_complete = FALSE;
	sei();
}
void init_usart1(unsigned int bd,unsigned int config){
	unsigned int ubrr = (CLOCK / 16/bd)-1;
	
	unsigned char data_size = config / 100;
	unsigned char parity = (config % 100)/10;
	unsigned char stop_bit = (config % 100)%10;
	
	UBRR1H = (unsigned char) (ubrr >> 8);
	UBRR1L = (unsigned char) ubrr;
	
	UCSR1A = 0x00;
	UCSR1B = 0x98;
	UCSR1C = 0x00;
	
	switch (data_size)
	{
		case 5:
			UCSR1C &= 0xF9;
			break;
		case 6:
			UCSR1C |= 0x02;
			break;
		case 7:
			UCSR1C |= 0x04;
			break;
		case 8:
			UCSR1C |= 0x06;
			break;
	}
	switch (parity)
	{
		case 0:
			UCSR1C &= 0xCF;
			break;
		case 1:
			UCSR1C |= 0x20;
			break;
		case 2:
			UCSR1C |= 0x60;
			break;
	}
	switch (stop_bit)
	{
		case 1:
			UCSR1C &= 0xF7;
			break;
		case 2:
			UCSR1C |= 0x08;
			break;
	}
	RX1_index=0;
	RX1_msg_complete = FALSE;
	sei();
}
void init_usart2(unsigned int bd,unsigned int config){
	unsigned int ubrr = (CLOCK / 16/bd)-1;
	unsigned char data_size = config / 100;
	unsigned char parity = (config % 100)/10;
	unsigned char stop_bit = (config % 100)%10;
	UBRR2H = (unsigned char) (ubrr >> 8);
	UBRR2L = (unsigned char) ubrr;
	UCSR2A = 0x00;
	UCSR2B = 0x98;
	UCSR2C = 0x00;
	switch (data_size)
	{
		case 5:
		UCSR2C &= 0xF9;
		break;
		case 6:
		UCSR2C |= 0x02;
		break;
		case 7:
		UCSR2C |= 0x04;
		break;
		case 8:
		UCSR2C |= 0x06;
		break;
	}
	switch (parity)
	{
		case 0:
		UCSR2C &= 0xCF;
		break;
		case 1:
		UCSR2C |= 0x20;
		break;
		case 2:
		UCSR2C |= 0x60;
		break;
	}
	switch (stop_bit)
	{
		case 1:
		UCSR2C &= 0xF7;
		break;
		case 2:
		UCSR2C |= 0x08;
		break;
	}
	RX2_index=0;
	RX2_msg_complete = FALSE;
	sei();
}
void init_usart3(unsigned int bd,unsigned int config){
	unsigned int ubrr = (CLOCK / 16/bd)-1;
	unsigned char data_size = config / 100;
	unsigned char parity = (config % 100)/10;
	unsigned char stop_bit = (config % 100)%10;
	UBRR3H = (unsigned char) (ubrr >> 8);
	UBRR3L = (unsigned char) ubrr;
	UCSR3A = 0x00;
	UCSR3B = 0x98;
	UCSR3C = 0x00;
	switch (data_size)
	{
		case 5:
		UCSR3C &= 0xF9;
		break;
		case 6:
		UCSR3C |= 0x02;
		break;
		case 7:
		UCSR3C |= 0x04;
		break;
		case 8:
		UCSR3C |= 0x06;
		break;
	}
	switch (parity)
	{
		case 0:
		UCSR3C &= 0xCF;
		break;
		case 1:
		UCSR3C |= 0x20;
		break;
		case 2:
		UCSR3C |= 0x60;
		break;
	}
	switch (stop_bit)
	{
		case 1:
		UCSR3C &= 0xF7;
		break;
		case 2:
		UCSR3C |= 0x08;
		break;
	}
	RX3_index=0;
	RX3_msg_complete = FALSE;
	sei();
}

void write_char_usart0(unsigned char c){
	while((UCSR0A & 0x20)==0);
	UDR0 = c;
}
void write_char_usart1(unsigned char c){
	while((UCSR1A & 0x20)==0);
	UDR1 = c;
}
void write_char_usart2(unsigned char c){
	while((UCSR2A & 0x20)==0);
	UDR2 = c;
}
void write_char_usart3(unsigned char c){
	while((UCSR3A & 0x20)==0);
	UDR3 = c;
}

void send_string_usart0(unsigned char *str){
	unsigned char i = 0;
	while(str[i] != 0)
	{
		write_char_usart0(str[i]);
		i++;
	}
}
void send_string_usart1(unsigned char *str){
	unsigned char i = 0;
	while(str[i] != 0)
	{
		write_char_usart1(str[i]);
		i++;
	}
}
void send_string_usart2(unsigned char *str){
	unsigned char i = 0;
	while(str[i] != 0)
	{
		write_char_usart2(str[i]);
		i++;
	}
}
void send_string_usart3(unsigned char *str){
	unsigned char i = 0;
	while(str[i] != 0)
	{
		write_char_usart3(str[i]);
		i++;
	}
}

unsigned char read_char_usart0(){
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
unsigned char read_char_usart1(){
	while (!(UCSR1A & (1<<RXC1)));
	return UDR1;
}
unsigned char read_char_usart2(){
	while (!(UCSR2A & (1<<RXC2)));
	return UDR2;
}
unsigned char read_char_usart3(){
	while (!(UCSR3A & (1<<RXC3)));
	return UDR3;
}


ISR(USART0_RX_vect)
{
	if(RX0_index == 0) memset(msg_from_usart0, 0, RX_BUFFER);
	unsigned char c;
	while (!(UCSR0A & (1<<RXC0)));
	c = UDR0;
	msg_from_usart0[RX0_index] = c;
	RX0_index++;
	if(c == 0x0a)
	{
		msg_from_usart0[RX0_index+1] = 0;
		RX0_msg_complete = TRUE;	
		RX0_index=0;
	}
}
ISR(USART1_RX_vect){
	if(RX1_index == 0) memset(msg_from_usart1, 0, RX_BUFFER);
	unsigned char c;
	while (!(UCSR1A & (1<<RXC1)));
	c = UDR1;
	msg_from_usart1[RX1_index] = c;
	RX1_index++;
	if(c == 0x0a)
	{
		msg_from_usart1[RX1_index+1] = 0;
		RX1_msg_complete = TRUE;
		RX1_index=0;
	}	
}
ISR(USART2_RX_vect){
	if(RX2_index == 0) memset(msg_from_usart2, 0, RX_BUFFER);
	unsigned char c;
	while (!(UCSR2A & (1<<RXC2)));
	c = UDR2;
	msg_from_usart2[RX2_index] = c;
	RX2_index++;
	if(c == 0x0a)
	{
		msg_from_usart2[RX2_index+1] = 0;
		RX2_msg_complete = TRUE;
		RX2_index=0;
	}
}
ISR(USART3_RX_vect){
	if(RX3_index == 0) memset(msg_from_usart3, 0, RX_BUFFER);
	unsigned char c;
	while (!(UCSR3A & (1<<RXC3)));
	c = UDR3;
	msg_from_usart3[RX3_index] = c;
	RX3_index++;
	if(c == 0x0a)
	{
		msg_from_usart3[RX3_index+1] = 0;
		RX3_msg_complete = TRUE;
		RX3_index=0;
	}
}