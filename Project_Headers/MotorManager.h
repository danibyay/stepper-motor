
/* ! **************
* @file: MotorManager.h
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief (User's Manual)
* This manager controls which bits in a String are
* on or off in order for a stepper motor to start working
*
* You can rotate ClockWise or Counter ClockWise
*
***************** */

#ifndef MOTOR_H_
#define MOTOR_H_

/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

#define MOTOR_PORT				B	/* Specify the digital port where the LED string is connected */
#define MOTOR_PIN_START		2   /* Specify the starting pin on the digital port where teh LED String is connected */
#define MOTOR_NUMBER_OF_PINS 4 /* How many pins will be used for this string */

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/

/*!*-----------------------------------------------------------------------------------------------
* \name     MotorManager_Init
* \brief    Initalizes the GPIO pins used for the Motor String and it sets it to the initial condition
*           which is 0x08
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void MotorManager_Init(void);


/*!*-----------------------------------------------------------------------------------------------
* \name     MotorManager_RotateClockwise
* \brief    Sets the appropriate sequence for the motor to rotate ClockWise
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void MotorManager_RotateClockwise(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     MotorManager_RotateCounterClockwise
* \brief    Sets the appropriate sequence for the motor to rotate Counter ClockWise
*           yellow - black - brown - green is the necessary sequence of wires in the motor 
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void MotorManager_RotateCounterClockwise(void);


#endif /* MOTOR_H_ */
