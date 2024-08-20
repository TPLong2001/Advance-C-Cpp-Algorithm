/*
* File: test.c
* Author: Long Truong
* Date: 20/04/2024
* Description: This is a source file print data to test
*/
#include"..\Header\test.h"


extern Node *head;

void printDataPerson(const Person *p){
    printf("Name: %s\n",p->name);
    printf("Age: %d\n",p->age);
    printf("Address: %s\n",p->address);
    printf("Phone Number: %s\n\n",p->phoneNumber);
}

void print_list() {
    Node *list = head;
    while (list != NULL) {
        printDataPerson(&(list->data));
        list = list->next;
    }
    printf("\n");
}