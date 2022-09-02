/*
 * WDT_Interface.h
 *
 * Created: 2/26/2022 6:02:58 PM
 *  Author: Sara Ahmed 
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

void WDT_Void_Enable(void);
/*
Function Name        : WDT_Void_Enable
Function Returns     : void
Function Arguments   : void
Function Description : enable the watch dog timer.
*/

void WDT_Void_Disable(void);
/*
Function Name        : WDT_Void_Disable
Function Returns     : void
Function Arguments   : void
Function Description : disable the watch dog timer.
*/
#endif /* WDT_INTERFACE_H_ */