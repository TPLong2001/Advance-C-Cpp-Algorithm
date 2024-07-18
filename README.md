# Lesson 3: Pointer
## 1.Pointer
### Kích thước pointer
#### kích thước của pointer phụ thuộc vào kiến trúc máy tính thực thi
#### Kiến trúc x86, con trỏ sẽ có kích thước 32-bit (4 bytes)
#### Kiến trúc x64, con trỏ sẽ có kích thước 64-bit (8 bytes)
### Định nghĩa
#### Biến con trỏ là một biến có giá trị là địa chỉ của một biết khác ( chứa địa chỉ của một biến khác). Biến bình thường thì chỉ lưu giá trị
```c
int main{
    int var = 10;  //bien binh thuong
    int *ptr;      //bien con tro
    ptr = &var;    // bien con tro lay dia chi cua bien var

    //ex1: pointer
    int a = 10;
    int array[]={1,2,4,5};

    int *ptr = array;

    printf("Dia chi a: %p \n", &a);
    printf("gia tri tai dia chi: %d\n",*ptr);
    printf("Dia chi Tong: %p \n", &tong);
    printf("Dia chi array: %p\n",array);
}
```
## 2.function pointer
#### Con trỏ hàm là 1 con trỏ lưu trữ địa chỉ của 1 hàm mà nó đang trỏ đến. Nó cũng có thể truyền một fumctiom như một đối số cho function khác.
```c
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
int main (int argc, char const *argv[]){
//ex2: func pointer
    void (*phepToan[])(int,int) = {&tong, &hieu, &tich, &thuong};

    phepToan[0](7,5);
    phepToan[1](7,5);
    phepToan[2](7,5);
    phepToan[3](7,5);

    TinhToan(&tong,27,65);
    TinhToan(&hieu,27,65);
    TinhToan(&thuong,27,65);

    char (*text)() = &display;
    printf("Test: %c\n",text());
    return 0;
}
```


## 3.Type pointer
#### Các kiểu dữ liệu của con trỏ cho thấy con trỏ đang lưu trữ dữ giá trị kiểu giữ liệu nào tại địa chỉ đó.
#### VD: char *ptr; đây là con trỏ kiểu char nó sẽ sử dụng 1 byte địa chỉ tương úng để chứa giá trị. Nếu có các giá trị xếp liên tiếp (như kiểu mảng, kiểu chuỗi) thì xác định theo độ lệch địa chỉ cũng dựa vào kiểu dữ liệu của con trỏ đó, từ đó việc dịch địa chỉ để lấy giá trị trong 1 chuỗi các giá trị liên tiếp mới chính xác.
#### con trỏ kiểu void có thể trỏ đến tất các các con trỏ, địa chỉ khác mà không cần quan tâm đến kiểu dữ liệu của con trỏ, địa chỉ đó.
```c
#include<stdio.h>
int main (int argc, char const *argv[]){
//ex3: type pointer 
    int var_int = 50;
    char var_char = 'A';
    double var_double = 10.5;
    
    int *ptr;
    char *ptr_char;
    float *ptr_float;
    double *ptr_double;

    void *ptr_void;

    ptr_void = &tong;
    ((void (*)(int,int))ptr_void)(3,4);

    ptr_void = &var_char;
    printf("Dia chi: %p, int: %c\n",ptr_void,*(char *)ptr_void);    
    ptr_void = &var_double;
    printf("Dia chi: %p, int: %f\n",ptr_void,*(double *)ptr_void);    
    ptr_void = &var_int;
    printf("Dia chi: %p, int: %d\n",ptr_void,*(int *)ptr_void);     
    return 0;
}
```


## 4.Pass by value và Pass by reference
#### Khi truyền các đối số vào 1 hàm thì:
#### -Nếu truyền int a, int b (Pass by value) thì khi hàm đó được gọi, các đối số truyền vào sẽ được khởi tạo 1 bản sao của nó hoàn toàn không liên quan đến các đối số đã truyền vào lúc đầu, các bản sao đó sẽ được thực thi trong hàm và được xóa khi kết thúc hàm vì vậy giá trị của các đối số lúc truyền vào sẽ không bị thay đổi.
#### - Nếu truyền int *a, int *b (Pass by reference) thì khi hàm đó được gọi, các đối số truyền vào sẽ có giá trị chính là địa chỉ cuả các đối số truyền vào đó, lên khi thực thi trong hàm thay đổi giá trị của biến thông qua địa chỉ sẽ thay đổi hoàn toán giá trị của biến đó, kế cả khi thoát khỏi hàm.
#### - Con trỏ hằng: là 1 biến con trỏ trỏ vào 1 giá trị hằng, vì vậy không thể thay đổi giá trị của hằng đó kể cả thông qua con trỏ, còn ta vẫn có thể sử dụng các con trỏ khác để trỏ vào hằng đó.
#### - Hằng con trỏ: là 1 biền con trỏ kiểu hằng (không thể thay đổi giá trị tại nó được lưu trong bộ nhớ vùng data segment) vì vậy khi dã gán cho nó 1 địa chỉ để trỏ vào thì ta không thể thay đổi địa chỉ trỏ vào đó hay nói cách khác ta không thể trỏ đến giá trị khác nữa. còn giá trị trỏ vào vẫn có thể thay đổi giá trị.
```c
#include<stdio.h>
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
int main (int argc, char const *argv[]){
//ex4: tham chieu bien, con tro hang, hang con tro
    int x = 10, y = 20;     //0x01=10 0x02=20
    printf("x=%d, y=%d\n",x,y);

    swap2(&x,&y);
    printf("x=%d, y=%d\n",x,y);

    printf("String: %s\n",string);

    // display2(string);
    // printf("String: %s\n",string);
    return 0;
}
```



## 5.NULL Pointer 
#### là con trỏ trỏ đến vùng nhớ bằng không hay nói cách khác nó không trỏ đến bất kì đối tượng hay vùng nhớ nào. nó được ứng dụng cho việc khai báo các con trỏ ban đầu khi chưa có đối tượng trỏ cụ thể để tránh trỏ vào các vùng nhớ rác không mong muốn gây lỗi hệ thống.


## 6.Pointer to pointer
