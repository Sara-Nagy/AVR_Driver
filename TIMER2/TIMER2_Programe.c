/*
 * TIMER2_Programe.c
 *
 * Created: 10/25/2021 12:52:13 AM
 *  Author: Sara Ahmed
 */ 

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "TIMER2_Config.h"
#include "TIMER2_Pravite.h"

void (*TIMER2_COM_Ptr)(void)=0;    //interrupt for compare match mode 
void (*TIMER2_OVF_Ptr)(void)=0;    //interrupt for timer over flow mode 
void TIMER2_Void_TimerOverFlow_Interrupt(void)
{
	//1_select timer over flow  mode : 0b00
	CLR_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
	
	//2_select timer2 clock 
	SET_BIT(ASSR,AS2);      //Timer/Counter2 is clocked from a Crystal Oscillator connected to the Timer Oscillator  1 (TOSC1) pin and 2 (TOSC2) pin 
	
	//3_select timer prescaler 
	TCCR2=(TCCR2 & 0b11111000)|TIMER2_CLOCK;
	
	//4_enable interrupt
	SET_BIT(TIMSK,TOIE2 );
	
}

void TIMER2_VoidInit_CTC_Interrupt(void)
{
	
	
	//1_select CTC mode : 0b10
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
	//2_load a value in OCR0 
	OCR2=80;  
	//3_select timer clock 
	TCCR2=(TCCR2 & 0b11111000)|TIMER2_CLOCK;
	/*
	every interrupt compare match= 10 ms
	*/
	//4_enable interrupt
	SET_BIT(TIMSK,OCIE2);

}

void TIMER2_VoidGenrate_Wave_NonPWM(void)
{
	//1_set OC2 as output pin 
	DIO_VoidSetPinDirection(4,7,1);
	//2_select CTC mode
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
	//3_load a value in OCR2 
	OCR2=64;
	//4_select timer clock 
	TCCR2=(TCCR2 & 0b11111000)|TIMER2_CLOCK;
	//5_toggle OC2 on compare match
	TCCR2=(TCCR2 & 0b11001111)|(OC2_COMPARA_MATCH<<4);
	
}
void TIMER2_VoidGenrate_Wave_FastPWM(void)
{
	//1_set OC2 as output pin 
	DIO_VoidSetPinDirection(4,7,1);
	//2_select fast PWM mode
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	//3_load a value in OCR2 
	OCR2=128;
	//4_select timer clock 
	TCCR2=(TCCR2 & 0b11111000)|TIMER2_CLOCK;
	//5_ Clear OC0 on compare match, set OC2 at TOP,(non inverting mode)*
	TCCR2=(TCCR2 & 0b11001111)|(OC2_FAST_PWM<<4);
}
void TIMER2_VoidGenrate_Wave_PhaseCorrectMode(void)
{
	//1_ set OC0 as output pin 
	DIO_VoidSetPinDirection(4,7,1);
	//2_select phase correct PWM mode ob01
	CLR_BIT(TCCR2,WGM21); 
	SET_BIT(TCCR2,WGM20);
	//3_load a value in OCR2 
	OCR2=64;
	//4_select timer clock 
	TCCR2=(TCCR2 & 0b11111000)|TIMER2_CLOCK;
	//5_ Clear OC0 on compare match when up-counting. Set OC0 on compare  match when downcounting.
	TCCR2=(TCCR2 & 0b11001111)|(OC2_PHASE_CORRECT_PWM <<4);

}	
void TIMER2_Void_CTC_CallBack(void(*f_ptr)(void))
{
	TIMER2_COM_Ptr=f_ptr;
}

void TIMER2_Void_TOF_CallBack(void(*f_ptr)(void))
{
	TIMER2_OVF_Ptr=f_ptr;
}
//ISR of Timer2 of compare match
void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	if(TIMER2_COM_Ptr!=0)
	{
		TIMER2_COM_Ptr();
	}
}
//ISR of Timer2 of timer over flow
void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	if(TIMER2_OVF_Ptr!=0)
	{
		TIMER2_OVF_Ptr();
	}
}
