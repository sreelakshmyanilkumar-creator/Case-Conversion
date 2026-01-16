//**************************** Case Conversion ********************************* 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File        : ChangeCase.h
// Summary     : To change case of the string as per user input
// Note        : None
// Author      : Sreelakshmy M.A.
// Date        : 15/01/2026
// 
//****************************************************************************** 
 
#ifndef _CHANGE_CASE_H_ 
#define _CHANGE_CASE_H_

//******************************* Include Files ******************************** 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//******************************* Global Types ********************************* 
 
//***************************** Global Constants ******************************* 
typedef enum {
    CHANGE_CASE_LOWER = 1,
    CHANGE_CASE_UPPER,
    CHANGE_CASE_CAMEL
 }CASE_TYPE;
//***************************** Global Variables ******************************* 
 
//**************************** Forward Declarations **************************** 
bool ChangeCase(uint8_t *pucStringName, CASE_TYPE *pucUserChoice);
bool ChangeToLower(uint8_t *pucStringName);
bool ChangeToUpper(uint8_t *pucStringName);
bool ChangeToCamel(uint8_t *pucStringName);

#endif //_CHANGE_CASE_H_
//EOF