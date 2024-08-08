#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code;

#define TRY         if((exception_code=setjmp(buf))==0)
#define CATCH(x)    else if(exception_code == (x))
#define THROW(x,y)  throw(x,y)

void throw(int x, char* y){
    error_code=y;
    longjmp(buf,x);
}

//setjmp(buf) == 0
//longjmp(buf,(x))

double thuong(int a, int b){
    if(b == 0){
        // longjmp(buf,1);
        THROW(1,"Lỗi! Phép chia cho 0!");   
    }
    return a/(double)b;
}

int checkArray(int array[], int size){
    if(size <= 0){
        THROW(2,"Lỗi! Mảng có kích thước bằng 0!");
    }
    return 1;
}


int main(){

    TRY{
        int array[0];
        // int ketqua = thuong(8,0);
        // printf("Ket qua %f\n",ketqua);

        checkArray(array, 0);
    }CATCH(1){
        printf("%s\n",error_code);
    }CATCH(2)
    {
        printf("%s\n",error_code);
    }
    return 0;
}