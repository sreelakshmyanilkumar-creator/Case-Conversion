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
#include "ChangeCase.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.ReadUserInput.*********************************
//Purpose   : To get the user input like string and conversion type.
//Inputs    : pucStringName - Character Pointer to get the input string from 
//            user
//            pucUserChoice - Interger pointer to get choice of conversion from 
//            user
//Outputs   : pucStringName - updated string after read input from user
//            pucUserChoice - Updated integer after read input from user
//Return    : Boolean value - for both input success return will be 1 else 0
//Notes     : None
//******************************************************************************

bool ReadUserInput(uint8_t *pucStringName, CHANGE_CASE_TYPE *pucUserChoice)
{
    bool blReadInputRet = false;
    size_t ReadStringLength;

    if(pucStringName == NULL || pucUserChoice == NULL)
    {
        printf("Pointer is NULL\n");
    }
    else
    {
        printf("Enter the string to be converted\n");

        if(fgets((char*)pucStringName, READ_INPUT_STRING_SIZE,stdin) != NULL)
        {
            ReadStringLength = strlen((char*)pucStringName); 
        
            if (ReadStringLength > 0 && 
                pucStringName[ReadStringLength-1] == '\n') 
            {
                pucStringName[ReadStringLength-1] = '\0';
            }

            printf("Enter the user choice of conversion\n");

            for(int i = 0 ; i < READ_TOTAL_CASE_HANDLERS; i++)
            {
                printf("%d. %s\n", CaseHandler[i].ChangeCaseType, 
                    CaseHandler[i].ChangeCaseStringName);
            }

            if(scanf("%u", pucUserChoice) != false)
            {
                printf("USER INPUT = %hhd\n", *pucUserChoice);
                blReadInputRet = true;
            }
        }
    }

    return blReadInputRet;
}
//EOF