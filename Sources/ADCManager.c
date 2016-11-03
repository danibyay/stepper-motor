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
#include "ADCManager.h"
#include "types.h"
#include "derivative.h" /* include peripheral declarations */

/*********************				  Defines								**********************/

/*********************				   Exported Functions					**********************/
void ADC_Init(void)
{
  APCTL1_ADPC0 = ADC_ANALOGIC_INPUT;
  ADCSC1 = REG_CONFIG;
}
//-------------------------------------------------------------------------------------------------
bool ADC_isDataReady(void)
{
   if(ADCSC1_COCO)
   {
      return M_TRUE;	   
   }
   else
   {
	   return M_FALSE;
   }
}

u8 ADC_Read(void)
{
   return ADCRL; 
}


//-------------------------------------------------------------------------------------------------

