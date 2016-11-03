/*
 * DistanceManager.c
 *
 *  Created on: Nov 1, 2016
 *      Author: Daniela, Jesus
 */

#include "DistanceManager.h"
#include "types.h"

void DistanceManager_Init(void)
{
	time = DEFAULT_TIME;
}

//returns Rps (revolutions per second) given a speed with a previously set time
u16 DistanceManager_Distance2Rps(u16 distance)
{
	u16 b;
	
	u32 a = (circumference*time);
	distance = (distance*10);
	b = distance/a;
	return b;
}

//set the time
void DistanceManager_setTime(u8 time_param)
{
	
}



