/*
 * SPI_Pravite.h
 *
 * Created: 4/22/2022 11:31:28 PM
 *  Author: Sara Ahmed
 */ 


#ifndef SPI_PRAVITE_H_
#define SPI_PRAVITE_H_

#define SPCR          *((volatile u8*)(0x2D))                                 //SPI Control Register

#define SPIE          7                                                       //Bit 7 – SPIE: SPI Interrupt Enable
#define SPE           6                                                       //Bit 6 – SPE: SPI Enable
#define DORD          5                                                       //Bit 5 – DORD: Data Order
#define MSTR          4                                                       //Bit 4 – MSTR: Master/Slave Select
#define CPOL          3                                                       //Bit 3 – CPOL: Clock Polarity
/************************************************************************/
/* CPOL Functionality

CPOL      Leading Edge       Trailing Edge
0         Rising             Falling
1         Falling            Rising                                                                     */
/************************************************************************/
#define CPHA          2                                                       //Bit 2 – CPHA: Clock Phase
/************************************************************************/
/* CPHA Functionality
CPHA       Leading Edge     Trailing Edge
0          Sample           Setup
1          Setup            Sample
                                                                     */
/************************************************************************/


#define SPR1          1                                                       //Bits 1– SPR1: SPI Clock Rate Select 1 
#define SPR0          0                                                       //Bits 0– SPR0: SPI Clock Rate Select 0 

#define SPSR          *((volatile u8*)(0x2E))                                 //SPI Status Register

#define SPIF          7                                                       //Bit 7 – SPIF: SPI Interrupt Flag
#define WCOL          6                                                       //Bit 6 – WCOL: Write COLlision Flag
/** • Bit 5..1 – Res: Reserved Bits **/
#define SPI2X          0                                                       //Bit 0 – SPI2X: Double SPI Speed Bit
/************************************************************************/
/* Relationship Between SCK and the Oscillator Frequency

 SPI2X    SPR1    SPR0    SCK Frequency
 0        0        0          fosc/4
 0        0        1          fosc/16
 0        1        0          fosc/64
 0        1        1          fosc/128
 1        0        0          fosc/2
 1        0        1          fosc/8
 1        1        0          fosc/32
 1        1        1          fosc/64                                                                    */
/************************************************************************/


#define SPDR          *((volatile u8*)(0x2F))                                 //SPI Data Register






#endif /* SPI_PRAVITE_H_ */