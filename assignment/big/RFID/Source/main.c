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

    SELECT_COMPARE_BY(Age);

    addListType(useCompareType);
    print_list();
    binarySearchType(value, useCompareType);

    return 0;
}