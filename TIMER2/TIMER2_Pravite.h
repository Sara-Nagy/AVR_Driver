/*
 * TIMER2_Pravite.h
 *
 * Created: 10/25/2021 12:53:44 AM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER2_PRAVITE_H_
#define TIMER2_PRAVITE_H_

#define TCNT2                *((volatile u8*)(0x44)))      //Timer/Counter0 Register

#define TCCR2                *((volatile u8*)(0x45))      //Timer/Counter0 Control Register
#define FOC2                 7                            //Bit 7 – FOC2: Force Output Compare
//Bit 6, 3 – WGM21:0: Waveform Generation Mode
#define WGM20                6
#define WGM21                3
/*

Mode  WGM21(CTC2)   WGM20(PWM2)   Timer/Counter Mode    TOP       Update of       TOV0 Flag Set-on
                                  of Operation                    OCR0       
								  
0      0               0          Normal                 0xFF      Immediate       MAX
1      0               1          PWM, Phase Correct     0xFF      TOP             BOTTOM
2      1               0          CTC                    OCR0      Immediate       MAX
3      1               1          Fast PWM               0xFF      TOP             MAX
*/
//Bit 5:4 – COM01:0: Compare Match Output Mode
#define COM20                4
#define COM21                5
/**** Compare Output Mode, non-PWM Mode ****/
/*
COM21 COM20                Description
0      0                   Normal port operation, OC0 disconnected.
0      1                   Toggle OC0 on compare match
1      0                   Clear OC0 on compare match
1      1                   Set OC0 on compare match
*/
/**** Compare Output Mode, Fast PWM Mode ****/
/*
COM21 COM20      Description
0      0         Normal port operation, OC0 disconnected.
0      1         Reserved
1      0         Clear OC0 on compare match, set OC0 at TOP
1      1         Set OC0 on compare match, clear OC0 at TOP
*/
/**** Compare Output Mode, Phase Correct PWM Mode ****/
/*
COM21 COM20           Description
0      0              Normal port operation, OC0 disconnected.
0      1              Reserved
1      0              Clear OC0 on compare match when up-counting. Set OC0 on compare
                      match when downcounting.
1      1              Set OC0 on compare match when up-counting. Clear OC0 on compare
                      match when downcountin
*/

//Bit 2:0 – CS22:0: Clock Select
#define CS20                  0
#define CS21                  1
#define CS22                  2
/*
CS22 CS21 CS20    Description
0     0    0      No clock source (Timer/Counter stopped).
0     0    1      clkT2S/(No prescaling)
0     1    0      clkT2S/8 (From prescaler)
0     1    1      clkT2S/32 (From prescaler)
1     0    0      clkT2S/64 (From prescaler)
1     0    1      clkT2S/128 (From prescaler)
1     1    0      clkT2S/256 (From prescaler)
1     1    1      clkT2S
*/

#define OCR2                 *((volatile u8*)(0x43))      //Output Compare Register

#define TIMSK                *((volatile u8*)(0x59))      //Timer/Counter Interrupt Mask Register
#define TOIE2                6                             //Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
#define OCIE2                7                           //Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable

#define TIFR                 *((volatile u8*)(0x58))      //Timer/Counter Interrupt Flag Register
#define TOV2                 6                            //Bit 0 – TOV0: Timer/Counter0 Overflow Flag
#define OCF2                 7                            //Bit 1 – OCF0: Output Compare Flag 0

#define ASSR                  *((volatile u8*)(0x42))

#define AS2                   3                       //Bit 3 – AS2: Asynchronous Timer/Counter2
/*
When AS2 is written to zero, Timer/Counter 2 is clocked from the I/O clock, clkI/O. When
AS2 is written to one, Timer/Counter2 is clocked from a Crystal Oscillator connected to
the Timer Oscillator 1 (TOSC1) pin. When the value of AS2 is changed, the contents of
TCNT2, OCR2, and TCCR2 might be corrupted
*/


#endif /* TIMER2_PRAVITE_H_ */