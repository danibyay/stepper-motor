/*! **************************
*
* @file: ADC_Manager.c
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief
*Includes two basic functions of the ADC
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
