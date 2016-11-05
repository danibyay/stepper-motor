/* ! **************
* @file: TemperatureManager.h
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief (User's Manual)
* HIL layer above the ADC . We will read temperature and display the degrees read in Celsius
*
***************** */

#ifndef TEMPERATURE_MANAGER_H_
#define TEMPERATURE_MANAGER_H_
/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/

#define MAX_SENSOR_VOLTAGE 3300
#define MAX_ADC_READ 255
#define SENSOR_OFFSET 20
/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
void TemperatureManager_Init(void);
/*!*-----------------------------------------------------------------------------------------------
* \name     TemperatureManager_Init
* \brief    Initalizes the ADC module
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/

/*!*-----------------------------------------------------------------------------------------------
* \name     TemperatureManager_isDataReady
* \brief    Verifies if the conversion of data is ready to be read
* \param    void
* \return   bool
-------------------------------------------------------------------------------------------------*/
bool TemperatureManager_isDataReady(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     TemperatureManager_Read
* \brief    Reads the latest conversion of analog to digital temperature
* \param    void
* \return   u16 temperature
-------------------------------------------------------------------------------------------------*/
u16 TemperatureManager_Read(void);


#endif 
