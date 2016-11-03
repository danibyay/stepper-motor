/*
 * StringUtilis.h
 *
 *  Created on: Oct 30, 2016
 *      Author: Jesus
 */

#ifndef STRINGUTILIS_H_
#define STRINGUTILIS_H_
#include"types.h"

void StringUtils_setSize(u8 sizeParameter);

bool StringUtils_Str2Num(u8 str[], u8 strSize, u8 decimal, u16* num);

void StringUtils_Num2Str(u16 num, u8 string[]);

bool StringUtils_strcmp(u8 * msg,  const u8 ref[], u8 size);

#endif /* STRINGUTILIS_H_ */
