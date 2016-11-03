/*! **************************
*
* @file: Motor_Manager.c
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief
* 8 sequences of 8 bits, with the 4 least significant are the ones that
* determine the movement of a step motor with a half step sequences
* These 8 sequences are located in an array, and by traversing it
* in one way or another, the motor will turn on.
*
************************** */

/*********************						Includes						**********************/
#include "GPIO.h"
#include "MotorManager.h"

/*********************						Defines							**********************/

//sequences of 4 BITS alternating to run a step motor
#define S0 		0x20
#define S1 		0x30
#define S2 		0x10
#define S3 		0x18
#define S4 		0x08
#define S5 		0x0C
#define S6 		0x04
#define S7 		0x24
#define BITS 8
#define MAX_BIT 7
#define MIN_BIT 0

/*********************						Typedefs						**********************/

/*********************					Function Prototypes					**********************/

/*********************                  Static Variables                    **********************/
const u8 half_step_sequence[] = {S0, S1, S2, S3, S4, S5, S6, S7};
u8 u8current_sequence; //the current value on the port
/*************************************************************************************************/
u8 s_index = 0; //sequence index
/*********************                  Static Constants                    **********************/

/*********************                  Global Constants                    **********************/


/*********************				   Exported Functions					**********************/

void MotorManager_Init(void)
{
	u8current_sequence = half_step_sequence[s_index];
	GPIO_CONFIG_PORT_OUT(B,2,5);
	GPIO_WRITE_PORT(MOTOR_PORT, u8current_sequence);
	GPIO_CONFIG_PORT_OUT(MOTOR_PORT, MOTOR_PIN_START, MOTOR_NUMBER_OF_PINS);
}

//-------------------------------------------------------------------------------------------------
void MotorManager_RotateCounterClockwise(void)
{
  s_index++;
  u8current_sequence = half_step_sequence[s_index % BITS];
  GPIO_WRITE_PORT(MOTOR_PORT, u8current_sequence);
}

//-------------------------------------------------------------------------------------------------
void MotorManager_RotateClockwise(void)
{
  s_index--;
  u8current_sequence = half_step_sequence[s_index % BITS];
  GPIO_WRITE_PORT(MOTOR_PORT, u8current_sequence);
}
