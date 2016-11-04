/*! **************************
*
* @file: Main.c
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief
*  Main program of an application that controls a stepper-motor via serial protocol
*  Use an emulator terminal, like tera-term. Enable local echo and set new line characters CR
*  Use the commands described in the message constants to move, turn on/off, change speed, etc. of the motor.
*
************************** */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "MotorManager.h"
#include "TemperatureManager.h"
#include "DelayManager.h"
#include "DirectionManager.h"
#include "TimersManager.h"
#include "types.h"
#include "StringUtilis.h"
#include "MessageManager.h"
#include "Constants.h"

#define DEGREES_HALF_STEP 		375
#define DEFAULT_STEPPER_TIME    52000
#define DEFAULT_TEMP_TIME       5000000  
#define MAX_TEMP_DEFAULT 	    400 
#define MAX_MSG_SIZE            26


u8 tempTimerID;
u16 variableStepperTime;
u8 currMsg[MAX_MSG_SIZE];
bool motorState;
u16 temperatureLimit;
u8 tempMsg[] = "\n   . C\n\r";

void moveMotor(bool dirCW)
{
   if(dirCW)
   {
	   MotorManager_RotateClockwise();
   }
   else
   {
	   MotorManager_RotateCounterClockwise();
   }
}

void tryAgain(void)
{
   if (!MsgManager_TxisBusy())
   {
      MsgManager_SendMessage(k_invalidMsg, k_invalidMsgSize);
   }
}

void sendDone(void)
{	    
   if (!MsgManager_TxisBusy())
   {
      MsgManager_SendMessage(k_msgDone, k_msgDoneSize);
      MsgManager_clearMsg(currMsg);
   }	    
}




void main(void) 
{
	
   u16 systemTemp;
   u8 motorTimerID;
   EnableInterrupts;
	
   TimersMngr_Init(); 
   motorTimerID = DelayManager_Init(DEFAULT_STEPPER_TIME);	
   tempTimerID = DelayManager_Init(DEFAULT_TEMP_TIME);
   DirectionManager_Init(); 
   MotorManager_Init();
   TemperatureManager_Init(); 
   MsgManager_Init();

   variableStepperTime = DEFAULT_STEPPER_TIME;
   motorState = ON;
   temperatureLimit=MAX_TEMP_DEFAULT;

   for(;;) 
   {
      TimersMngr_PeriodicTask();
      TimersMngr_UpdateCount();
      
	  if(TemperatureManager_isDataReady())
	  {
         systemTemp=TemperatureManager_Read();
	  }  
	  
	  // MOVE MOTOR /////////////////////////////////////////////////////////
	  if(TimersMngr_TimerHasElapsed(motorTimerID))
	  {
	     bool tempDir; 
	     tempDir = DirectionManager_getDirection();
	     if(motorState == ON && systemTemp<temperatureLimit)
	   	 {
		    moveMotor(tempDir);
	     }
	     TimersMngr_StartTimer(motorTimerID, variableStepperTime);	
	  }
	    
	  //RECEIVE MESSAGES ///////////////////////////////////////////////////////
	  if(MsgManager_isNewMessageReady())
	  {
         MsgManager_GetMessageReceived(currMsg);
         // TURN OFF OR ON THE MOTOR ////////////////////////////////////
	     if(StringUtils_strcmp(currMsg, k_msgMotor, k_msgMotorSize))
	     {
	        if(StringUtils_strcmp(&currMsg[k_msgMotorSize], k_optMotorOn, k_optMotorOnSize))
	    	{
	    	   motorState = ON;
	    	   sendDone();
	    	}
	    	else if(StringUtils_strcmp(&currMsg[k_msgMotorSize], k_optMotorOff, k_optMotorOffSize))
	    	{
	    	   motorState = OFF;
	       	   sendDone();
	    	}
	    	else
	    	{
	    	   tryAgain();
	    	}
	     }  
	     // CHANGE TEMPERATURE LIMIT ////////////////////////////////////////
	     else if(StringUtils_strcmp(currMsg, k_msgTempLim, k_msgTempLimSize))
		 {
	        u16 tempTempLim;
	        if(StringUtils_Str2Num(&currMsg[k_msgTempLimSize], k_optTempLimSize, k_numAfterDec, &tempTempLim))
	    	{
	    	   temperatureLimit=tempTempLim;
	    	   sendDone();
	    	}
	    	else
	    	{
	       	   tryAgain();
	    	}
	     }  
	     // CHANGE SPEED IN RPS ///////////////////////////////////////////////
	     else if(StringUtils_strcmp(currMsg, k_msgRps, k_msgRpsSize))
		 {
		    u16 tempRps;
		    if(StringUtils_Str2Num(&currMsg[k_msgRpsSize], k_optRpsSize, 1, &tempRps))
		    {
			   variableStepperTime = DelayManager_getTimeUs(tempRps); 
			   sendDone();
		    }
		    else
		    {
		       tryAgain();
		    }
		 }  
	     // CHANGE DIRECTION COMMAND ///////////////////////////////////////////
	     else if(StringUtils_strcmp(currMsg, k_msgDir, k_msgDirSize))
	     {
	        if(StringUtils_strcmp(&currMsg[k_msgDirSize], k_optDirCw, k_optDirCwSize))
	    	{
	    	   DirectionManager_setDirection(k_clockWise); 
	    	   sendDone();
	    	}
	    	else if(StringUtils_strcmp(&currMsg[k_msgDirSize], k_optDirCcw, k_optDirCcwSize))
	    	{
	    	   DirectionManager_setDirection(k_counterClockWise);
	    	   sendDone();
	    	}
	    	else
	    	{
	    	   tryAgain();
	    	}
	     }  
	     else if(motorState==OFF)
	     {
	        //ADVANCE DEGREES CLOCK WISE /////////////////////////
	    	if(StringUtils_strcmp(currMsg, k_msgStep, k_msgStepSize))
	    	{
	    	   u16 tempDeg;
	    	   u32 degrees;
	    	   bool tempDir;
	    	   if(StringUtils_Str2Num(&currMsg[k_msgStepSize], k_optDegreeSize, 0, &tempDeg))
	    	   {
		          degrees = (u32)tempDeg*100 ;
		    	  TimersMngr_StartTimer(motorTimerID, variableStepperTime);
		    	  while(degrees > DEGREES_HALF_STEP)
		    	  {
		    	     __RESET_WATCHDOG();
	    		     TimersMngr_PeriodicTask();
	    		     TimersMngr_UpdateCount();
		    	     if(TimersMngr_TimerHasElapsed(motorTimerID))
		    		 {	    		
		    		    TimersMngr_StartTimer(motorTimerID, variableStepperTime);
		    			tempDir = DirectionManager_getDirection();
		    			moveMotor(tempDir);
		    	    	DirectionManager_setDirection(k_clockWise);	
		    			degrees =degrees-DEGREES_HALF_STEP;
		    		 }  
	    		  }  
		    	  //MsgManager_clearMsg(&degrees); // alomejor no es necesario
		    	  sendDone();
	    	   }      
	    	   else
	    	   {
	    	      tryAgain();
	    	   }
	        }  
	    	// ADVANCE DEGREES COUNTER CLOCK WISE ////////////////////////////////
	    	else if(StringUtils_strcmp(currMsg, k_msgStepCcw, k_msgStepSizeCcw))
	    	{
	    	   u16 tempDeg;
	    	   u32 degrees;
	    	   bool tempDir;
	    	   if(StringUtils_Str2Num(&currMsg[k_msgStepSizeCcw], k_optDegreeSize, 0, &tempDeg))
	    	   {
	    	      degrees = (u32)tempDeg*100 ;
	    		  TimersMngr_StartTimer(motorTimerID, variableStepperTime);
	    	      while(degrees > DEGREES_HALF_STEP)
	    		  {
	    		     __RESET_WATCHDOG();
	    		     TimersMngr_PeriodicTask();
	    			 TimersMngr_UpdateCount();
	    		     if(TimersMngr_TimerHasElapsed(motorTimerID))
	    			 {	    
	    			    TimersMngr_StartTimer(motorTimerID, variableStepperTime);
	    				tempDir = DirectionManager_getDirection();
	    				moveMotor(tempDir);
	    				DirectionManager_setDirection(k_counterClockWise);	
	    				degrees =degrees-DEGREES_HALF_STEP;
	    			 }		    					
	    		  }
	    		  //MsgManager_clearMsg(&degrees); // alomejor no es necesario
	    		  sendDone();
	    	   }   
	    	   else
	    	   {
	    	      tryAgain();
	    	   }
	    	}
	    	// ADVANCE DEGREES ACCORDING TO DISTANCE (motor moves a tire of 30 cm of perimeter) //////////////////////////
	    	/*else if(StringUtils_strcmp(currMsg, k_msgDistance, k_msgDistanceSize))
	    	{
	   	       u16 tempDist; 
	   	       if(StringUtils_Str2Num(&currMsg[k_msgDistanceSize], k_optDistanceSize, k_twoNumAfterDec, &tempDist))
	           {
	              u16 tempDeg; 
	    	   	  u32 degrees;
	    	   	  bool tempDir;
	    	   	  tempDeg = DistanceManager_Dist2Degrees(tempDist);	
	    	   	  degrees = (u32)tempDeg*100 ;
	    	      TimersMngr_StartTimer(motorTimerID, variableStepperTime);
	    	      while(degrees > DEGREES_HALF_STEP)
	    	      {
	    	   	     __RESET_WATCHDOG();
	        	     TimersMngr_PeriodicTask();
	       		     TimersMngr_UpdateCount();
	        		 if(TimersMngr_TimerHasElapsed(motorTimerID))
	        		 {	    		
	        		    TimersMngr_StartTimer(motorTimerID, variableStepperTime);
	        			tempDir = DirectionManager_getDirection();
	        			moveMotor(tempDir);
	        	    	DirectionManager_setDirection(k_clockWise);	
	        			degrees =degrees-DEGREES_HALF_STEP;
	           		 }	
	    	      }
	    		  //MsgManager_clearMsg(&degrees); // alomejor no es necesario
		    	  sendDone();		    			    				    			
	    	   }  
	    	   else
 		       {
	    	      tryAgain();
	           }	    		
	    	}*/
	        else
	    	{
	   		   tryAgain();
	   		}
	    }   
	    else
	    {
	       tryAgain();
	    }

	 }
	     
	 //TEMPERATURE SEND INFO //////////////////////////////////////////////
	 if (TimersMngr_TimerHasElapsed(tempTimerID))
	 {   
        if(!MsgManager_TxisBusy())
		{
	       if (systemTemp>temperatureLimit)
	       {
	          __RESET_WATCHDOG();
	    	  MsgManager_SendMessage(k_overTempDetect, k_overTempDetectsize);
	    	  TimersMngr_StartTimer(tempTimerID, DEFAULT_TEMP_TIME);
	       }
	       else
		   {
		      __RESET_WATCHDOG();
		      StringUtils_Num2Str(systemTemp, tempMsg);
		      MsgManager_SendMessage(tempMsg, 9); //arreglar con una constante el 6
		      TimersMngr_StartTimer(tempTimerID, DEFAULT_TEMP_TIME);
		   }
		}  
	 }
	    
      __RESET_WATCHDOG();	/* feeds the dog */
   } /* loop forever */
}


