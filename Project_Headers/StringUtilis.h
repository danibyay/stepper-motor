/*
 * StringUtilis.h
 *
 *  Created on: Oct 30, 2016
 *      Author: Jesus
 */

#ifndef STRINGUTILIS_H_
#define STRINGUTILIS_H_

#include"types.h"


/*!*-----------------------------------------------------------------------------------------------
* \name     StringUtils_Str2Num
* \brief    given a string that holds a decimal number, get the raw integer number
* \param    u8 string to convert, u8 size of the string, u8 numbers after decimal point, u16 pointer where to save the conversion
* \return   bool, true if conversion was successful
-------------------------------------------------------------------------------------------------*/
bool StringUtils_Str2Num(u8 str[], u8 strSize, u8 decimal, u16* num);

/*!*-----------------------------------------------------------------------------------------------
* \name     StringUtils_Num2Str
* \brief    Given a number, turn it into a string of characters
* \param    void
* \return   u16 num, u8 * the string of characters that results
-------------------------------------------------------------------------------------------------*/
void StringUtils_Num2Str(u16 num, u8 string[]);

/*!*-----------------------------------------------------------------------------------------------
* \name     StringUtils_strcmp
* \brief    Reads ADCRL register when COCO FLAG is on
* \param    msg to be compared, reference to be compared with, size of the string that we want to see if it is equal
* \return   bool, if the two strings were equal
-------------------------------------------------------------------------------------------------*/
bool StringUtils_strcmp(u8 * msg,  const u8 ref[], u8 size);

#endif /* STRINGUTILIS_H_ */
