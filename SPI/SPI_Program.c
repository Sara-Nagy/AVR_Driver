/*
 * SPI_Program.c
 *
 * Created: 4/22/2022 11:30:42 PM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "../DIO/DIO_Interface.h"
#include "SPI_Config.h"
#include "SPI_Pravite.h"


void SPI_MasterVoid_Init(void)
{ 
	//1_Set SS / MOSI / SCK  as output pins for master (MISO (DIO_PIN6) is by default input pin)
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUT);    //SS
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUT);    //MOSI
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUT);    //SCK
	
	//2_Enable Master mode
	SET_BIT(SPCR,MSTR);
	
	//3_Set clock to fosc/16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
	
	//4_Enable SPI
	SET_BIT(SPCR,SPE);
	
	//5_disable SPI Interrupt Enable
	CLR_BIT(SPCR,SPIE);
	
	//6_set SS to high   
	DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH); 
	
}

void SPI_SlaveVoid_Init(void)
{
	//1_Set MISO as output ( MOSI,SS,SCK is by default input pin)
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUT);
	
	//2_Enable slave mode
	CLR_BIT(SPCR,MSTR);
	
	//3_Enable SPI
	SET_BIT(SPCR,SPE);
}

u8 SPI_U8Master_Transmit_Char(u8 u8copy_data)
{
	//1_Clear SS to send data to slave
	DIO_VoidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_LOW); 
	//2_Put data on SPDR
	SPDR=u8copy_data;
	//3_Wait until the transmission is finished
	while(GET_BIT(SPSR,SPIF)==0);
	//4_read SPDR 
	return SPDR ;
}

void SPI_VoidMaster_Transmit_String(u8 * u8copy_data)
{
	while((*u8copy_data)!=0)
	{
		SPI_U8Master_Transmit_Char(*u8copy_data);
		_delay_ms(300);
		u8copy_data++;
	}
}

u8 SPI_U8Slave_Receive_Char(u8 u8copy_data)
{
	//1_Put data on SPDR
	SPDR=u8copy_data;
	//2_Wait until data is received in SPI register
	while(GET_BIT(SPSR,SPIF)==0);
	//3_read the received data
	return SPDR ;
}




