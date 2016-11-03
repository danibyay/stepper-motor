/*! **************************
*
* @file: DirectionManager.h
* @author(s): Daniela Becerra, Jesús Martín Barroso
*
************************** */

#ifndef DIRECTION_MANAGER_H
#define DIRECTION_MANAGER_H

/*********************				   Includes					**********************/
#include "types.h"

/*********************				   Defines					**********************/
#define CW 			1 // if 1, go clockwise, if 0, go counterclockwise

/*********************					Function Prototypes					**********************/

/* Enables a one bit register internal pull-up resistors to receive input */
void DirectionManager_Init(void);

/* According to the input (1 or 0) we move the MotorStringManager Clockwise or CounterClockwise */
void DirectionManager_setDirection(bool dir);

bool DirectionManager_getDirection(void);

#endif /* DIRECTION_MANAGER_H */
