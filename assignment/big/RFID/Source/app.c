/*
* File: app.c
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a source file consist of function serving binary search
*/
#include "..\Header\app.h"

Node *head = NULL;
CompareType g_usedCompareType;

static int (*checkCompareType())(const Person *, const Person *){
    int (*compareFunct)(const Person *, const Person *) = NULL;
    switch (g_usedCompareType)
    {
        case COMPARE_NAME:
            compareFunct = compareByName;
            break;
        case COMPARE_AGE:
            compareFunct = compareByAge;
            break;
        case COMPARE_ADDRESS:
            compareFunct = compareByAddress;
            break;
        case COMPARE_PHONE_NUMBER:
            compareFunct = compareByPhoneNumber; 
            break;  
        default:
            break; 
    }
    return compareFunct;
}

Status addListType(){
    int (*compareFunct)(const Person *, const Person *) = checkCompareType();

    Person *dataPerson = (Person*)malloc(sizeof(Person));
    char line[255];
    
    FILE*fp = fopen("D:/code/Advance C_Cpp Algorithm/Advance-C-Cpp-Algorithm/assignment/big/RFID/dataRFID.csv","r");  
    if(!fp)
    {
        return STATUS_FALSE;
    }
    fgets(line,255,fp);                                 //read line 1

    while(!feof(fp))
    {
        fgets(line,255,fp);
        splitString(line, ",",dataPerson);
        add_node(&head, dataPerson, compareFunct);
    }
    fclose(fp);
    free(dataPerson);
    return STATUS_SUCCESS;
}

CenterPoint *binarySearchType(Person person){
    int (*compareFunct)(const Person *, const Person *) = checkCompareType();
    CenterPoint *ptr = centerPoint(head);
    CenterPoint *result = binarySearch(ptr, person, compareFunct);
    if (result != NULL) {
        return result;
    } 
    else{
        return NULL;
    }
}