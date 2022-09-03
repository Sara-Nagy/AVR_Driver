/*
 * I2C_Interface.h
 *
 * Created: 4/28/2022 11:36:21 PM
 *  Author: Sara Ahmed
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../LIB/STD_TYPES.H"

void I2C_Void_Master_Init(u32 u32copy_SCL_Clock);
/*
 * FUNCTION NAME:       I2C_Void_Master_Init
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned long int (SCL Clock)
 * FUNCTION DESCRIPTION:set the value of frequency of SCL that wanted to be use.
 */

void I2C_Void_Start(void);

/*
 * FUNCTION NAME:       I2C_Void_Start
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:send start condition to start the communication.
 */

void I2C_Void_Repeated_Start(void);
/*
 * FUNCTION NAME:       I2C_Void_Repeated_Start
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:send repeated start condition to start the communication.
 */

void I2C_Void_Stop(void);

/*
 * FUNCTION NAME:       I2C_Void_Stop
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:send stop condition to stop the communication.
 */

void I2C_Void_WriteAddress_Write(u8 u8copy_address);
/*
 * FUNCTION NAME:       I2C_Void_WriteAddress_Write
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char(the address and write bit)
 * FUNCTION DESCRIPTION:Send the address of the slave and Write bit.
 */

void I2C_Void_WriteAddress_Read(u8 u8copy_address);
/*
 * FUNCTION NAME:       I2C_Void_WriteAddress_Read
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char(the address and read bit)
 * FUNCTION DESCRIPTION:Send the address of the slave and Read bit.
 */

void I2C_Void_Master_Write(u8 u8copy_data);
/*
 * FUNCTION NAME:       I2C_Void_Master_Write
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char(the data)
 * FUNCTION DESCRIPTION:send data from master to slave.
 */

u8 I2C_U8_Master_Read(void);
/*
 * FUNCTION NAME:       I2C_U8_Master_Read
 * FUNCTION RETURN:     unsigned char(the data)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:master receive data slave.
 */

void I2C_Void_Slave_Write(u8 u8copy_data);
/*
 * FUNCTION NAME:       I2C_Void_Slave_Write
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char(the data)
 * FUNCTION DESCRIPTION:send data from slave to master.
 */

u8 I2C_U8_Slave_Read(void);
/*
 * FUNCTION NAME:       I2C_U8_Slave_Read
 * FUNCTION RETURN:     unsigned char(the data)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:slave receive data master.
 */

void I2C_Void_Set_Address(u8 u8copy_address);
/*
 * FUNCTION NAME:       I2C_Void_Set_Address
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  unsigned char(the address)
 * FUNCTION DESCRIPTION:set the address of the slave.
 */

#endif /* I2C_INTERFACE_H_ */