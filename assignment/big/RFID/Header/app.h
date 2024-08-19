/*
* File: app.h
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a header file consist of declare functions layer application
*/
#ifndef __APP_H__
#define __APP_H__

#include <time.h>
#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\binarySearch.h"

typedef enum CompareType{
    compareName,
    compareAge,
    compareAddress,
    comparePhoneNumber
}CompareType;

#define SELECT_COMPARE_BY(type) \
    CompareType useCompareType = compare##type;

Person per[100];
Node *head = NULL;


/*
* Function: addListType
* Description: This function create person then add to list with following order config type 
* Input:
*   type - an CompareType value, type order you want sort
* Output:
*   not output
*/
void addListType(CompareType type);


/*
* Function: binarySearchType
* Description: This function search person with following order config type 
* Input:
*   type - an CompareType value, type order you want sort to binary tree
*   person - an Person value you want search
* Output:
*   not output
*/
void binarySearchType(Person person,CompareType type);


/*
* Function: print_list
* Description: This function print list in linked list
* Input:
*   not onput
* Output:
*   not output
*/
void print_list(void);


#endif