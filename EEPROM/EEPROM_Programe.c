/*
 * EEPROM_Programe.c
 *
 * Created: 9/13/2021 11:18:51 AM
 *  Author: IT Shop
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "EEPROM_Pravite.h"
#include "EEPROM_Config.h"

void EEPROM_VoidWrite(u16 u16cpy_address,u8 u8cpy_data)
{
	//1-set up address register
	EEAR=u16cpy_address;
	/* we can set up in this way
	EEARL=(U8)u8cpy_address;
	EEARH=(U8)(u8cpy_address>>8);
	*/
	
	//2_set up data register
	EEDR=u8cpy_data;
	
	//we should disable global interrupt to avoid problems.
   //3_set EEMWE bit to 1
   SET_BIT(EECR,EEMWE);
   
  //4_set EEWE bit to 1 to start EEPROM wtite
  SET_BIT(EECR,EEWE);
  //we should enable global interrupt.
  
  //5_wait for finish write process.
  while(GET_BIT(EECR,EEWE)==1);
	
}

u8 EEPROM_U8Read(u16 u16cpy_address)
{ 
	
	//1-set up address register
	EEAR=u16cpy_address;
	/* we can set up in this way
	EEARL=(U8)u8cpy_address;
	EEARH=(U8)(u8cpy_address>>8);
	*/
	
	//2-set EERE bit to 1 to start EEPROM read
	SET_BIT(EECR,EERE);
	
	//3_return data from data register
	return EEDR;
	
	
	
	
	
}