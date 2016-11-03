/*
 * DistanceManager.h
 *
 *  Created on: Nov 1, 2016
 *      Author: Daniela, Jesus
 */

#ifndef DISTANCEMANAGER_H_
#define DISTANCEMANAGER_H_

#include "types.h"

const u16 distanceConstant = 12;


//returns degrees to turn given a speed with a previously set time
u16 DistanceManager_Dist2Degrees(u16 distance);



#endif /* DISTANCEMANAGER_H_ */
