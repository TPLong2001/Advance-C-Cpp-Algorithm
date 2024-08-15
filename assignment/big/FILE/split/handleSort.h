#ifndef __HANDLE_SORT_H__
#define __HANDLE_SORT_H__

#include "handleString.h"

void coppyDataHome(home *dich, home *nguon);
void merge(home home_data[], int left, int mid, int right);
void mergeSort(home home_data[], int left, int right);
void radixSort(home home_data[], int size);

#endif