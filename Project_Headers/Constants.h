/*
 * Constants.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Daniela Becerra, Jesus Martin.
 *      Brief: File where the applications constants are, mostly strings of characters and their respective sizes.
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

extern const bool k_clockWise = 1;
extern const bool k_counterClockWise = 0;
extern const u8 k_msgDistanceSize = 5;
extern const u8 k_msgTempLim[] = "TEMP-LIMIT:";
extern const u8 k_msgTempLimSize = 11;
extern const u8 k_optTempLimSize = 5;
extern const u8 k_numAfterDec = 1;
extern const u8 k_optRpsSize = 5;
extern const u8 k_optDegreeSize = 3;
extern const u8 k_optDirCw[] = "CW\r";
extern const u8 k_optDirCcw[] = "CCW\r";
extern const u8 k_optDirCwSize = 2;
extern const u8 k_optDirCcwSize = 3;
extern const u8 k_optMotorOff[] = "Off\r";
extern const u8 k_optMotorOn[] = "On\r";
extern const u8 k_optMotorOnSize = 2;
extern const u8 k_optMotorOffSize = 3;
extern const u8 k_msgMotorSize = 6;
extern const u8 k_msgRpsSize = 4;
extern const u8 k_msgDirSize = 4;
extern const u8 k_msgStepSize = 8;
extern const u8 k_msgStepSizeCcw = 9;
extern const u8 k_msgDoneSize = 7;
extern const u8 k_invalidMsgSize = 12;
extern const u8 k_msgMotor[] = "MOTOR:";
extern const u8 k_msgRps[] = "RPS:";
extern const u8 k_msgDir[] = "DIR:";
extern const u8 k_msgStep[] = "STEP-CW:";
extern const u8 k_msgStepCcw[] = "STEP-CCW:";
extern const u8 k_msgDone[] = "\nDone\n\r";
extern const u8 k_invalidMsg[] = "\nTry again\n\r";
extern const u8 k_overTempDetect[]="OverTempeture Detected\n\r";
extern const u8 k_overTempDetectsize=24;
extern const u8 k_msgDistance[] = "DIST:";
extern const u8 k_optDistanceSize = 4;
extern const u8 k_twoNumAfterDec = 2;


#endif /* CONSTANTS_H_ */
