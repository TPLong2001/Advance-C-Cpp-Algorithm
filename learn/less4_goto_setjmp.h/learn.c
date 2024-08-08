#include<stdio.h>

int main(int argc,char const *argv[]){

    batdau:
    for (int i = 0; i < 10; i++)
    {

        printf("i = %d\n",i);
        if(i ==5){
            goto batdau;
        }
    }
    return 0;
}