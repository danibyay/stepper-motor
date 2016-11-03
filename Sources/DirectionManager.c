/*! **************************
*
* @file: DirectionManager.c
* @author(s): Daniela Becerra, Jesús Martín Barroso
*
************************** */

/*********************				   Includes					**********************/
#include "GPIO.h"
#include "DirectionManager.h"
#include "MotorManager.h"
#include "types.h"

/*********************				   Defines					**********************/

bool direction;

/*********************				   Exported Functions					**********************/
void DirectionManager_Init(void)
{
	  direction = CW;
}

//-------------------------------------------------------------------------------------------------
void DirectionManager_setDirection(bool dir)
{
	direction = dir;
}

bool DirectionManager_getDirection(void)
{
	return direction;
}
