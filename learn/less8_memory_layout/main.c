#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

void test1()
{
    int array[2] ;
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);
}

void test2()
{
    int *array = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);

    array = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);


    // int *array1 = (int*)malloc(sizeof(int) * 2);
    // printf("dia chi array1[0]: %p\n", array1);
    // printf("dia chi array1[1]: %p\n", array1 + 1);

    // array = (int*)realloc(array,sizeof(int) * 4);
    // printf("dia chi array[0]: %p\n", array);
    // printf("dia chi array[1]: %p\n", array + 1);

    free(array);
}


int main()
{
    // test1();
    // test1();
    // printf("------------------------\n");
    // test2();
    // printf("------------------------\n");
    // test2();

    uint16_t *ptr = NULL;
    // ptr = (uint16_t*)malloc(4 * sizeof(uint16_t));


    ptr = (uint16_t*)calloc(4,sizeof(uint16_t));

    // memset(ptr, 0, 4);

    // for (int i = 0; i < 4; i++)
    // {
    //     ptr[i] = 0;
    // }

    for (int i = 0; i < 4; i++)
    {
        printf("Dia chi: %p\tGia tri: %d\n", (uint8_t*)ptr+i*2, *((uint8_t*)ptr+i*2));
    }
    

    // ptr = realloc(ptr, 6 * sizeof(uint16_t));
    // for (int i = 0; i < 6; i++)
    // {
    //     ptr[i] = 2*i;
    // }
    // ptr[6] = 21;

    // for (int i = 0; i < 7; i++)
    // {
    //     printf("dia chi: %p\nGia tri: %d\n", (uint8_t*)ptr+i*2, *((uint8_t*)ptr+i*2));
    // }

    return 0;
}