/*
* File: binarySearch.h
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a header file consist of declare functions and variables
*/
#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME       32
#define SIZE_ADDR       100
#define SIZE_PHONE_NUM  11

typedef struct Person {
    char name[SIZE_NAME];
    int age;
    char address[SIZE_ADDR];
    char phoneNumber[SIZE_PHONE_NUM];
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

typedef struct CenterPoint {
    Person person;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;


/*
* Function: compareByName
* Description: This function compare the Name of two Person
* Input:
*   p1 - an Person value
*   p2 - an Person value
* Output:
*   returns The space between two different characters in the name
*/
int compareByName(const Person *p1, const Person *p2);

/*
* Function: compareByAge
* Description: This function compare the Name of two Person
* Input:
*   p1 - an Person value
*   p2 - an Person value
* Output:
*   returns The space between two different age number.
*/
int compareByAge(const Person *p1, const Person *p2);

/*
* Function: compareByAddress
* Description: This function compare the Name of two Person
* Input:
*   p1 - an Person value
*   p2 - an Person value
* Output:
*   returns The space between two different characters in the ByAddress
*/
int compareByAddress(const Person *p1, const Person *p2);

/*
* Function: compareByPhoneNumber
* Description: This function compare the Name of two Person
* Input:
*   *p1 - an pointer Person value
*   *p2 - an pointer Person value
* Output:
*   returns The space between two different integer number in the phone number
*/
int compareByPhoneNumber(const Person *p1, const Person *p2);

void printDataPerson(const Person *p);

/*
* Function: add_node
* Description: This function create new Node with data of person and insert to list with type sort belong compareFunct
* Input:
*   head    - an pointer Node point to head in list
*   person  - an Persion value
*   int (*compareFunct)(const Person *, const Person *) - callback function
* Output:
*   not output
*/
void add_node(Node **head, Person person, int (*compareFunct)(const Person *, const Person *));

/*
* Function: centerPoint
* Description: This function count node number in list and init binary Tree
* Input:
*   head    - an pointer Node point to head in list
* Output:
*   return root of binary tree
*/
CenterPoint *centerPoint(Node *head);

/*
* Function: binarySearch
* Description: This function search person data in binary tree with type data search belong compareFunct
* Input:
*   root    - an pointer CenterPoint point to root in binary tree
* Output:
*   return root of binary tree
*/
CenterPoint *binarySearch(CenterPoint *root, Person person, int (*compareFunct)(const Person *, const Person *));


void splitString(const char *str, const char *delim,Person *person);

#endif