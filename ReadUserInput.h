//**************************** Case Conversion *********************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File        : ReadUserInput.h
// Summary     : To read user input such as a string and the type of case 
//               conversion
// Note        : None
// Author      : Sreelakshmy M.A.
// Date        : 15/01/2026
// 
//****************************************************************************** 
 
#ifndef _READ_USER_INPUT_H_ 
#define _READ_USER_INPUT_H_
 
//******************************* Include Files ******************************** 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "ChangeCase.h"

//******************************* Global Types ********************************* 
 
//***************************** Global Constants ******************************* 
#define READ_INPUT_STRING_SIZE (20)
#define TRUE                   (1)
#define FALSE                  (0)
#define SCANF_TRUE             (2)

//***************************** Global Variables ******************************* 
 
//**************************** Forward Declarations **************************** 
bool ReadUserInput(uint8_t *pucStringName, CHANGE_CASE_TYPE *pucUserChoice);

#endif //_READ_USER_INPUT_H_
//EOF