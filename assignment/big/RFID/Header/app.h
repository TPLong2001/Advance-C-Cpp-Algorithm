/*
* File: app.h
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a header file consist of declare functions layer application
*/
#ifndef __APP_H__
#define __APP_H__

#include "..\Header\binarySearch.h"

typedef enum CompareType{
    compareName,
    compareAge,
    compareAddress,
    comparePhoneNumber
}CompareType;

extern CompareType usedCompareType; 
#define SELECT_COMPARE_BY(type) \
    usedCompareType = type;


/*
* Function: addListType
* Description: This function create person then add to list with following order config type 
* Input:
*   not input
* Output:
*   return -1 if false file open
*/
int addListType();


/*
* Function: binarySearchType
* Description: This function search person with following order config type 
* Input:
*   person - an Person value you want search
* Output:
*   not output
*/
void binarySearchType(Person person);


/*
* Function: print_list
* Description: This function print list in linked list
* Input:
*   not input
* Output:
*   not output
*/
void print_list() ;


#endif