//**************************** Case Conversion *********************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File        : ReadUserInput.c
// Summary     : To read user input such as a string and the type of case 
//               conversion
// Note        : None
// Author      : Sreelakshmy M.A.
// Date        : 15/01/2026
// 
//****************************************************************************** 
 
//******************************* Include Files ******************************** 
 #include "ReadUserInput.h"

//******************************.ReadUserInput.*********************************
//Purpose : To get the user input like string and conversion type.
//Inputs  : pucStringName - Character Pointer to get the input string from 
//          user
//          pucUserChoice - Interger pointer to get choice of conversion from 
//          user
//Return  : Boolean value - for both input success return will be 1 else 0
//Notes   : None
//******************************************************************************

bool ReadUserInput(uint8_t *pucStringName, CASE_TYPE *pucUserChoice)
{
    if(pucStringName == NULL || pucUserChoice == NULL)
    {
        printf("Pointer is NULL\n");
        return false;
    }
    else
    {
        printf("Enter the string to be converted\n");

        if(fgets((char*)pucStringName, READ_INPUT_STRING_SIZE,stdin) == NULL)
        {
            return false;
        }

        printf("Enter the user choice of conversion\n");
        printf("1. To Lower Case\n");
        printf("2. To Upper Case\n");
        printf("3. To Camel Case\n");

        if(scanf("%u", pucUserChoice) != true)
        {
            printf("USER INPUTT = %hhd\n", *pucUserChoice);
            return false;
        }
    }

    return true;
}
//EOF