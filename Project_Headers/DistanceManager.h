/*
 * DistanceManager.h
 *
 *  Created on: Nov 1, 2016
 *      Author: Daniela Becerra , Jesus Barroso
 *      Brief: Gives a way to make the calculation for another command, distance.
 */

#ifndef DISTANCEMANAGER_H_
#define DISTANCEMANAGER_H_

#include "types.h"

const u16 distanceConstant = 12;

/*!*-----------------------------------------------------------------------------------------------
* \name     DistanceManager_Dist2Degrees
* \brief    Returns degrees to turn given a speed with a previously set time
* \param    distance, the distance that the motor will make a tire advance
* \return   degrees, the necessary degrees to move the motor such distance
-------------------------------------------------------------------------------------------------*/
u16 DistanceManager_Dist2Degrees(u16 distance);



#endif /* DISTANCEMANAGER_H_ */
