/*
* File: app.h
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a header file consist of declare functions layer application
*/
#ifndef __APP_H__
#define __APP_H__

#include "..\Header\binary_search.h"
#include <stdio.h>

#define SELECT_COMPARE_BY(type) \
    g_usedCompareType = type;

/*
* enum: Status
* Description:  Enum consisting of elements that replace success or failure attributes
* element:
*   STATUS_SUCCESS   - a value enum replace success
*   STATUS_FALSE     - a value enum replace failure
*/
typedef enum Status{
    STATUS_SUCCESS,
    STATUS_FALSE
}Status;

/*
* enum: CompareType
* Description:  Enum consisting of elements that represent the type of comparison the user needs to make
* element:
*   COMPARE_NAME           - a value enum represent the type of compare name
*   COMPARE_AGE            - a value enum represent the type of compare age
*   COMPARE_ADDRESS        - a value enum represent the type of compare address
*   COMPARE_PHONE_NUMBER   - a value enum represent the type of compare phoneNumber
*/
typedef enum CompareType{
    COMPARE_NAME,
    COMPARE_AGE,
    COMPARE_ADDRESS,
    COMPARE_PHONE_NUMBER
}CompareType;

/*
* Function: addListType
* Description: This function create person then add to list with following order config type 
* Input:
*   input void
* Output:
*   return FILE_OPEN_FALSE or FILE_OPEN_SUCCESS
*/
Status addListType();

/*
* Function: binarySearchType
* Description: This function search person with following order config type 
* Input:
*   person - an Person value you want search
* Output:
*   return result searched
*/
CenterPoint *binarySearchType(Person person);

#endif