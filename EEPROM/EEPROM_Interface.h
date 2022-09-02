/*
 * EEPROM_Interface.h
 *
 * Created: 9/13/2021 11:17:23 AM
 *  Author: Sara Ahmed
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_VoidWrite(u16 u16cpy_address,u8 u8cpy_data);
/*
 * FUNCTION NAME:        EEPROM_VoidWrite
 * FUNCTION RETURN:      nothing(void)
 * FUNCTION ARGUMENTS:   unsigned char (address), unsigned char (data).
 * FUNCTION DESCRIPTION: write the given data in the given address in the EEPROM.
 */

u8 EEPROM_U8Read(u16 u16cpy_address);
/*
 * FUNCTION NAME:        EEPROM_U8Read  
 * FUNCTION RETURN:      data written in the given address.
 * FUNCTION ARGUMENTS:   unsigned char (address).
 * FUNCTION DESCRIPTION: return the data that written in the given address.
 */



#endif /* EEPROM_INTERFACE_H_ */