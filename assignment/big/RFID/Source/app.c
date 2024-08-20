/*
* File: app.c
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a source file consist of function serving binary search
*/
#include "..\Header\app.h"

Node *head = NULL;
CompareType usedCompareType;

static int (*checkCompareType())(const Person *, const Person *){
    int (*compareFunct)(const Person *, const Person *) = NULL;
    switch (usedCompareType)
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
    return compareFunct;
}

int addListType(){
    int (*compareFunct)(const Person *, const Person *) = checkCompareType();

    Person dataPerson;
    char line[255];
    
    FILE*fp = fopen("D:/code/Advance C_Cpp Algorithm/Advance-C-Cpp-Algorithm/assignment/big/RFID/dataRFID.csv","r");  
    if(!fp)
    {
        printf("Khong the mo file %s!\n","dataRFID.csv");
        return -1;
    }
    fgets(line,255,fp);                                 //read line 1

    while(!feof(fp))
    {
        fgets(line,255,fp);
        splitString(line, ",",&dataPerson);
        add_node(&head, dataPerson, compareFunct);
    }
    fclose(fp);
    return 1;
}

void binarySearchType(Person person){
    int (*compareFunct)(const Person *, const Person *) = checkCompareType();

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