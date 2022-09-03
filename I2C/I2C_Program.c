/*
 * I2C_Program.c
 *
 * Created: 4/28/2022 11:36:55 PM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include "I2C_Config.h"
#include <avr/io.h>

void I2C_Void_Master_Init(u32 u32copy_SCL_Clock)
{
	TWBR= (u8) (((F_CPU/u32copy_SCL_Clock)-16) / (2*PRESCALAR));
	
	#if PRESCALAR==1
	
		TWSR=0;
	
	#elif PRESCALAR==4
	
		TWSR=1;
	
	#elif PRESCALAR==16
	
	   TWSR=2;
	
	#else PRESCALAR==64
	
	   TWSR=3;
	#endif
}

void I2C_Void_Start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);//clear TWINT , enable I2C, set TWSTA bit to send start condition 
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}

void I2C_Void_Repeated_Start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);//clear TWINT , enable I2C, set TWSTA bit to send start condition
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x10); // repeated start condition has been transmitted
}

void I2C_Void_Stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);//clear TWINT , enable I2C, set TWSTO bit to send stop condition 
	
}

void I2C_Void_WriteAddress_Write(u8 u8copy_address)
{
	TWDR=u8copy_address;
	TWCR=(1<<TWINT)|(1<<TWEN);//clear TWINT , enable I2C
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received
}

void I2C_Void_WriteAddress_Read(u8 u8copy_address)
{
	TWDR=u8copy_address;
	TWCR=(1<<TWINT)|(1<<TWEN);//clear TWINT , enable I2C
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x40); // SLA+Read has been transmitted and ACK has been received
}

void I2C_Void_Master_Write(u8 u8copy_data)
{
	TWDR=u8copy_data;
	TWCR=(1<<TWINT)|(1<<TWEN);//clear TWINT , enable I2C
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}

u8 I2C_U8_Master_Read(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);//clear TWINT , enable I2C 
	while(GET_BIT(TWCR,TWINT)==0);//wait to finish
	while ((TWSR & 0XF8) != 0x58);//data has been received : ACK has not been returned
	return TWDR;
	
} 

void I2C_Void_Slave_Write(u8 u8copy_data)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//clear TWINT , enable I2C , set TWEA to send ACK
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0xA8); // own SLA+Read has been received and ACK has been returned
	TWDR=u8copy_data;
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//clear TWINT , enable I2C , set TWEA to send ACK
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0xB8); // data has been transmitted and ACK has been received	
}

u8 I2C_U8_Slave_Read(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//clear TWINT , enable I2C , set TWEA to send ACK
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);//clear TWINT , enable I2C , set TWEA to send ACK
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
	return TWDR ;
}

void I2C_Void_Set_Address(u8 u8copy_address)
{

     TWAR=u8copy_address;	
}