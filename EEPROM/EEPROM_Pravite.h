/*
 * EEPROM_Pravite.h
 *
 * Created: 9/13/2021 11:17:55 AM
 *  Author: Sara Ahmed
 */ 


#ifndef EEPROM_PRAVITE_H_
#define EEPROM_PRAVITE_H_

#define  NUM1  0
#define  NUM2  1
#define  NUM3  2
#define  NUM4  3

#define EEARL     *((volatile u8*)(0x3E))
#define EEARH     *((volatile u8*)(0x3F))
#define EEAR      *((volatile u16*)(0x3E))
#define EEDR      *((volatile u8*)(0x3D))
#define EECR      *((volatile u8*)(0x3C))

#endif /* EEPROM_PRAVITE_H_ */