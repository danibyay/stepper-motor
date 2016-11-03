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

const bool k_clockWise = 1;
const bool k_counterClockWise = 0;
const u8 k_msgDistanceSize = 5;
const u8 k_msgTempLim[] = "TEMP-LIMIT:";
const u8 k_msgTempLimSize = 11;
const u8 optTempLimSize = 5;
const u8 numAfterDec=1;
const u8 optRpsSize = 5;
const u8 optDegreeSize = 3;
const u8 optDirCw[] = "CW\r";
const u8 optDirCcw[] = "CCW\r";
const u8 optDirCwSize = 2;
const u8 optDirCcwSize = 3;
const u8 optMotorOff[] = "Off\r";
const u8 optMotorOn[] = "On\r";
const u8 optMotorOnSize = 2;
const u8 optMotorOffSize = 3;
const u8 msgMotorSize = 6;
const u8 msgRpsSize = 4;
const u8 msgDirSize = 4;
const u8 msgStepSize = 8;
const u8 msgStepSizeCcw = 9;
const u8 msgProfSaveSize = 9;
const u8 msgProfUseSize = 8;
const u8 msgDoneSize = 7;
const u8 invalidMsgSize = 12;
const u8 msgMotor[] = "MOTOR:";
const u8 msgRps[] = "RPS:";
const u8 msgDir[] = "DIR:";
const u8 msgStep[] = "STEP-CW:";
const u8 msgStepCcw[] = "STEP-CCW:";
const u8 msgProfSave[] = "PROF_SAVE:"; //:n
const u8 msgProfUse[] = "PROF_USE:"; //:n
const u8 msgDone[] = "\nDone\n\r";
const u8 invalidMsg[] = "\nTry again\n\r";
const u8 overTempDetect[]="OverTempeture Detected\n\r";
const u8 overTempDetectsize=24;
const u8 msgDistance[] = "DIST:";
const u8 optDistanceSize = 4;
const u8 twoNumAfterDec = 2;

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
		MsgManager_SendMessage(invalidMsg, invalidMsgSize);
	}
}

void sendDone(void)
{	    
   if (!MsgManager_TxisBusy())
   {
      MsgManager_SendMessage(msgDone, msgDoneSize);
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

	
	for(;;) {
	    TimersMngr_PeriodicTask();
	    TimersMngr_UpdateCount();
	    
	    if(TemperatureManager_isDataReady())
	    {
		    systemTemp=TemperatureManager_Read();
	    }
	    
	    // MOTOR
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
	    
	    //RECEIVE MESSAGE
	    if(MsgManager_isNewMessageReady())
	    {
	    	MsgManager_GetMessageReceived(currMsg);
	    	if(StringUtils_strcmp(currMsg, msgMotor, msgMotorSize))
	    	{
	    		if(StringUtils_strcmp(&currMsg[msgMotorSize], optMotorOn, optMotorOnSize))
	    		{
	    			motorState = ON;
	    			sendDone();
	    		}
	    		else if(StringUtils_strcmp(&currMsg[msgMotorSize], optMotorOff, optMotorOffSize))
	    		{
	    			motorState = OFF;
	    			sendDone();
	    		}
	    		else
	    		{
	    			tryAgain();
	    		}
	    	}
	    	/*else if(StringUtils_strcmp(currMsg, msgDistance, k_msgDistanceSize))
	    	{
	    		u16 tempDist;
	    		u16 a;
	    		u16 b;
	    		//5 characters , 2 numbers after decimal point
	    		if(StringUtils_Str2Num(&currMsg[k_msgDistanceSize], 4, 1, &tempDist))
	    		{
	    			__RESET_WATCHDOG();	
	    			a=DistanceManager_Distance2Rps(tempDist);
	    			b=DelayManager_getTimeUs(b);
	    			
	    		}
	    		else
	    		{
	    		    tryAgain();
	    		}
	    		
	    	}*/
	    	else if(StringUtils_strcmp(currMsg, k_msgTempLim, k_msgTempLimSize))
		   	{
	      		u16 tempTempLim;
	    		if(StringUtils_Str2Num(&currMsg[k_msgTempLimSize], optTempLimSize, numAfterDec, &tempTempLim))
	    		{
	    			temperatureLimit=tempTempLim;
	    		   	sendDone();
	    		    			
	    		}
	    		else
	    		{
	    		  	tryAgain();
	    		}
	    	}
	    	//RPS COMMAND
	    	else if(StringUtils_strcmp(currMsg, msgRps, msgRpsSize))
		    {
		    	u16 tempRps;
		    	if(StringUtils_Str2Num(&currMsg[msgRpsSize], optRpsSize, 1, &tempRps))
		    	{
					variableStepperTime = DelayManager_getTimeUs(tempRps); 
					sendDone();
		    	}
		    	else
		    	{
		    		tryAgain();
		    	}
		    }
	    	//DIRECTION COMMAND
	    	else if(StringUtils_strcmp(currMsg, msgDir, msgDirSize))
	    	{
	    		if(StringUtils_strcmp(&currMsg[msgDirSize], optDirCw, optDirCwSize))
	    		{
	    			DirectionManager_setDirection(k_clockWise); 
	    			sendDone();
	    		}
	    		else if(StringUtils_strcmp(&currMsg[msgDirSize], optDirCcw, optDirCcwSize))
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
	    		//DEGREES COMMAND CLOCK WISE
	    		if(StringUtils_strcmp(currMsg, msgStep, msgStepSize))
	    		{
	    			u16 tempDeg;
	    			u32 degrees;
	    			bool tempDir;
	    			if(StringUtils_Str2Num(&currMsg[msgStepSize], optDegreeSize, 0, &tempDeg))
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
	    		//DEGREES COMMAND COUNTER CLOCK WISE
	    		else if(StringUtils_strcmp(currMsg, msgStepCcw, msgStepSizeCcw))
	    		{
	    			u16 tempDeg;
	    			u32 degrees;
	    			bool tempDir;
	    			if(StringUtils_Str2Num(&currMsg[msgStepSizeCcw], optDegreeSize, 0, &tempDeg))
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
	    
	    
	    //TEMPERATURE SEND
	    if (TimersMngr_TimerHasElapsed(tempTimerID))
	    {
	    

		    if(!MsgManager_TxisBusy())
		    {
	    		if (systemTemp>temperatureLimit)
	    		{
	    			__RESET_WATCHDOG();
	    			MsgManager_SendMessage(overTempDetect, overTempDetectsize);
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


