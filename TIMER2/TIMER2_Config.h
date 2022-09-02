/*
 * TIMER2_Config.h
 *
 * Created: 10/25/2021 12:53:22 AM
 *  Author: Sara Ahmed
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

#define TIMER2_CLOCK    0b101
/*
                       Description
0  0  0       No clock source (Timer/Counter stopped).
0  0  1       clkT2S/(No prescaling)
0  1  0       clkT2S/8 (From prescaler)
0  1  1       clkT2S/32 (From prescaler)
1  0  0       clkT2S/64 (From prescaler)
1  0  1       clkT2S/128 (From prescaler)
1  1  0       clkT2S/256 (From prescaler)
1  1  1       clkT2S/1024 (From prescaler
*/
#define OC2_COMPARA_MATCH     0b01
/*
                           Description
0      0                   Normal port operation, OC0 disconnected.
0      1                   Toggle OC0 on compare match
1      0                   Clear OC0 on compare match
1      1                   Set OC0 on compare match
*/
#define OC2_FAST_PWM     0b10
/*
                 Description
0      0         Normal port operation, OC0 disconnected.
0      1         Reserved
1      0         Clear OC0 on compare match, set OC0 at TOP
1      1         Set OC0 on compare match, clear OC0 at TOP
*/
#define OC2_PHASE_CORRECT_PWM     0b10
/*
                      Description
0      0              Normal port operation, OC0 disconnected.
0      1              Reserved
1      0              Clear OC0 on compare match when up-counting. Set OC0 on compare
                      match when downcounting.
1      1              Set OC0 on compare match when up-counting. Clear OC0 on compare
                       match when downcountin.
*/


#endif /* TIMER2_CONFIG_H_ */