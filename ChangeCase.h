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
//#include "ReadUserInput.h"

//***************************** Global Constants *******************************
typedef enum {
    CHANGE_CASE_LOWER = 1,
    CHANGE_CASE_UPPER,
    CHANGE_CASE_CAMEL,
    CHANGE_CASE_HEX
 }CHANGE_CASE_TYPE;

 #define READ_INPUT_STRING_SIZE     (20)
 #define READ_TOTAL_CASE_HANDLERS   (4) 

//******************************* Global Types *********************************
typedef struct _CHANGE_CASE_HANDLER_
{
    CHANGE_CASE_TYPE ChangeCaseType;
    uint8_t ChangeCaseStringName[READ_INPUT_STRING_SIZE];
    bool (*func) (uint8_t *pucStringName);
}CHANGE_CASE_HANDLER;

//***************************** Global Variables *******************************
extern const CHANGE_CASE_HANDLER CaseHandler[];

//**************************** Forward Declarations ****************************
bool ChangeCase(uint8_t *pucStringName, CHANGE_CASE_TYPE *pucUserChoice);

#endif //_CHANGE_CASE_H_
//EOF