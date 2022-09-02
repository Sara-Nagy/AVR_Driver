/*
 * USART_Program.c
 *
 * Created: 4/6/2022 5:39:41 PM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
//#include <avr/io.h>
#include "USART_Config.h"
#include "USART_Pravite.h"
#define F_CPU 8000000UL 

void USART_VoidInit(u16 baud)
{
	u16 UBRR=0;
	//1_choose the baud rate that will used by the sender and receiver.
	    UBRR=(F_CPU/(16*baud))-1;
		UBRRH = (u8)(UBRR>>8);                                   //URSEL bit should be zero to select UBRRH to write on it not UCSRC
		UBRRL = (u8)UBRR;
		
	//2_Enable receiver and transmitter 
	   SET_BIT(UCSRB,RXEN);
	   SET_BIT(UCSRB,TXEN);
	   
	//3_Set frame format: 8 data bit , 1 stop bit , no parity bit
	  UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);                           //URSEL bit should be one to select UCSRC to write on it not UBRRH
	
}

void USART_VoidSend_Char(s8 s8copy_data)
{
	//1_ Wait for empty transmit buffer 
	while ( GET_BIT(UCSRA,UDRE)==0 );
	
	//2_ Put data into buffer, sends the data 
	UDR = s8copy_data;
}
void USART_VoidSend_data_9_bits(s16 s16copy_data)
{
	//1_ Wait for empty transmit buffer
	while ( GET_BIT(UCSRA,UDRE)==0 );
	
   //2_clear TXB8 bit (clear bit if it used before send)
    CLR_BIT(UCSRC,TXB8);
	//3_copy TXB8 to UCSRB (if the ninth bit is 1)
	if (s16copy_data& 0x0100 )
		{
			SET_BIT(UCSRC,TXB8);
		}			
	//4__ Put data into buffer, sends the data
	UDR = s16copy_data;
}

void USART_VoidSend_string(s8 * s8copy_data)
{
	while(*s8copy_data !=0)
	{
		USART_VoidSend_Char(*s8copy_data);
		s8copy_data++;
		_delay_ms(100);
	}
	
}

u8 USART_u8_Receive_Char(void)
{

	// 1_ Wait for data to be received 
	while ( GET_BIT(UCSRA,RXC)==0 );
	
	//2_rececive data from UDR buffer
	return UDR ;
}

s16 USART_u16_Receive_Data_9_Bit(void)
{
	u8 status, resultH, resultL;
	
	// 1_ Wait for data to be received
	while ( GET_BIT(UCSRA,RXC)==0 );
	
	//2_ Get status and 9th bit, then data from buffer
	status = UCSRA;
	resultH = UCSRB;
	resultL = UDR;
	
	//3_ If error, return -1
	if ( status & (1<<FE)|(1<<DOR))
	return -1;
	
	//4_ Filter the 9th bit ,if the receive data is 9 bits
	resultH = (resultH >> 1) & 0x01;
	
	//5_receive data from UDR buffer and RXB8
		return ((resultH << 8) | resultL);

}