/*
 * WDT_Config.h
 *
 * Created: 2/26/2022 6:03:23 PM
 *  Author: IT Shop
 */ 


#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_
 
#define WDT_PRESCALER    7   //0b111
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



#endif /* WDT_CONFIG_H_ */