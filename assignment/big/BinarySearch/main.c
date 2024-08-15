#include <stdio.h>
#include <stdlib.h>

#define MAX 15

void sort(int *array, int size)
{
    int a;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if(array[i] > array[j]){
                a = array[i];
                array[i] = array[j];
                array[j] = a;
            }
        } 
    }  
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Arr[%d] = %d\n", i, array[i]);
    }
    
}

int binarySearch(int *array, int left, int right, int data)
{
    int pos = 0x2FFF;                       // Value = False => not found
    int mid = (right + left) / 2;           // (right - left) / 2 + left

    if(array[mid] == data)
    {
        pos = mid;
    }
    else if ((array[mid] > data) && ((mid - 1) > left))
    {
        pos = binarySearch(array, left, mid - 1, data);
    }
    else if ((array[mid] < data ) && ((mid + 1) <= right))
    {
        pos = binarySearch(array, mid + 1, right, data);
    }
    return pos;
}



int main()
{
    int Array[MAX] = {5, 3, 9, 2, 7, 4, 11, 54, 12, 32, 13, 33, 26, 1, 27};
    sort(Array, MAX);
    display(Array, MAX);
    int i = binarySearch(Array, 0, MAX -1, 13);
    (i == 0x2FFF) ? printf("Not Found!\n") : printf("\nArr[%d] = %d\n", i, Array[i]);
    return 0;
}