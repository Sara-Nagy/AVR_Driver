/*
 * WDT_Pravite.h
 *
 * Created: 2/26/2022 6:03:47 PM
 *  Author: Sara Ahmed
 */ 


#ifndef WDT_PRAVITE_H_
#define WDT_PRAVITE_H_

#define WDTCR         *((volatile u16*)(0x41))        //Watchdog Timer Control Register

#define WDTOE         4                              //Watchdog Turn-off Enable
#define WDE           3                              //Watchdog Enable
#define WDP2          2                              //Watchdog Timer Prescaler 2
#define WDP1          1                              //Watchdog Timer Prescaler 1
#define WDP0          0                              //Watchdog Timer Prescaler 0
/*
Watchdog Timer Prescale Select

WDP2 WDP1 WDP0     Number of WDT   Oscillator Cycles Typical Time-out at VCC = 3.0V    Oscillator Cycles Typical Time-out at VCC = 5.0V

0     0    0       16K (16,384)               17.1 ms                                                 16.3 ms
0     0    1       32K (32,768)               34.3 ms                                                 32.5 ms
0     1    0       64K (65,536)               68.5 ms                                                 65 ms
0     1    1       128K (131,072)             0.14 s                                                  0.13 s
1     0    0       256K (262,144)             0.27 s                                                  0.26 s
1     0    1       512K (524,288)             0.55 s                                                  0.52 s
1     1    0       1,024K (1,048,576)         1.1 s                                                   1.0 s
1     1    1       2,048K (2,097,152)         2.2 s                                                   2.1 s
*/



#endif /* WDT_PRAVITE_H_ */