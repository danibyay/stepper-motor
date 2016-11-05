/*! **************************
*
* @file: Temperature_Manager.c
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief
*     HIL layer above the ADC, We will read temperature from the microcontroller and display the degrees read
*
************************** */

/*********************						Includes						**********************/
#include "TemperatureManager.h"
#include "ADCMANAGER.h"
#include "types.h"
#include "derivative.h" /* include peripheral declarations */

/*********************				  Defines								**********************/
/*********************				   Exported Functions					******************x	****/


void TemperatureManager_Init(void)
{
	ADC_Init();
}
//-------------------------------------------------------------------------------------------------
bool TemperatureManager_isDataReady(void)
{
	return ADC_isDataReady();
}

u16 TemperatureManager_Read(void)
{
	u16 temp;
	temp=((u16)ADC_Read()*13);
	//return(u16)((((u32)ADC_Read()*MAX_SENSOR_VOLTAGE)/MAX_ADC_READ)+SENSOR_OFFSET);
	return 	temp;

}
