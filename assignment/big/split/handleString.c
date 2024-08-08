#include "handleString.h"


int CharToNum(char x)
{
    return (int)x - 48;
}

int stringToNum(char *string)
{
    int result = 0;
    int count = 0;
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        // printf("len %d string %d: %c\n",strlen(string),i,*string);
        if(*string == '.'){
            break;
        }
        result = CharToNum(*string) + count * 10;
        count = result;
        string++;
    }
    return result;
}

void stringToArray(char *string, char array[],int size)
{
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        if(*string == '.'){
            break;
        }
        array[i] = *string;
        string++;
    }
}

int stringCompare(const char *str1, const char *str2) 
{
   while (*str1 && (*str1 == *str2)) 
   {
        //printf("str1:%c str2:%c\n",*str1,*str2);
        str1++;
        str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}