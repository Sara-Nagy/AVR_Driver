/*
 * EXTI_Programe.c
 *
 * Created: 9/27/2021 3:47:02 PM
 *  Author: Sara Ahmed
 */ 
#include  "../LIB/BIT_MATH.h"
#include  "../LIB/STD_TYPES.h"
#include  "../DIO/DIO_Interface.h"
#include  "EXTI_Config.h"
#include  "EXTI_Pravite.h"

void EXTI_VoidInit(void)
{
	//INT0
	#if EXTI_INT0 == ENABLE
	//1_ select sense control 
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	MCUCR |= (EXTI_INT0_INT1_SENSEMODE <<0); 
	//2_set interrupt enable bit
	SET_BIT(GICR ,INT0);
	//3_set the direction of pin of INT0 as input pin
	DIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_IN);
	
	//INT1
	#elif EXTI_INT1 == ENABLE
	//1_ select sense control
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	MCUCR |= (EXTI_INT0_INT1_SENSEMODE <<2);
	//2_set interrupt enable bit
	SET_BIT(GICR ,INT1);
	//3_set the direction of pin of INT0 as input pin
	DIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_IN);
	
	//INT2
	#elif EXTI_INT2 == ENABLE
	//1_ select sense control
	CLR_BIT(MCUCSR,ISC2);
	MCUCSR |= (EXTI_INT2_SENSEMODE <<6);
	//2_set interrupt enable bit
	SET_BIT(GICR ,INT2);
	//3_set the direction of pin of INT0 as input pin
	DIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_IN);
	#endif	
}
