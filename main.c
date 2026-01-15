//**************************** Case Conversion****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File        : main.c
// Summary     : Case conversion of a string according to user input
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
 #include "change_case.h"
 
//***************************** Global Variables ******************************* 
uint8_t ucStringName[20];
uint8_t ucUserChoice;


//***************************** Local types ******************************* 
#define DEBUG_PRINTS


int main()
{
    if(ReadUserInput(ucStringName,&ucUserChoice) == FALSE)
    {
        printf("Invalid read input from user\n");
    }
    else
    {
        #ifdef DEBUG_PRINTS
        printf("%s\n",ucStringName);
        printf("%d\n",ucUserChoice);
        #endif

        if(ChangeCase(ucStringName,&ucUserChoice) != TRUE)
        {
            printf("Invalid case conversion\n");
        }
        else
        {
            #ifdef DEBUG_PRINTS
            printf("%s\n",ucStringName);
            #endif
        }
    }

    return 0;
}


// EOF 