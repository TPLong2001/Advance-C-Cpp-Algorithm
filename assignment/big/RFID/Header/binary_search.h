/*
* File: binarySearch.h
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a header file consist of declare functions and variables
*/
#ifndef __BINARY_SEARCH_H__
#define __BINARY_SEARCH_H__

#include <stdlib.h>
#include <string.h>

/*
* struct: Person
* Description:The structure contains information about the user
* element:
*   name        - a pointer to a string that stores the user's name
*   age         - an integer value that stores the user's age
*   address     - a pointer to a string that stores the user's address
*   phoneNumber - a pointer to a string that stores the user's phoneNumber
*/
typedef struct Person {
    char *name;
    int age;
    char *address;
    char *phoneNumber;
} Person;

/*
* struct: Node
* Description:The structure contains data and poiter next
* element:
*   data     - a Person value that stores the user's data
*   next     - a pointer to other Node in List.
*/
typedef struct Node {
    Person data;
    struct Node *next;
} Node;

/*
* struct: CenterPoint
* Description:The structure binaryTree contains data and poiter left and right
* element:
*   person  - a Person value that stores the user's data
*   left    - a pointer to left Node in binaryTree.
*   right   - a pointer to right Node in binaryTree.
*/
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

/*
* Function: printDataPerson
* Description: This function printf each data in Person value 
* Input
*   person  - an Persion value
* Output:
*   return none
*/
void printDataPerson(const Person *p);

//////////////////////////////////////////////////////////////////////////////////////

/*
* Function: add_node
* Description: This function create new Node with data of person and insert to list with type sort belong compareFunct
* Input:
*   head    - an pointer Node point to head in list
*   person  - an Persion value
*   compareFunct - callback function
* Output:
*   return none
*/
void add_node(Node **head, Person *person, int (*compareFunct)(const Person *, const Person *));

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
*   person  - an Persion value 
*   compareFunct    - callback function 
* Output:
*   return root of binary tree
*/
CenterPoint *binarySearch(CenterPoint *root, Person person, int (*compareFunct)(const Person *, const Person *));


/*
* Function: splitString
* Description: This function Split a string into small parts based on the delimiter character then save data to Persion value
* Input:
*   str    - an pointer char point to string need split
*   person - an Persion value to stora data from string
*   delim  - an pointer char point to string contains 1 separator character
* Output:
*   return none
*/
void splitString(const char *str, const char *delim, Person *person);

#endif