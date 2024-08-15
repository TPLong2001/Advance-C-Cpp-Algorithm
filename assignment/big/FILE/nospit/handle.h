#ifndef __HANDLE_H__
#define __HANDLE_H__

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

////////////handle Sort
void mergeSort(home home_data[], int left, int right);
void radixSort(home home_data[], int size);

//////////////handle File
int getDataFromFile(const char *name,const char *mode, int numLine);
int printDataToFile(const char *name,const char *mode,int line);
void bestSeller(home data[], int size);

#endif