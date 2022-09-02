/*
 * SPI_Interface.h
 *
 * Created: 4/22/2022 11:31:06 PM
 *  Author: Sara Ahmed
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "../LIB/STD_TYPES.h" 

void SPI_MasterVoid_Init(void);
/*
Function Name        : SPI_MasterVoid_Init
Function Returns     : void
Function Arguments   : void
Function Description : initialize the Master Mode of the SPI communication protocol.
*/

void SPI_SlaveVoid_Init(void);
/*
Function Name        : SPI_SlaveVoid_Init
Function Returns     : void
Function Arguments   : void
Function Description : initialize the Slave Mode of the SPI communication protocol.
*/

u8 SPI_U8Master_Transmit_Char(u8 u8copy_data);

/*
Function Name        : SPI_U8Master_Transmit_Char
Function Returns     : unsigned char(received data)
Function Arguments   : unsigned char(transmitted data)
Function Description : Send 8 bits data from master to slave and receive 8 bits data from slave if wanted.
*/

void SPI_VoidMaster_Transmit_String(u8 * u8copy_data);

/*
Function Name        : SPI_U8Master_Transmit_Char
Function Returns     : void
Function Arguments   : pointer to unsigned char(transmitted data)
Function Description : Send string from master to slave.
*/

u8 SPI_U8Slave_Receive_Char(u8 u8copy_data);

/*
Function Name        : SPI_U8Slave_Receive_Char
Function Returns     : unsigned char(received data)
Function Arguments   : unsigned char(transmitted data)
Function Description : Send 8 bits data from slave to master and receive 8 bits data from master.
*/



#endif /* SPI_INTERFACE_H_ */