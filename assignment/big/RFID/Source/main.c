#include "..\Header\app.h"
// #include "..\Source\binarySearch.c"
// #include "..\Source\app.c"


int main() 
{
    Person value = {    
        "asfy",
        22,                         //age = 23
        "46 dfg",
        "0325344355"
    };

    SELECT_COMPARE_BY(compareAddress);

    //load data from FILE to List
    if(addListType() == -1){
        return 0;
    }

    print_list();
    
    binarySearchType(value);

    return 0;
}