//**************************** Case Conversion******************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File        : read_user_input.c
// Summary     : To read user input
// Note        : 
// Author      : Sreelakshmy M A
// Date        : 15/01/2026
// 
//***************************************************************************** 
 

//******************************* Include Files ******************************* 
 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
 #include "read_user_input.h"


 //******************************.ReadUserInput.****************************************** 
//Purpose : To get the user input to for selecting conversion type.
//Inputs  : ucptrStringName - Character Pointer to get the input string from user
//          ucptrUserChoice - Interger pointer to get choice from user
//Return  : Boolean value - for both input success return 0 & for any failure return -1
//Notes   :  
//******************************************************************************************

bool ReadUserInput(uint8_t *ucptrStringName,uint8_t *ucptrUserChoice)
{
    printf("Enter the string to be converted\n");
    if(fgets((char*)ucptrStringName, SIZE_OF_INPUT_STRING,stdin) == NULL)
    {
        return FALSE;
    }

    printf("Enter the user choice of conversion\n");
    printf("1. To Lower Case\n");
    printf("2. To Upper Case\n");
    printf("3. To Camel Case\n");

    if(scanf("%hhd",ucptrUserChoice) != SCANF_TRUE)
    {
        printf("USER INPUT = %hhd\n",*ucptrUserChoice);
        return FALSE;
    }
    return TRUE;
}