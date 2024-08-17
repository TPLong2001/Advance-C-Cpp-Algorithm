#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\binarySearch.h"
#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Source\binarySearch.c"

int main() 
{
    Node *head = NULL;

    Person per[100];

    //tao ngau nhien 10000 node
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        per[i].age = rand() % 100 + 1;
        add_node(&head, per[i], compareByAge);
    }

    print_list(head);

    CenterPoint *ptr = centerPoint(head);

    Person value = {
        .name = "",
        .age = 23,
        .address = "",
        .phoneNumber = {}
    };
    CenterPoint *result = binarySearch(ptr, value, compareByAge);
    if (result != NULL) {
        printf("Tim thay person:\n");
        printDataPerson(&(result->person));
    } else 
    {
        printf("Khong tim thay\n");
    }

    return 0;
}