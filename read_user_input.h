//**************************** Case Conversion****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File        : read_user_input.h
// Summary     : To read user input 
// Note        : 
// Author      : Sreelakshmy M A
// Date        : 15/01/2026
// 
//***************************************************************************** 
 
#ifndef _READ_USER_INPUT_H_ 
#define _READ_USER_INPUT_H_
 
//******************************* Include Files ******************************* 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Constants ******************************* 
#define SIZE_OF_INPUT_STRING 20
#define TRUE 0
#define FALSE -1
#define SCANF_TRUE 2

//**************************** Forward Declarations *************************** 
bool ReadUserInput(uint8_t *ucptrStringName,uint8_t *ucptrUserChoice);

#endif // 