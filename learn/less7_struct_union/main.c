#include<stdio.h>
#include<stdint.h>
#include<string.h>

// typedef struct 
// {
//     uint16_t var1;      // 2 byte
//     uint8_t var2;       // 1 byte
//     uint32_t var3;      // 4 byte
// }frame;

typedef union 
{
    uint16_t var1;      // 2 byte
    uint8_t var2;       // 1 byte
    uint32_t var3;      // 4 byte
}frame;

// typedef union 
// {
//     struct 
//     {
//         uint8_t id[2];
//         uint8_t data[5];
//         uint8_t cs[1];       
//     }data;
//     uint8_t array[8];
    
// }frame;



int main()
{
    frame test;

    test.var1 = 1;
    test.var2 = 2;
    test.var3 = 243534; //0x3B74E

    // printf("dia chi: %p\n",test);
    // printf("dia chi var1: %p\n",test.var1);
    // printf("Size: %lu byte\n",sizeof(frame));

    printf("test.var1: %p\n",test.var1);    //0xB74E
    printf("test.var2: %p\n",test.var2);    //0x4E
    printf("test.var3: %p\n",test.var3);    //0x3B74E 
    
    
    
    
    // frame transmit;
    // strcpy(transmit.data.id,(char*)"12");
    // strcpy(transmit.data.data,(char*)"12345");
    // strcpy(transmit.data.cs,(char*)"6");
    // //printf("ID:%s DATA:%s CS:%c  array:%s\n",transmit.data.id, transmit.data.data, transmit.data.cs,transmit.array);

    // frame receiver;
    // strcpy(receiver.array,transmit.array);

    //printf("ID:%s DATA:%s CS:%c\n",receiver.data.id, receiver.data.data, receiver.data.cs);

    return 0;
}