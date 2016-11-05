/* ! **************
* @file: DelayManager.h
* @author(s): Daniela Becerra, Jesús Barroso
* @Brief: Header file that defines the implementation of TimersManager.
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
* \brief    Creates and starts a timer.
* \param    u32 time in microseconds that will trigger the timer.
* \return   u8 id of the timer created.
-------------------------------------------------------------------------------------------------*/
u8 DelayManager_Init(u32 time);



/*!*-----------------------------------------------------------------------------------------------
* \name     DelayManager_getTimeUs 
* \brief    calculation of the time in microseconds for the software timers to be triggered, starting from a number that represents
*           revolutions per second including one decimal, multiplied by 10
* \param    u16 rps speed in revolutions per seconds that the motor has to perform
* \return   u16 time in microseconds that will trigger the timer and consequently the movement of a step of the motor
-------------------------------------------------------------------------------------------------*/
u16 DelayManager_getTimeUs(u16 rps);


#endif /* DELAY_H */
