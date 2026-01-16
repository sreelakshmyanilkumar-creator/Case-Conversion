//**************************** Case Conversion *********************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
// 
// File        : ChangeCase.c
// Summary     : To change case of the string as per user input
// Note        : None
// Author      : Sreelakshmy M.A.
// Date        : 15/01/2026
// 
//****************************************************************************** 

//******************************* Include Files ********************************
 #include "ChangeCase.h"
 #include "ReadUserInput.h"

//******************************* Local Types ********************************** 
 
//***************************** Local Constants ******************************** 

//***************************** Local Variables ******************************** 
 
//****************************** Local Functions ******************************* 

//******************************.ChangeToLower.*********************************
//Purpose : To convert to lower case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return will be 0 & for any failure return will be -1
//Notes   : None
//*
bool ChangeToLower(uint8_t *pucStringName)
{
    if(pucStringName == NULL)
    {
        return false;
    }
    
    while (*pucStringName)
    {
        if(*pucStringName >= 'A' && *pucStringName <= 'Z') 
        {
            *pucStringName = *pucStringName + ('a' - 'A');
        }

        pucStringName++;
    }

    return true;
}

//******************************.ChangeToUpper.******************************************************************* 
//Purpose : To convert to upper case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return will be 0 & for any failure return will be -1
//Notes   :  None
//*
bool ChangeToUpper(uint8_t *pucStringName)
{
    if(pucStringName == NULL)
    {
        return false;
    }
    
    while (*pucStringName)
    {
        if(*pucStringName >= 'a' && *pucStringName <= 'z') 
        {
            *pucStringName = *pucStringName - ('a' - 'A');
        }
        pucStringName++;
    }

    return true;
}

//******************************.ChangeToCamel.******************************************************************** 
//Purpose : To convert to camel case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Return  : Boolean value - for success return will be 0 & for any failure return will be -1
//Notes   : None
//*
bool ChangeToCamel(uint8_t *pucStringName)
{
    uint8_t ChangeCaseNewWord = 1;

    if(pucStringName == NULL)
    {
        return false;
    }

    while(*pucStringName)
    {
        if(*pucStringName == ' ')
        {
            ChangeCaseNewWord = 1;
        }
        else
        {
            if(ChangeCaseNewWord)
            {
                if(*pucStringName >= 'a' && *pucStringName <= 'z')
                { 
                    *pucStringName = *pucStringName - ('a' - 'A');
                } 
                ChangeCaseNewWord = 0;
            }
            else
            {
                if(*pucStringName >= 'A' && *pucStringName <= 'Z')
                {
                    *pucStringName = *pucStringName + ('a' - 'A');
                }
            }
        }
        
        pucStringName++;  
    }
    
    return true;
}

//******************************.ChangeCase.***********************************************************************
//Purpose : To change the case conversion.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//          pucUserChoice - Interger pointer to get choice from user
//Return  : Boolean value - for success return will be 0 & for any failure return will be -1
//Notes   :  
//*
bool ChangeCase(uint8_t *pucStringName, CASE_TYPE *pucUserChoice)
{
    if(pucStringName == NULL || pucUserChoice == NULL)
    {
        printf("pointer is NULL\n");
        return false;
    }
    else
    {
        switch(*pucUserChoice)
        {
            case CHANGE_CASE_LOWER:
                if(ChangeToLower(pucStringName) != true)
                {
                    return false;
                }
                break;
            case CHANGE_CASE_UPPER:
                if(ChangeToUpper(pucStringName) != true)
                {
                    return false;
                }
                break;
            case CHANGE_CASE_CAMEL:
                if(ChangeToCamel(pucStringName) != true)
                {
                    return false;
                }
                break;
            default:
                printf("Invalid user choice\n");
                break;
        }
    }

    return true;
}
//EOF