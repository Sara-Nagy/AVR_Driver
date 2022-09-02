/*
 * USART_Interface.h
 *
 * Created: 4/6/2022 5:41:14 PM
 *  Author: IT Shop
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "../LIB/STD_TYPES.h" 

void USART_VoidInit(u16 baud);
/*
Function Name        : USART_VoidInit
Function Returns     : void
Function Arguments   : unsigned short (the baub rate).
Function Description : initialize the USART communication protocol.
*/

void USART_VoidSend_Char(s8 s8copy_data);
/*
Function Name        : USART_VoidSend_Char
Function Returns     : void
Function Arguments   : unsigned char(data to sent)
Function Description : Send data using USART.
*/

void USART_VoidSend_data_9_bits(s16 s16copy_data);
/*
Function Name        : USART_VoidSend_data_9_bits
Function Returns     : void
Function Arguments   : unsigned short(data to sent)
Function Description : Send data using USART.
*/

void USART_VoidSend_string(s8 * s8copy_data);
/*
Function Name        : USART_VoidSend_string
Function Returns     : void
Function Arguments   : pointer to unsigned char(data to sent)
Function Description : Send data using USART.
*/

u8 USART_u8_Receive_Char(void);
/*
Function Name        : USART_u8_Receive_Char
Function Returns     : void
Function Arguments   : unsigned char(data to sent)
Function Description : Receive data using USART.
*/

s16 USART_u16_Receive_Data_9_Bit(void);
/*
Function Name        : USART_u16_Receive_Data_9_Bit
Function Returns     : void
Function Arguments   : unsigned short(data to sent)
Function Description : Receive data using USART.
*/


#endif /* USART_INTERFACE_H_ */