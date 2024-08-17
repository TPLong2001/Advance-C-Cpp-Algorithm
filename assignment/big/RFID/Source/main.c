#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Header\app.h"
#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Source\binarySearch.c"
#include "D:\code\Advance C_Cpp Algorithm\Advance-C-Cpp-Algorithm\assignment\big\RFID\Source\app.c"


int main() 
{
    Person value = {
        .name = "",
        .age = 23,
        .address = "",
        .phoneNumber = {}
    };

    addListType(compareAge);
    print_list();
    binarySearchType(value, compareAge);

    return 0;
}