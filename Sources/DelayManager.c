/* ! **************
* @file: DelayManager.c
* @author(s): Daniela Becerra, Jesús Barroso
*
*
***************** */
//Includes a function to initialize a timer, and a function to calculate delays in microseconds
/*********************						Includes						**********************/
#include "DelayManager.h"
#include "types.h"
#include "TimersManager.h"


/*********************						Variables							**********************/

/*********************				   Exported Functions					**********************/
u8 DelayManager_Init(u32 time)
{
	u8 id = TimersMngr_CreateTimer(M_NULL);
	TimersMngr_StartTimer(id, time);
	return id;
}
//-------------------------------------------------------------------------------------------------
u16 DelayManager_getTimeUs(u16 rps)
{
   u16 time =(u16) (SCALE/((u32)STEPS * rps));
   if(time > MIN_SPEED)
   {
      return MIN_SPEED;
   }
   else if(time < MAX_SPEED)
   {
      return MAX_SPEED;
   }
   return time;
}
