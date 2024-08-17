/*
* File: binarySearch.c
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a source file consist of function serving binary search
*/
#include"D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\binarySearch.h"

static int stringCompare(const char *str1, const char *str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

static int arrayCompare(const int *arr1, const int *arr2){
    int compare;
    for (int i = 0; i < 10; i++)
    {
        compare = arr1[i] - arr2[i];
        if(compare != 0){
            break;
        }
    }
    return compare;
}

int compareByName(const Person *p1, const Person *p2){
    return stringCompare(p1->name, p2->name);
}

int compareByAge(const Person *p1, const Person *p2){
    return p1->age - p2->age;
}

int compareByAddress(const Person *p1, const Person *p2){
    return stringCompare(p1->address, p2->address);
}

int compareByPhoneNumber(const Person *p1, const Person *p2){
    return arrayCompare(p1->phoneNumber, p2->phoneNumber);
}

void coppyDataPerson(Person *dich, Person *nguon){
    for (int i = 0; i < 30; i++)
    {
        dich->name[i] = nguon->name[i];
    }
    dich->age = nguon->age;
    for (int i = 0; i < 100; i++)
    {
        dich->address[i] = nguon->address[i];
    }
    for (int i = 0; i < 10; i++)
    {
        dich->phoneNumber[i] = nguon->phoneNumber[i];
    }
}

static void printDataPerson(const Person *p){
    printf("Name: %s\n",p->name);
    printf("Age: %d\n",p->age);
    printf("Address: %s\n",p->address);
    printf("Phone Number: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d",p->phoneNumber[i]);
    }
    printf("\n");
}

//them node va sap xep tu be den lon
void add_node(Node **head, Person person, int (*compareFunct)(const Person *, const Person *)) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    coppyDataPerson(&(new_node->data), &person);
    new_node->next = NULL;

    if (*head == NULL || compareFunct(&((*head)->data), &person) >= 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && compareFunct(&(current->next->data), &person) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

//tim diem giua phia ben trai va ben phai su dung de quy
static CenterPoint *buildTree(Node *head, int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    coppyDataPerson(&(root->person), &(node->data));
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

//tim diem giua
CenterPoint *centerPoint(Node *head) {
    int length = 0;
    Node *node = head;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}



//ham tim kiem nhi phan
CenterPoint *binarySearch(CenterPoint *root, Person person, int (*compareFunct)(const Person *, const Person *)) {
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop);
    if (root == NULL) {
        return NULL;
    }

    // if (root->value == value) {
    if (compareFunct(&person, &(root->person)) == 0) {
        return root;
    }

    // if (value < root->value) {
    if (compareFunct(&person, &(root->person)) < 0) {
        return binarySearch(root->left, person, compareFunct);
    } else {
        return binarySearch(root->right, person, compareFunct);
    }
}

void print_list(Node *head) {
    while (head != NULL) {
        printDataPerson(&(head->data));
        head = head->next;
    }
    printf("\n");
}