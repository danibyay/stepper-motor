/*
 * DistanceManager.c
 *
 *  Created on: Nov 1, 2016
 *      Author: Daniela, Jesus
* This program convert from distance to degrees
 *      
 */

/*********************						Includes						**********************/

#include "DistanceManager.h"
#include "types.h"


u16 DistanceManager_Dist2Degrees(u16 distance)
{
	u16 tempDeg;
	tempDeg = distance * distanceConstant;
	return tempDeg;
}




