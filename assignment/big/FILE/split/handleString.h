#ifndef __HANDLE_STRING_H__
#define __HANDLE_STRING_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 10000

typedef struct home
{
    int YearBuilt;
    int LandSize;
    char Postcode[8];
    int Price;
    char Seller[11];
}home;

home home_data[MAXLINE];


int CharToNum(char x);
int stringToNum(char *string);
void stringToArray(char *string, char array[],int size);
int stringCompare(const char *str1, const char *str2) ;



#endif
