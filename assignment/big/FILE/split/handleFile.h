#ifndef __HANDLE_FILE_H__
#define __HANDLE_FILE_H__

#include "handleString.h"

void splitString(const char *str, const char *delim, int countLine);
int getDataFromFile(const char *name,const char *mode, int numLine);
int printDataToFile(const char *name,const char *mode,int line);
void bestSeller(home data[], int size);

#endif