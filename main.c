//**************************** Case Conversion ********************************* 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
// 
// File        : main.c
// Summary     : Case conversion of a string according to user input
// Note        : None
// Author      : Sreelakshmy M.A.
// Date        : 15/01/2026
// 
//******************************************************************************
 
//******************************* Include Files ********************************
#include <stdlib.h>
#include "ReadUserInput.h"
#include "ChangeCase.h"

//******************************* Local Types ********************************** 
 
//***************************** Local Constants ******************************** 
 #define DEBUG_PRINTS

//***************************** Local Variables ******************************** 
 
//****************************** Local Functions ******************************* 

//******************************.main.****************************************** 
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Interger value - Upon success return will be 0 else any non zero
//Notes   : None
//*
int main()
{
    uint8_t pucStringName[READ_INPUT_STRING_SIZE] = {0};
    CHANGE_CASE_TYPE pucUserChoice = 0;
    bool MainRet = EXIT_SUCCESS;

    if(ReadUserInput(pucStringName, &pucUserChoice) == false)
    {
        printf("Invalid read input from user\n");
        MainRet = EXIT_FAILURE;
    }
    else
    {
        #ifdef DEBUG_PRINTS
        printf("%s\n", pucStringName);
        printf("%d\n", pucUserChoice);
        #endif

        if(ChangeCase(pucStringName, &pucUserChoice) != true)
        {
            printf("Invalid case conversion\n");
            MainRet = EXIT_FAILURE;
        }
        else
        {
            #ifdef DEBUG_PRINTS
            printf("%s\n", pucStringName);
            #endif
        }
    }

    return MainRet;
}
// EOF 