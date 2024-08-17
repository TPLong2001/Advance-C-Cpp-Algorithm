/*
* File: app.c
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a source file consist of function serving binary search
*/
#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\app.h"

void addListType(CompareType type){
    int (*compareFunct)(const Person *, const Person *) = NULL;
    switch (type)
    {
        case compareName:
            compareFunct = compareByName;
            break;
        case compareAge:
            compareFunct = compareByAge;
            break;
        case compareAddress:
            compareFunct = compareByAddress;
            break;
        case comparePhoneNumber:
            compareFunct = compareByPhoneNumber; 
            break;   
    }

    //tao ngau nhien 100 node
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        per[i].age = rand() % 100 + 1;
        add_node(&head, per[i], compareFunct);
    }
}

void binarySearchType(Person person,CompareType type){
    int (*compareFunct)(const Person *, const Person *) = NULL;
    switch (type)
    {
        case compareName:
            compareFunct = compareByName;
            break;
        case compareAge:
            compareFunct = compareByAge;
            break;
        case compareAddress:
            compareFunct = compareByAddress;
            break;
        case comparePhoneNumber:
            compareFunct = compareByPhoneNumber; 
            break;   
    }

    CenterPoint *ptr = centerPoint(head);
    CenterPoint *result = binarySearch(ptr, person, compareFunct);
    if (result != NULL) {
        printf("Tim thay person:\n");
        printDataPerson(&(result->person));
    } 
    else{
        printf("Khong tim thay\n");
    }
}

void print_list() {
    Node *list = head;
    while (list != NULL) {
        printDataPerson(&(list->data));
        list = list->next;
    }
    printf("\n");
}