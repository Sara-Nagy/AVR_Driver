/*
 * WDT_Programe.c
 *
 * Created: 2/26/2022 6:02:34 PM
 *  Author: Sara Ahmed 
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "WDT_Config.h"
#include "WDT_Pravite.h"

void WDT_Void_Enable(void)
{
	//Watchdog timer enables with typical timeout period
	WDTCR=(WDTCR &0b11111000)|WDT_PRESCALER;
	
	//Set Watchdog Enable bit
	SET_BIT(WDTCR,WDE);
}

void WDT_Void_Disable(void)
{
	// Write logical one to WDTOE and WDE 
	WDTCR = (1<<WDTOE) | (1<<WDE);
	// Turn off WDT 
	WDTCR = 0x00;
}