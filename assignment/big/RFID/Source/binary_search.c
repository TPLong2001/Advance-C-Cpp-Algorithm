/*
* File: binarySearch.c
* Author: Long Truong
* Date: 17/04/2024
* Description: This is a source file consist of function serving binary search
*/
#include"..\Header\binary_search.h"

static int CharToNum(char x)
{
    return (int)x - 48;
}

static int stringToNum(char *string)
{
    int result = 0;
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        result = CharToNum(*string) + result * 10;
        string++;
    }
    return result;
}

static int stringCompare(const char *str1, const char *str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

static void stringToArray(char *string, char array[])
{
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        array[i] = *string;
        string++;
    }
    array[len] = '\0';
}

static void coppyDataPerson(Person *dich,const Person *nguon){
    dich->name = (char*)malloc(sizeof(char)*(strlen(nguon->name) + 1));                 // lenth + 1 ky tu \0
    stringToArray((nguon->name), dich->name);
    
    dich->age = nguon->age;

    dich->address = (char*)malloc(sizeof(char)*(strlen(nguon->address) + 1));           // lenth + 1 ky tu \0
    stringToArray((nguon->address), dich->address);

    dich->phoneNumber = (char*)malloc(sizeof(char)*(strlen(nguon->phoneNumber) + 1));   // lenth + 1 ky tu \0
    stringToArray((nguon->phoneNumber), dich->phoneNumber);
}

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

///////////////////////////////////////////////////////////////////////
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
    return stringCompare(p1->phoneNumber, p2->phoneNumber);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void add_node(Node **head, Person *person, int (*compareFunct)(const Person *, const Person *)) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    coppyDataPerson(&(new_node->data), person);         //ERROR
    new_node->next = NULL;

    if (*head == NULL || compareFunct(&((*head)->data), person) >= 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && (compareFunct(&(current->next->data), person) < 0)) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    free(person->name);
    free(person->address);
    free(person->phoneNumber);
}

CenterPoint *centerPoint(Node *head) {
    int length = 0;
    Node *node = head;
    while (node != NULL) {
        node = node->next;
        length++;
    }
    return buildTree(head, 0, length - 1);
}

CenterPoint *binarySearch(CenterPoint *root, Person person, int (*compareFunct)(const Person *, const Person *)) {

    // static int loop = 0;
    // loop++;
    // printf("so lan lap: %d\n", loop);

    if (root == NULL) {
        return NULL;
    }

    if (compareFunct(&person, &(root->person)) == 0) {
        return root;
    }

    if (compareFunct(&person, &(root->person)) < 0) {
        return binarySearch(root->left, person, compareFunct);
    } else {
        return binarySearch(root->right, person, compareFunct);
    }
}

///////////////////////////////////////////////////////////////////////////
void splitString(const char *str, const char *delim,Person *person) {
    char *copy = strdup(str);           //Sao chép chuỗi gốc để giữ nguyên chuỗi gốc
    char *token = copy;                 //con trỏ chuỗi để xử lý thành từng phần nhỏ và lấy data
    char *next_token = NULL;            //con trỏ chuỗi dùng để phân tách từng phần nhỏ
    int column = 0;                     //stt cột

    while (token != NULL) {
        // Tìm vị trí của dấu phân cách tiếp theo
        next_token = strstr(token, delim);

        if (next_token != NULL) {
            // Đặt dấu kết thúc chuỗi tại vị trí của dấu phân cách
            *next_token = '\0';
            next_token += strlen(delim);    //lấy địa chỉ mới sau dấu phân cách
        }

        switch (column)
        {
        case 0:
            person->name = (char *)malloc(sizeof(char) * (strlen(token) + 1));
            stringToArray(token,person->name);
            break;
        case 1:
            person->age = stringToNum(token);
            break;
        case 2:
            person->address = (char *)malloc(sizeof(char) * (strlen(token) + 1));
            stringToArray(token,person->address);
            break;
        case 3:
            person->phoneNumber = (char *)malloc(sizeof(char) * (strlen(token) + 1));
            stringToArray(token,person->phoneNumber);
            break;
        default:
            break;
        }
        token = next_token;
        column++; 
    }
    free(copy);         // Giải phóng bộ nhớ đã sao chép chuỗi
}
