/* ! **************
* @file: ADCManager.h
* @author(s): Daniela Becerra, Jesús Barroso
*
* @brief (User's Manual)
* This manager controls how we are using the ADC Module(Register, Operation mode, Number of Channel)
*
* You can change between channels
*
***************** */
#ifndef ADC
#define ADC
/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/
#include "types.h"
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define ADC_ANALOGIC_INPUT   1
#define REG_CONFIG           0x20 //0b00100000 no interruptions, continous conversion and channel zero

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/
/*!*-----------------------------------------------------------------------------------------------
* \name     ADC_Init
* \brief    Initalizes the ADC module used for the ADC manager.
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void ADC_Init(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     ADC_Read
* \brief    Reads ADCRL 
* \param    void
* \return   u8 returns the last read Data of ADC in ADC register low
-------------------------------------------------------------------------------------------------*/
u8 ADC_Read(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     ADC_Read
* \brief    Checks if the last conversion of the ADC is complete (COCO)
* \param    void
* \return   bool, true if data is ready, false, otherwise
-------------------------------------------------------------------------------------------------*/
bool ADC_isDataReady(void);


#endif /* ADC */
