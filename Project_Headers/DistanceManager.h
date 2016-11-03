/*
 * DistanceManager.h
 *
 *  Created on: Nov 1, 2016
 *      Author: Daniela, Jesus
 */

#ifndef DISTANCEMANAGER_H_
#define DISTANCEMANAGER_H_

#include "types.h"

#define DEFAULT_TIME 	10  //seconds
//valid distance from 6 to 1560 centimeters. if given differently, anyways, the RPS are bounded.
//valid time from 1 to 10 seconds
u8 time;
const u16 circumference = 300;

void DistanceManager_Init(void);

//returns Rps (revolutions per second) given a speed with a previously set time
u16 DistanceManager_Distance2Rps(u16 distance);

//set the time
void DistanceManager_setTime(u8 time_param);


#endif /* DISTANCEMANAGER_H_ */
