//**************************** Case Conversion****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File        : change_case.h
// Summary     : To change case of the string as per user input
// Note        : 
// Author      : Sreelakshmy M A
// Date        : 15/01/2026
// 
//***************************************************************************** 
 
#ifndef _CHANGE_CASE_H_ 
#define _CHANGE_CASE_H_

//******************************* Include Files ******************************* 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//**************************** Forward Declarations *************************** 
bool ChangeCase(uint8_t *ucStringName,uint8_t *ucUserChoice);
bool ChangeToLower(uint8_t *ucptrStringName);
bool ChangeToUpper(uint8_t *ucptrStringName);
bool ChangeToCamel(uint8_t *ucptrStringName);

#endif // 