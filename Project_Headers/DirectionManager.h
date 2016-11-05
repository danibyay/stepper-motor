/*! **************************
*
* @file: DirectionManager.h
* @author(s): Daniela Becerra, Jesús Martín Barroso
* @brief: allows giving an initial direction to the motor, setting and getting the attribute
*
************************** */

#ifndef DIRECTION_MANAGER_H
#define DIRECTION_MANAGER_H

/*********************				   Includes					**********************/
#include "types.h"

/*********************				   Defines					**********************/
#define CW 			1 // if 1, go clockwise, if 0, go counterclockwise

/*********************					Function Prototypes					**********************/

/*!*-----------------------------------------------------------------------------------------------
* \name     DirectionManager_Init
* \brief    Sets a default direction, as clockwise
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void DirectionManager_Init(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     DirectionManager_Init
* \brief    changes the local attribute of direction
* \param    bool dir, the direction of the motor, Clockwise or counterClockwise
* \return   void
-------------------------------------------------------------------------------------------------*/
void DirectionManager_setDirection(bool dir);

/*!*-----------------------------------------------------------------------------------------------
* \name     DirectionManager_Init
* \brief    returns the local attribute of direction
* \param    void
* \return   bool dir, the direction of the motor, Clockwise or counterClockwise
-------------------------------------------------------------------------------------------------*/
bool DirectionManager_getDirection(void);

#endif /* DIRECTION_MANAGER_H */
