#include<stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d = %d\n",a,b,a+b);

}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n",a,b,a-b);

}

void tich(int a, int b){
    printf("tich %d va %d = %d\n",a,b,a*b);

}

void thuong(int a, int b){
    printf("thuong %d va %d = %f\n",a,b,a/(double)b);

}

void TinhToan(void (*phepToan)(int,int),int a, int b){
    printf("Chuong trinh tinh toan:\n");
    phepToan(a,b);
}

char display(){
    return (char) 'A';
}

void swap(int a, int b){    //int a=10, int b=20, 0xc3=10 va 0xc4=20
    int c;
    c = a;
    a = b;
    b = c;
}

void swap2(int *a, int *b){     //int *a=0x01  int *b=0x02
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

char string[]="Hello worlds";

// void display2(const char *words){ // truyen vao con tro hang
//     words[0] = 'W'; //khong cho phep thay doi du lieu

// }

int main (int argc, char const *argv[]){

    // int *ptr = NULL;
    // printf("gia tri: %p\n",ptr);

    int var = 5;        //*0x01=5
    int *ptr = &var;    //*0xc1=0x01
    int **ptp = &ptr;   //**ptp=0xc1
    printf("Dc var:%p\n",&var);
    printf("Dc ptr:%p\n",&ptr);
    printf("Dc ptp:%p\n",&ptp);
    


// //ex4: tham chieu bien, con tro hang, hang con tro
//     int x = 10, y = 20;     //0x01=10 0x02=20
//     printf("x=%d, y=%d\n",x,y);

//     swap2(&x,&y);
//     printf("x=%d, y=%d\n",x,y);

//     printf("String: %s\n",string);

//     // display2(string);
//     // printf("String: %s\n",string);




// //ex3: type pointer 
//     int var_int = 50;
//     char var_char = 'A';
//     double var_double = 10.5;
    
//     int *ptr;
//     char *ptr_char;
//     float *ptr_float;
//     double *ptr_double;

//     void *ptr_void;

//     ptr_void = &tong;
//     ((void (*)(int,int))ptr_void)(3,4);

//     ptr_void = &var_char;
//     printf("Dia chi: %p, int: %c\n",ptr_void,*(char *)ptr_void);    
//     ptr_void = &var_double;
//     printf("Dia chi: %p, int: %f\n",ptr_void,*(double *)ptr_void);    
//     ptr_void = &var_int;
//     printf("Dia chi: %p, int: %d\n",ptr_void,*(int *)ptr_void);    
 
       
    
    

// //ex2: func pointer
//     void (*phepToan[])(int,int) = {&tong, &hieu, &tich, &thuong};

//     phepToan[0](7,5);
//     phepToan[1](7,5);
//     phepToan[2](7,5);
//     phepToan[3](7,5);

//     TinhToan(&tong,27,65);
//     TinhToan(&hieu,27,65);
//     TinhToan(&thuong,27,65);

//     char (*text)() = &display;
//     printf("Test: %c\n",text());


    
    
// //ex1: pointer
//     int a = 10;

//     int array[]={1,2,4,5};

//     int *ptr = array;

//     printf("Dia chi a: %p \n", &a);
//     printf("gia tri tai dia chi: %d\n",*ptr);
//     printf("Dia chi Tong: %p \n", &tong);
//     printf("Dia chi array: %p\n",array);


    return 0;
}