/*
 * TIMER2_Interface.h
 *
 * Created: 10/25/2021 12:52:48 AM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


void TIMER2_Void_TimerOverFlow_Interrupt(void);

/*
Function Name        : TIMER2_Void_TimerOverFlow_Interrupt
Function Returns     : void
Function Arguments   : void
Function Description : initialize the interrupt of time over flow mode of timer2.
*/
void TIMER2_VoidInit_CTC_Interrupt(void);
/*
Function Name        : TIMER2_VoidInit_CTC_Interrupt
Function Returns     : void
Function Arguments   : void
Function Description : initialize the interrupt of the CTC mode of timer2.
*/
void TIMER2_VoidGenrate_Wave_NonPWM(void);
/*
	Function Name        : TIMER2_VoidGenrate_Wave_NonPWM
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the generation of a wave on OC2 pin in NonPWM mode.
*/
void TIMER2_VoidGenrate_Wave_FastPWM(void);
/*
Function Name        : TIMER0_VoidGenrate_Wave_FastPWM
Function Returns     : void
Function Arguments   : void
Function Description : initialize the generation of a wave on OC2 pin in fast PWM mode.
*/
void TIMER2_VoidGenrate_Wave_PhaseCorrectMode(void);
/*
	Function Name        : TIMER2_VoidGenrate_Wave_PhaseCorrectMode
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the generation of a wave on OC2 pin in phase correct PWM mode.
*/

void TIMER2_Void_CTC_CallBack(void(*f_ptr)(void));
/*
Function Name        : TIMER2_Void_CTC_CallBack
Function Returns     : void
Function Arguments   : pointer to function.
Function Description : take the instruction that wanted to be executed in the ISR of campare match of timer2.
*/

void TIMER2_Void_TOF_CallBack(void(*f_ptr)(void));
/*
Function Name        : TIMER2_Void_TOF_CallBack
Function Returns     : void
Function Arguments   : pointer to function.
Function Description : take the instructions that wanted to be executed in the ISR of timer over flow of timer2.
*/


#endif /* TIMER2_INTERFACE_H_ */