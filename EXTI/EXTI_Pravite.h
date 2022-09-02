/*
 * EXTI_Pravite.h
 *
 * Created: 9/27/2021 3:48:15 PM
 *  Author: Sara Ahmed
 */ 


#ifndef EXTI_PRAVITE_H_
#define EXTI_PRAVITE_H_
 
#define ENABLE                    1
#define DISABLE                   0

#define EXTI_RISING_EDGE          3
#define EXTI_FALLING_EDGE         2
#define EXTI_ONCHANGE             1
#define EXTI_LOWLEVEL             0  

#define EXTI_RISING_EDGE_INT2     1
#define EXTI_FALLING_EDGE_INT2    0  
	
#define GICR        *((volatile u8* )(0x5B))  //global interrupt control register : contain(enable bits for external interrupt).
#define INT0         6                       //INT1: External Interrupt Request 0 Enable (BIT 6)
#define INT1         7                       //INT1: External Interrupt Request 1 Enable (BIT 7)
#define INT2         5                       //INT1: External Interrupt Request 2 Enable (BIT 5)

#define MCUCR       *((volatile u8*)(0x55))       //MCU Control Register : contains control bits for interrupt sense control for (INT0 and INT1).
// Interrupt Sense Control for(INT0)  Bit 1 and Bit 0
#define ISC00       0                          
#define ISC01       1
/*
ISC11 ISC10          Description
0      0             The low level of INT0 generates an interrupt request.
0      1             Any logical change on INT0 generates an interrupt request.
1      0             The falling edge of INT0 generates an interrupt request.
1      1             The rising edge of INT0 generates an interrupt request
*/

// Interrupt Sense Control for(INT1)  Bit 1 and Bit 0
#define ISC10       2
#define ISC11       3
/*
ISC11 ISC10          Description
0      0             The low level of INT1 generates an interrupt request.
0      1             Any logical change on INT1 generates an interrupt request.
1      0             The falling edge of INT1 generates an interrupt request.
1      1             The rising edge of INT1 generates an interrupt request
*/

#define MCUCSR       *((volatile u8*)(0x54))   //MCU Control and Status Register : contains control bit for interrupt sense control for (INT2).
#define ISC2         6                         //Bit 6 – ISC2: Interrupt Sense Control (INT2)
/*
ISC2                 Description
0                    The falling edge of INT2 generates an interrupt request.
1                   The rising edge of INT2 generates an interrupt request
*/

#define GIFR        *((volatile u8*)(0x5A))   //General Interrupt Flag register : contains the interrupt flags for all the ATmega32 external interrupts.
#define INTF0       6                         //When an edge or logic change on the INT0 pin triggers an interrupt request, INTF0 becomes set (one) by hardware.
#define INTF1       7                        //When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1 becomes set (one) by hardware.
#define INTF2       5                        //When an event on the INT2 pin triggers an interrupt request, INTF2 becomes set (one) dy hardware.


#endif /* EXTI_PRAVITE_H_ */