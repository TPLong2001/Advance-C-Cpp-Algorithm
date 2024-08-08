#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY         if((exception_code=setjmp(buf))==0)
#define CATCH(x)    else if(exception_code == (x))
#define THROW(x)    longjmp(buf,(x))


//setjmp(buf) == 0
//longjmp(buf,(x))

double thuong(int a, int b){
    if(b == 0){
        // longjmp(buf,1);
        THROW(1);   
    }
    return a/(double)b;
}

int checkArray(int array[], int size){
    if(size <= 0){
        // longjmp(buf,2);//đặt mã lỗi là 2
        THROW(2);
    }
    return 1;
}


int main(){

    exception_code = setjmp(buf);

    // //ex1
    // if (exception_code == 2);
    // {
    //     printf("Nhay den 2\n");
    //     //exit();

    // }
    // printf("Test: %d\n",exception_code);

    // longjmp(buf,2);

    // printf("Thoat\n");


    // //ex2
    // double ketqua;
    // if(exception_code == 0){
    //     int array[0];
    //     // ketqua = thuong(8,0);
    //     // printf("Ket qua %f\n",ketqua);

    //     checkArray(array, 0);
    // }else if(exception_code == 1){
    //     printf("ERROR! Mau bang 0\n");
    // }else if (exception_code == 2)
    // {
    //     printf("ERROR! Aray bang 0\n");
    // }
    

    //ex3
    TRY{
        int array[0];
        // ketqua = thuong(8,0);
        // printf("Ket qua %f\n",ketqua);

        checkArray(array, 0);
    }CATCH(1){
        printf("ERROR! Mau bang 0\n");
    }CATCH(2)
    {
        printf("ERROR! Aray bang 0\n");
    }
    
    
    


    return 0;
}