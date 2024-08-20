#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\app.h"
// #include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Source\binarySearch.c"
// #include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Source\app.c"


int main() 
{
    Node *head = NULL;

    Person value = {    
        "asfy",
        22,         //age = 23
        "46 dfg",
        "0325344355"
    };

    SELECT_COMPARE_BY(compareAddress);

    //load data from FILE to List
    if(addListType(&head, useCompareType) == -1){
        return 0;
    }

    print_list(head);
    
    binarySearchType(head, value, useCompareType);

    return 0;
}