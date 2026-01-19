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
#define CHANGE_CASE_MULTPLR         (2)
#define CHANGE_CASE_PREFIX_SIZE     (2)
#define CHANGE_CASE_NULL_CHARA_SIZE (1)

//****************************** Local Functions *******************************
static bool ChangeToLower(uint8_t *pucStringName);
static bool ChangeToUpper(uint8_t *pucStringName);
static bool ChangeToCamel(uint8_t *pucStringName);
static bool ChangeToHex(uint8_t *pucStringName);

//***************************** Local Variables ********************************
const CHANGE_CASE_HANDLER CaseHandler[] = {
    {CHANGE_CASE_LOWER, "Lower Case", ChangeToLower},
    {CHANGE_CASE_UPPER, "Upper Case", ChangeToUpper},
    {CHANGE_CASE_CAMEL, "Camel Case", ChangeToCamel},
    {CHANGE_CASE_HEX, "Hex", ChangeToHex}
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
    bool blChangeLowerRet = false;

    if(pucStringName != NULL)
    {
        while (*pucStringName)
        {
            if(*pucStringName >= 'A' && *pucStringName <= 'Z') 
            {
                *pucStringName = *pucStringName + ('a' - 'A');
            }

            pucStringName++;
        }

        blChangeLowerRet = true;
    }

    return blChangeLowerRet;
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
    bool blChangeUpperRet = false;

    if(pucStringName != NULL)
    {
        while (*pucStringName)
        {
            if(*pucStringName >= 'a' && *pucStringName <= 'z') 
            {
                *pucStringName = *pucStringName - ('a' - 'A');
            }
            pucStringName++;
        }

        blChangeUpperRet = true;
    }

    return blChangeUpperRet;
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
    bool blChangeCamelRet = false;

    if(pucStringName != NULL)
    {
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

        blChangeCamelRet = true;

    }

    return blChangeCamelRet;
}

//******************************.ChangeToHex.*********************************
//Purpose   : To convert to hex.
//Inputs    : pucStringName - Character Pointer to get the input string from 
//            user
//Outputs   : pucStringName - updated string after conversion
//Return    : Boolean value - for both input success return will be true else 
//            false
//Notes     : None
//*
static bool ChangeToHex(uint8_t *pucStringName)
{
    bool blChangeHexRet = false;

    uint8_t ChangeCaseHexBuffer[(READ_INPUT_STRING_SIZE * CHANGE_CASE_MULTPLR) +
         CHANGE_CASE_PREFIX_SIZE+CHANGE_CASE_NULL_CHARA_SIZE];
    uint8_t *ChangeCaseHexPtr = ChangeCaseHexBuffer;
    ChangeCaseHexPtr += sprintf((char*)ChangeCaseHexPtr, "0x");

    if(pucStringName != NULL)
    {
        for(int i = 0; pucStringName[i] != '\0'; i++)
        {
            ChangeCaseHexPtr += sprintf((char*)ChangeCaseHexPtr, "%02X", 
            pucStringName[i]);
        }

        blChangeHexRet = true;
    }

        strcpy((char*)pucStringName, (char*)ChangeCaseHexBuffer);
        return blChangeHexRet;
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