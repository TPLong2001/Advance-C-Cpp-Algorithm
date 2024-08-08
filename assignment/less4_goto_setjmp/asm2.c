#include<stdio.h>
#include<setjmp.h>

typedef enum ErrorCodes {
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR 
}ErrorCodes;

jmp_buf buf;
ErrorCodes exception_code;
char *error_mesage;

#define TRY         if((exception_code=setjmp(buf))==0)
#define CATCH(x)    else if(exception_code == (x))
#define THROW(x,y)  throw(x,y)

void throw(ErrorCodes x, char* y){
    error_mesage=y;
    longjmp(buf,x);
}

ErrorCodes status(ErrorCodes exception_code){
    ErrorCodes status;
    switch (exception_code)     
    {
    case FILE_ERROR:
        return  FILE_ERROR;
    case NETWORK_ERROR:
        return  NETWORK_ERROR;
    case CALCULATION_ERROR:
        return  CALCULATION_ERROR;
    case NO_ERROR:
        return  NO_ERROR;   
    }
}


void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    printf("Xử lý mạng ...\n");
    THROW(NETWORK_ERROR, "Lỗi Xử lý mạng: Không thể kết nối mạng.");
}

void calculateData() {
    printf("Tính toán dữ liệu ...\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán dữ liệu: dữ liệu không tồn tại.");
}

int main(){

    TRY{
        readFile();
        networkOperation();
        calculateData();
    }CATCH(status(exception_code)){
        printf("%s\n",error_mesage);
    }

    return 0;
}