/* ! **************
* @file: DelayManager.h
* @author(s): Daniela Becerra, Jesús Barroso
*
*
***************** */

#ifndef DELAY_H
#define DELAY_H

/*********************						Includes						**********************/
#include "types.h"

/*********************						Defines							**********************/
#define MAX_SPEED 2000 //2 miliseconds
#define MIN_SPEED 52000 //52 milliseconds to have 0.2 rpm
#define SCALE 10000000  //multiplier for the calculation
#define STEPS 96 //steps necessary for the motor to do a 360 degree turn
/*********************					Function Prototypes					**********************/

/*!*-----------------------------------------------------------------------------------------------
* \name     DelayManager_Init
* \brief    Initalizes the MTIM module with the right modulo, interrupt configuration and clock source
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
u8 DelayManager_Init(u32 time);

//calculation of the time in microseconds for the software timers, starting from a number that represents 
//revolutions per second including one decimal, multiplied by 10
u16 DelayManager_getTimeUs(u16 rps);


#endif /* DELAY_H */
