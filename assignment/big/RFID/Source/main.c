#include "..\Header\app.h"
#include "..\Header\test.h"

// #include "..\Source\test.c"
// #include "..\Source\binary_search.c"
// #include "..\Source\app.c"

extern CompareType g_usedCompareType; 

int main() {
    CenterPoint *result;
    Person value = {    
        "asfy",
        22,                         //age = 23
        "46 dfg",
        "0325344355"
    };

    SELECT_COMPARE_BY(COMPARE_ADDRESS);

    //load data from FILE to List
    if(addListType() == STATUS_FALSE){
        printf("Khong the mo file %s!\n","dataRFID.csv");
        return 0;
    }

    print_list();
    
    if((result = binarySearchType(value)) != NULL){
        printf("Tim thay person:\n");
        printDataPerson(&(result->person));
    }else{
        printf("Khong tim thay\n");
    }
        
    return 0;
}