/*
 * USART_Pravite.h
 *
 * Created: 4/6/2022 5:40:50 PM
 *  Author: IT Shop
 */ 


#ifndef USART_PRAVITE_H_
#define USART_PRAVITE_H_

#define F_CPU 8000000UL 
#define UBRR_NORMAL_SPEED(baud)     (F_CPU/(16*baud))-1
#define UBRR_DOUBLE_SPEED(baud)     (F_CPU/(8*baud))-1

#define UDR                    *((volatile u8*)(0x2C))         //USART I/O Data Register

#define UCSRA                  *((volatile u8*)(0x2B))         //USART Control and Status Register A
#define RXC                    7                                //Bit 7 – RXC: USART Receive Complete
#define TXC                    6                                //Bit 6 – TXC: USART Transmit Complete
#define UDRE                   5                                //Bit 5 – UDRE: USART Data Register Empty
#define FE                     4                                //Bit 4 – FE: Frame Error
#define DOR                    3                                //Bit 3 – DOR: Data OverRun
#define PE                     2                                //Bit 2 – PE: Parity Error
#define U2X                    1                                //Bit 1 – U2X: Double the USART Transmission Speed
#define MPCM                   0                                //Bit 0 – MPCM: Multi-processor Communication Mode

#define UCSRB                 *((volatile u8*)(0x2A))         //USART Control and Status Register B
#define RXCIE                 7                                //Bit 7 – RXCIE: RX Complete Interrupt Enable
#define TXCIE                 6                                //Bit 6 – TXCIE: TX Complete Interrupt Enable
#define UDRIE                 5                                //Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
#define RXEN                  4                                //Bit 4 – RXEN: Receiver Enable
#define TXEN                  3                                //Bit 3 – TXEN: Transmitter Enable
#define UCSZ2                 2                                //Bit 2 – UCSZ2: Character Size
#define RXB8                  1                                //Bit 1 – RXB8: Receive Data Bit 8
#define TXB8                  0                               //Bit 0 – TXB8: Transmit Data Bit 8


#define UCSRC                *((volatile u8*)(0x40))         //USART Control and Status Register C
#define URSEL                7                                //Bit 7 – URSEL: Register Select
#define UMSEL                6                                //Bit 6 – UMSEL: USART Mode Select
/** UMSEL Bit Settings
UMSEL       Mode
0          Asynchronous Operation
1          Synchronous Operation
**/
#define UPM1                5                                //Bit 5 – UPM1 Parity Mode
#define UPM0                4                                //Bit 4 – UPM0 Parity Mode
/** UPM Bits Settings
UPM1   UPM0     Parity Mode
0       0        Disabled
0       1        Reserved
1       0        Enabled, Even Parity
1       1        Enabled, Odd Parity
**/
#define USBS                3                                //Bit 3 – USBS: Stop Bit Select
/** USBS Bit Settings
USBS      Stop Bit(s)
0          1-bit
1          2-bit
**/
#define UCSZ1                2                                 //Bit 2 – UCSZ1: Character Size
#define UCSZ0                1                                //Bit 1 – UCSZ0: Character Size
/*** UCSZ Bits Settings
UCSZ2   UCSZ1 UCSZ0          Character Size
0        0         0           5-bit
0        0         1           6-bit
0        1         0           7-bit
0        1         1           8-bit
1        0         0           Reserved
1        0         1           Reserved
1        1         0           Reserved
1        1         1           9-bit
**/                                                                    

#define UCPOL                0                                //Bit 0 – UCPOL: Clock Polarity
/** UCPOL Bit Settings
UCPOL     Transmitted Data Changed (Output of  TxD Pin)   Received Data Sampled (Input on RxD Pin)

0            Rising XCK Edge                                   Falling XCK Edge
1            Falling XCK Edge                                  Rising XCK Edge
**/

#define UBRRH                *((volatile u8*)(0x40))         //USART Baud Rate Register UBRRH
#define UBRRL                *((volatile u8*)(0x29))         //USART Baud Rate Register UBRRL

#endif /* USART_PRAVITE_H_ */