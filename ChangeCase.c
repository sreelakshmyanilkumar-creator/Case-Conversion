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

//****************************** Local Functions *******************************
static bool ChangeToLower(uint8_t *pucStringName);
static bool ChangeToUpper(uint8_t *pucStringName);
static bool ChangeToCamel(uint8_t *pucStringName);

//***************************** Local Variables ********************************
 CHANGE_CASE_HANDLER CaseHandler[] = {
    {CHANGE_CASE_LOWER, ChangeToLower},
    {CHANGE_CASE_UPPER, ChangeToUpper},
    {CHANGE_CASE_CAMEL, ChangeToCamel}
 };

//******************************.ChangeToLower.*********************************
//Purpose : To convert to lower case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Outputs : pucStringName - updated string after conversion
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
static bool ChangeToLower(uint8_t *pucStringName)
{
    bool ChangeLowerRet = true;

    if(pucStringName == NULL)
    {
        ChangeLowerRet = false;
    }
    
    while (*pucStringName)
    {
        if(*pucStringName >= 'A' && *pucStringName <= 'Z') 
        {
            *pucStringName = *pucStringName + ('a' - 'A');
        }

        pucStringName++;
    }

    return ChangeLowerRet;
}

//******************************.ChangeToUpper.*********************************
//Purpose : To convert to upper case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Outputs : pucStringName - updated string after conversion
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
static bool ChangeToUpper(uint8_t *pucStringName)
{
    bool ChangeUpperRet = true;

    if(pucStringName == NULL)
    {
        ChangeUpperRet = false;
    }
    
    while (*pucStringName)
    {
        if(*pucStringName >= 'a' && *pucStringName <= 'z') 
        {
            *pucStringName = *pucStringName - ('a' - 'A');
        }
        pucStringName++;
    }

    return ChangeUpperRet;
}

//******************************.ChangeToCamel.*********************************
//Purpose : To convert to camel case.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//Outputs : pucStringName - updated string after conversion
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
static bool ChangeToCamel(uint8_t *pucStringName)
{
    bool ChangeCaseNewWord = true;
    bool ChangeCamelRet = true;

    if(pucStringName == NULL)
    {
        ChangeCamelRet = false;
    }

    while(*pucStringName)
    {
        if(*pucStringName == ' ')
        {
            ChangeCaseNewWord = true;
        }
        else
        {
            if(ChangeCaseNewWord)
            {
                if(*pucStringName >= 'a' && *pucStringName <= 'z')
                { 
                    *pucStringName = *pucStringName - ('a' - 'A');
                } 
                ChangeCaseNewWord = false;
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
    
    return ChangeCamelRet;
}

//******************************.ChangeCase.************************************
//Purpose : To change the case conversion.
//Inputs  : pucStringName - Character Pointer to get the input string from user
//          pucUserChoice - Interger pointer to get choice from user
//Outputs : pucStringName - updated string after conversion
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
bool ChangeCase(uint8_t *pucStringName, CHANGE_CASE_TYPE *pucUserChoice)
{
    bool ChangeCaseRet = true;
    uint8_t ChangeCaseMaxCount = sizeof(CaseHandler)/sizeof(CaseHandler[0]);

    if(pucStringName == NULL || pucUserChoice == NULL)
    {
        printf("pointer is NULL\n");
        ChangeCaseRet = false;
    }
    else
    {
        for(int count = 0; count < ChangeCaseMaxCount; count++)
        {
            if(CaseHandler[count].ChangeCaseType == *pucUserChoice)
            {
                ChangeCaseRet = CaseHandler[count].func(pucStringName);
            }
        }
    }

    return ChangeCaseRet;
}
//EOF