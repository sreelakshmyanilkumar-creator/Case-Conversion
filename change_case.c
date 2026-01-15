//**************************** Case Conversion****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File        : change_case.c
// Summary     : To change case of the string as per user input
// Note        : 
// Author      : Sreelakshmy M A
// Date        : 15/01/2026
// 
//***************************************************************************** 

//******************************* Include Files ******************************* 
 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
 #include "change_case.h"
 #include "read_user_input.h"


 //******************************.ChangeToLower.****************************************** 
//Purpose : To convert to lower case.
//Inputs  : ucptrStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return 0 & for any failure return -1
//Notes   :  
//*
bool ChangeToLower(uint8_t *ucptrStringName)
{
    if(ucptrStringName == NULL)
    {
        return FALSE;
    }
    
    while (*ucptrStringName)
    {
        if(*ucptrStringName >= 'A' && *ucptrStringName <= 'Z') 
        {
            *ucptrStringName = *ucptrStringName + ('a' - 'A');
        }
        ucptrStringName++;
    }
}

 //******************************.ChangeToUpper.****************************************** 
//Purpose : To convert to upper case.
//Inputs  : ucptrStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return 0 & for any failure return -1
//Notes   :  
//*
bool ChangeToUpper(uint8_t *ucptrStringName)
{
    if(ucptrStringName == NULL)
    {
        return FALSE;
    }
    
    while (*ucptrStringName)
    {
        if(*ucptrStringName >= 'a' && *ucptrStringName <= 'z') 
        {
            *ucptrStringName = *ucptrStringName - ('a' - 'A');
        }
        ucptrStringName++;
    }
}

 //******************************.ChangeToCamel.****************************************** 
//Purpose : To convert to camel case.
//Inputs  : ucptrStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return 0 & for any failure return -1
//Notes   :  
//*
bool ChangeToCamel(uint8_t *ucptrStringName)
{
    uint8_t NewWord = 1;

    if(ucptrStringName == NULL)
    {
        return FALSE;
    }

    while(*ucptrStringName)
    {
        if(*ucptrStringName == ' ')
        {
            NewWord = 1;
        }
        else
        {
            if(NewWord)
            {
                if(*ucptrStringName >= 'a' && *ucptrStringName <= 'z')
                { 
                    *ucptrStringName = *ucptrStringName - ('a' - 'A');
                } 
                NewWord = 0;
            }
            else
            {
                if(*ucptrStringName >= 'A' && *ucptrStringName <= 'Z')
                {
                    *ucptrStringName = *ucptrStringName + ('a' - 'A');
                }
            }

        }

        ucptrStringName++;  
    }

    return TRUE;
}


 
 //******************************.ChangeCase.****************************************** 
//Purpose : To change the case conversion.
//Inputs  : ucptrStringName - Character Pointer to get the input string from user
//          ucptrUserChoice - Interger pointer to get choice from user
//Return  : Boolean value - for both input success return 0 & for any failure return -1
//Notes   :  
//*
bool ChangeCase(uint8_t *ucptrStringName,uint8_t *ucptrUserChoice)
{
    switch(*ucptrUserChoice)
    {
        case 1:
                if(ChangeToLower(ucptrStringName) != TRUE)
                {
                    return FALSE;
                }
                break;
        case 2:
                if(ChangeToUpper(ucptrStringName) != TRUE)
                {
                    return FALSE;
                }
                break;
        case 3:
                if(ChangeToCamel(ucptrStringName) != TRUE)
                {
                    return FALSE;
                }
                break;
        default:
                printf("Invalid user choice\n");
                break;
    }
    return 0;

}