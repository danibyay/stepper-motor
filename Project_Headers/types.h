/*! **********************************************************************************************
* 2015  ITESM Campus Guadalajara. Laboratorio de Microcontroladores 
* @file:      types.h
* @author(s): Mauricio Capistrán
* @brief (User's Manual)
**************************************************************************************************/
#ifndef TYPES_H_
#define TYPES_H_
/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define M_TRUE	(1)
#define M_FALSE	(0)
#define M_NULL (0)
#define ON	(1)
#define OFF (0)

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/
typedef unsigned char  u8;
typedef signed   char  i8;
typedef unsigned int  u16;
typedef signed   int  i16;
typedef unsigned long u32;
typedef signed long i32; 
typedef unsigned char bool;

typedef void (*ISR_callback)(void); /*ISR function data type */
typedef void (*pFunc_t)(void);      /* generic function pointer data type */

#endif /* TYPES_H_ */
