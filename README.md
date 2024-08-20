# Lesson 3: POINTER

<details>
  <summary>chi tiết</summary

## 1. Pointer
 Kích thước pointer: kích thước của pointer phụ thuộc vào kiến trúc máy tính thực thi
+ Kiến trúc x86, con trỏ sẽ có kích thước 32-bit (4 bytes)
+ Kiến trúc x64, con trỏ sẽ có kích thước 64-bit (8 bytes)
  
Định nghĩa: Biến con trỏ là một biến có giá trị là địa chỉ của một biết khác ( chứa địa chỉ của một biến khác). Biến bình thường thì chỉ lưu giá trị
    
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
## 2. function pointer
- Con trỏ hàm là 1 con trỏ lưu trữ địa chỉ của 1 hàm mà nó đang trỏ đến. Nó cũng có thể truyền một fumctiom như một đối số cho function khác.

Example:

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
- Ta cũng có thể viết một hàm trả về địa chỉ của một hàm khác bằng cách sử dụng con trỏ hàm trong C

Example
```c
#include <stdio.h>

// Định nghĩa các hàm add và subtract
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// Định nghĩa một hàm trả về con trỏ hàm
int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return add;
    } else if (op == '-') {
        return subtract;
    } else {
        return NULL;  // Trường hợp không hợp lệ
    }
}

int main() {
    // Sử dụng hàm getOperation để lấy địa chỉ của hàm add
    int (*operation)(int, int) = getOperation('+');
    
    if (operation != NULL) {
        printf("Result: %d\n", operation(5, 3));  // Output: Result: 8
    } else {
        printf("Invalid operation\n");
    }

    // Sử dụng hàm getOperation để lấy địa chỉ của hàm subtract
    operation = getOperation('-');
    
    if (operation != NULL) {
        printf("Result: %d\n", operation(5, 3));  // Output: Result: 2
    } else {
        printf("Invalid operation\n");
    }

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

## 4. Pass by value và Pass by reference
#### Khi truyền các đối số vào 1 hàm thì:
- Nếu truyền int a, int b (Pass by value) thì khi hàm đó được gọi, các đối số truyền vào sẽ được khởi tạo 1 bản sao của nó hoàn toàn không liên quan đến các đối số đã truyền vào lúc đầu, các bản sao đó sẽ được thực thi trong hàm và được xóa khi kết thúc hàm vì vậy giá trị của các đối số lúc truyền vào sẽ không bị thay đổi.
- Nếu truyền int *a, int *b (Pass by reference) thì khi hàm đó được gọi, các đối số truyền vào sẽ có giá trị chính là địa chỉ cuả các đối số truyền vào đó, lên khi thực thi trong hàm thay đổi giá trị của biến thông qua địa chỉ sẽ thay đổi hoàn toán giá trị của biến đó, kế cả khi thoát khỏi hàm.

|Pass by value|Pass by reference|
|:--------|:--------|
|- Một bản sao của đối số truyền vào được tạo ra|- Truyền trực tiếp con trỏ vào trong hàm|
|- Thay đổi giá trị của đối số truyền vào trong hàm không ảnh hưởng đến biến gốc.|- Thay đổi giá trị của đối số truyền vào trong hàm ảnh hưởng trực tiếp đến biến gốc.|
|- Tốn bộ nhớ hơn do phải khởi tạo các bản sao|- Tiết kiệm bộ nhớ hơn và có thể hiệu quả với các cấu trúc dữ liệu lớn như "struct"|
#### Type pointer
- Con trỏ hằng: là 1 biến con trỏ trỏ vào 1 giá trị hằng, vì vậy không thể thay đổi giá trị của hằng đó kể cả thông qua con trỏ, còn ta vẫn có thể sử dụng các con trỏ khác để trỏ vào hằng đó.
- Hằng con trỏ: là 1 biền con trỏ kiểu hằng (không thể thay đổi giá trị tại nó được lưu trong bộ nhớ vùng data segment) vì vậy khi dã gán cho nó 1 địa chỉ để trỏ vào thì ta không thể thay đổi địa chỉ trỏ vào đó hay nói cách khác ta không thể trỏ đến giá trị khác nữa. còn giá trị trỏ vào vẫn có thể thay đổi giá trị.

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
</details>








# Lesson 4: GOTO_SETJMP
<details>
  <summary>Chi tiết</summary>

  # 1. goto
  ## Định nghĩa: 
  "goto" là một từ khóa trong C, câu lệnh goto là một câu lệnh nhảy (jump) vô điều kiện. Khi sử dụng câu lệnh nó sẽ nhảy đến một nhãn đã đặt trước đó.
việc nhảy vô điều kiện như vậy khiến ta rất dể dàng sử dụng để kiểm soát flow của chương trình, nhưng nếu lạm dụng nó có thể khiến cho chương trình trở lên khó đọc và bảo trì.
  ### Ví Dụ
 ```c
#include<stdio.h>

int main(int argc,char const *argv[]){

    batdau:
    for (int i = 0; i < 10; i++)
    {

        printf("i = %d\n",i);
        if(i == 5){
            goto batdau;
        }
    }
    return 0;
}
```
Trong ví dụ này sau khi i tiến tới 5 nó sẽ đọc đến câu lệnh goto để nhảy đến nhãn "batdau" và lại bắt đầu vòng lặp từ i = 0, vì vậy vòng lặp này sẽ chạy vô hạn từ 0 đến 5 và quay lại.

  ## Ưu điểm của goto
  ### Tự tạo 1 vòng lặp cơ bản
  goto có thể được sử dụng để tạo một vòng lặp đơn giản bằng cách gắn nhãn nhảy và kiểm tra điều kiện thoát.
  ### Ví Dụ
```c
#include <stdio.h>
int main() {
    int i = 0;

    start:
        if (i >= 5) {
            goto end; 
        }
        printf("%d ", i);
        i++;
        goto start;
    end:
        printf("\n");
    return 0;
}
```
Khi i đạt đến giá trị 5, control sẽ chuyển đến nhãn "end" và kết thúc chương trình.

  ### Thoát khỏi vòng lặp nhiều cấp độ
Nhiều trường hợp có nhiều vòng lặp lồng nhau, khi đó để thoát khỏi toàn bộ hoặc 1 số vòng lặp sẽ rất khó khăn, ta sẽ phải kiểm tra điều kiện thoát vòng lặp liên tục ở các vòng lặp sau đó. Để giải quyết việc này ta có thể sử dụng goto để nhảy đến 1 nhãn đã đặt ở nơi cần thoát ra.
  ### Ví Dụ
```c
for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        if (some_condition(i, j)) {
            goto exit_loops;
        }
    }
}
exit_loops:
```
  
### Xử lý lỗi và giải phóng bộ nhớ
Trong trường hợp xử lý lỗi, có thể sử dụng goto để dễ dàng giải phóng bộ nhớ đã được cấp phát trước khi thoát khỏi hàm.
### Ví Dụ
```c
void process_data() {
    int *data = malloc(sizeof(int) * 100);
    if (data == NULL) {
        goto cleanup;
    }
    cleanup:
    free(data);
}

```
  ### Implement Finite State Machines (FSM)
Trong một số trường hợp, đặc biệt là khi triển khai Finite State Machines, goto có thể được sử dụng để chuyển đến các trạng thái khác nhau một cách dễ dàng khi thỏa mãn điều kiện đề ra trước đó, ta có thể cho nó nhảy sang xử lý các điều kiện khác.
### Ví Dụ
```c
switch (current_state) {
    case STATE_A:
        // Xử lý State A
        if (condition) {
            goto STATE_B;
        }
        break;
    case STATE_B:
        break;
}

```
   ## Nhược điểm của goto
  + Việc sử dụng câu lệnh goto không được khuyến khích vì nó làm cho logic chương trình trở nên rất phức tạp.
  + Việc sử dụng goto làm cho việc theo dõi dòng chảy của chương trình trở nên rất khó khăn.
  + Việc sử dụng goto làm cho nhiệm vụ phân tích và xác minh tính đúng đắn của các chương trình (đặc biệt là các chương trình liên quan đến vòng lặp) trở nên rất khó khăn.
  + Việc sử dụng goto có thể tránh được một cách đơn giản bằng cách sử dụng câu lệnh break và continue .

# 2. setjmp.h
  ## Định nghĩa: 
  "setjmp.h" là một thư viện trong C cung cấp các hàm để xử lý các ngoại lệ theo mong muốn. có 2 hàm chính là setjmp và longjmp để thực hiện xử lý các ngoại lệ.
```c
setjmp(buf) == 0
longjmp(buf,(x))
```
  ## Ví Dụ:
```c
#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;

int main(){

    exception_code = setjmp(buf);

    //ex1
    if (exception_code == 2);
    {
        printf("Nhay den 2\n");
        //exit();

    }
    printf("Test: %d\n",exception_code);

    longjmp(buf,2);

    printf("Thoat\n");
    return 0;
}
```
khi khời tạo setjmp(buf); giá trị exception_code sẽ bằng 0;
sau khi hệ thống xử lý đến dòng longjmp(buf,2) lệnh này sẽ nhảy đến vị trí khởi tạo ban đầu và thay đổi giá trị exception_code thành 2 chính vì vậy nó sẽ nhảy vào if và in ra dòng nhảy đến 2.

## Xử lý ngoại lệ:
Từ các ứng dụng của 2 hàm trên ta define chúng thành 3 từ khóa chính với cấu trúc TRY CATCH (bắt lỗi và xử lý lỗi) giống với các ngôn ngứ bậc cao như sau.

```c
#define TRY         if((exception_code=setjmp(buf))==0)
#define CATCH(x)    else if(exception_code == (x))
#define THROW(x)    longjmp(buf,(x))
```
Sau đó khi cần xử lý lỗi ta dùng TRY và bắt lỗi ta dùng CATCH. Xác định lỗi, gán giá trị lỗi và nhảy đến xử lý lỗi ta dùng THROW.
```c
#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY         if((exception_code=setjmp(buf))==0)
#define CATCH(x)    else if(exception_code == (x))
#define THROW(x)    longjmp(buf,(x))

double thuong(int a, int b){
    if(b == 0){
        // longjmp(buf,1);
        THROW(1);   
    }
    return a/(double)b;
}

int checkArray(int array[], int size)
{
    if(size <= 0){
        // longjmp(buf,2);//đặt mã lỗi là 2
        THROW(2);
    }
    return 1;
}

int main(){
    TRY
    {
        int array[0];
        // ketqua = thuong(8,0);
        // printf("Ket qua %f\n",ketqua);
        checkArray(array, 0);
    }
    CATCH(1){
        printf("ERROR! Mau bang 0\n");
    }
    CATCH(2)
    {
        printf("ERROR! Aray bang 0\n");
    }
    return 0;
}
```
</details>











# Lesson 5: EXTERN - STATIC - REGISTER - VOLATILE
<details>
  <summary>Chi tiết</summary>

  ### 1. Extern
  Trong một project thường được chia nhỏ các file để biên dịch riêng lẻ sau đó kết hợp với nhau, việc này nhằm tăng tốc độ biên dịch của các chương trình lớn.
  Vì vậy để sử dụng được một Biến Toàn Cục hay một hàm từ một file khác ta có thể sử dụng "extern" để khai báo lại biến đó trong file cần sử dụng.
  Tóm lại, Extern là: Tham chiếu của một biến toàn cục hoặc 1 hàm nào đó đã được định nghĩa ở phạm vi bên ngoài file đó. (chỉ khai báo chứ không định nghĩa giá trị).
```c
extern <kiểu dữ liệu>  <tên biến>;
extern <kiểu dữ liệu>  <tên hàm>(các parameter truyền vào hàm đó);
```

  ### 2. Static
  Biến static hay còn được gọi là biến tĩnh có 2 loại:
  #### 2.1 Static local variable
  Khi biến được khởi tạo với từ khóa "static" nó sẽ được lưu trữ trong vùng nhớ static,globle và sẽ tồn tại trong suốt vòng đời của chương trình ngay cả khi kết thúc hàm chứa nó. Chính vì vậy khi được khởi tạo lần đầu tiên nó sẽ khởi tạo duy nhất 1 lần, với các lần khởi tạo tiếp theo sẽ bị bỏ qua.
  ```c
//exemple
void count(){
    static int a = 0;
    printf("a = %d\n",a);
    a++;
}
int main(int argv, char const *argc[])
{
    count();
    count();
    count();
    return 0;
}
```
OUTPUT:
```
a = 0
a = 1
a = 2
```
  #### 2.1 Static globle variable and function
  Các biến toàn cục hay hàm sử dụng từ khóa "static" thì khi đó phạm vi sử dụng giới hạn trong File khởi tạo đó, phạm vị bên ngoài file sẽ không thể sử dụng kể cả sử dụng "extern" để truy xuất. Chính bởi vậy nó có tác dụng không cho người dùng khác truy cập từ bên ngoài file vào các hàm phụ hỗ trợ các hàm chính. Đó là ứng dụng để tạo ra các thư viện.
  ```c
static int num;
static void count(){
    int a = 0;
    printf("a = %d\n",a);
    a++;
}
```

  ### 3. Register
  Các biến được khai báo với tử khóa này sẽ được lưu trong thanh ghi register thay vì lưu trong ram, nó sẽ giúp tốc độ tính toán nhanh hơn bình thường

  ### 4. Volatile
  Các biến được khai báo với tử khóa này sẽ thông báo cho chương trình không được phép tối ưu hóa biến đó trong quá trình biên dịch tránh gây lỗi không mong muốn và rất khó phát hiện.
  Một ưu điểm quan trong ứng dụng trong RTOS đó là khi có nhiều luồng chương trình chạy đồng thời, nếu cùng một mảng chạy 2 tác vụ khác nhau khi đang ghi dở vào hàm ở tác vụ 1 mà nhảy sang tác vụ 2 ghi vẫn vào hàm đó thì giá trị ban đầu ghi sẽ bị ghi đè mất và khi quay lại sẽ gây sai dữ liệu. Vì vây ta bắt buộc sử dụng "volatile" để bắt tác vụ đó thực hiện lại từ đầu nếu đang làm dở mà nhảy đi và quay lại.

</details>













# Lesson 6: BITMASK
<details>
  <summary>Chi tiết</summary>
  
  #### Bitmask "mặt nạ bit" là một kỹ thuật sử dụng thao tác với các bit để set, clear, get 1 bit bất kỳ trong 1 thanh ghi bằng cách sử dụng các phép toán logic.
  ### 1. AND bitwise
  - ký hiệu là "&".
  - Được sử dụng để như một phép nhân, với đầu ra là 1 nếu cả 2 bit đầu vào là 1
```c
int result = num1 & num2;
```
Example:
```
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1

  0b11110011
~ 0b11001011
= 0b11000011
```
  ### 2. OR bitwise
  - ký hiệu là "|".
  - Được sử dụng để như một phép cộng, với đầu ra là 0 nếu cả 2 bit đầu vào là 0
  
```c
int result = num1 | num2;
```
Example:
```
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1

  0b11110011
| 0b11001011
= 0b11111011
```
  ### 3. XOR bitwise
  - ký hiệu là "^".
  - Với đầu ra là 1 nếu 2 bit đầu vào là khác nhau ( 0 với 1)
  
```c
int result = num1 ^ num2;
```
Example:
```
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

  0b11110011
^ 0b11001011
= 0b00111000
```

  ### 4. NOT bitwise
  - ký hiệu là "~".
  - Được sử dụng để đào toàn bộ các bit của biến đó.
```c
int result = ~num;
```
Example:
```
~ 0 = 1
~ 1 = 0
~ 0b11110011 = 0b00001100
```

### 5. Shift left bitwise
  - ký hiệu là "<<".
  - Được sử dụng để dịch chuyển bit sang trái n bit tương đương với x (2^n).
```c
int result = num << n;
```
Example:
```
1 << 3 = 0b00000001 << 3 = 0b00001000 = 1 x 2^3
5 << 2 = 0b00000101 << 2 = 0b00010100 = 1 x 2^2 + 1 x 2^4 = 5 x 2^2
```
### 6. Shift right bitwise
  - ký hiệu là ">>".
  - Được sử dụng để dịch chuyển bit sang phải n bit tương đương với / (2^n).
```c
int result = num >> n;
```
Example:
```
11 >> 3 = 0b00001011 >> 3 = 0b00000001 = 11 / 2^3 = 1
15 >> 2 = 0b00001111 >> 2 = 0b00000011 = 15 / 2^2 = 3
```

</details>













# Lesson 7: STRUCT - UNION 
<details>
  <summary>Chi tiết</summary>

  ### Struct
  Struct là 1 kiểu dữ liệu tự định nghĩa và được sử dụng để lưu trữ các biến có kiểu dữ liệu khác nhau ở một đối tượng duy nhất.
  - Các biến sẽ được lưu trữ liên tục trên bộ nhớ và tên của Struct chính là con trỏ trỏ và địa chỉ của phần tử đầu tiên.
  - Kích thước của struct sẽ phụ thuộc và kích thước của các dữ liệu bên trong nó và phần PADDING.
  - PADDING: khi lưu trữ các dữ liệu sẽ được lưu lần lượt vào block ( kích thước của block phụ thuộc vào kích thước của kiểu dữ liệu lớn nhất trong struct). Nếu dữ liệu tiếp theo nào đó cần được lưu trữ có kích thước lớn hơn phần dư còn lại của block ( ví dụ block có kích thước 4 byte sau khi lưu 2 biến 1 byte còn thừa 2 byte nhưng biến tiếp theo càn lưu trữ lại có kích thước 4 byte > 2 byte còn lại), khi đó padding sẽ được thêm vào phần dư của block đó (2 byte padding) và dữ liệu sẽ được đẩy sang  block mới.

Example:
```c
typedef struct 
{                       // 1 block = 4 byte                                                  1 byte  1 byte  1 byte 1 byte
    uint16_t var1;      // 2 byte  2 < 4 byte dư                                 block 1:   //-var1-//-var1-//--dư--//--dư--//      => còn 2 byte dư
    uint8_t var2;       // 1 byte  1 < 2 byte dư                                 block 1:   //-var1-//-var1-//-var2-//-padding-//   => còn 1 byte dư
    uint32_t var3;      // 4 byte  4 > 1 byte dư => 1 byte padding =>     chuyển block 2:   //-var3-//-var3-//-var3-//-var3-//
}frame;                 // => size = số block cần dùng * kích thước của block = 2 * 4 = 8 byte

int main()
{
    printf("Kich thuoc: %d byte\n",sizeof(frame);
    return 0;
}
```
OUTPUT:
```
Kich thuoc: 8 byte
```

  ### Bit Field
  Bit fields trong C là các thành viên của một struct có kích thước được chỉ định dưới dạng số bit thay vì số byte. Chúng cho phép bạn lưu trữ nhiều giá trị nhỏ trong một không gian bộ nhớ nhỏ gọn hơn so với việc sử dụng các kiểu dữ liệu thông thường. Và địa chỉ của chúng vẫn được lưu trữ lần lượt liên tục trên bộ nhớ.
  ```c
struct MyStruct {
    unsigned int field1 : 1;  // 1 bit
    unsigned int field2 : 4;  // 4 bits
    unsigned int field3 : 3;  // 3 bits
};
```
Các biến được định nghĩa với độ rộng xác định trước được gọi là trường bit (bit field). Một trường bit có thể chứa nhiều hơn một bit nhưng độ rộng này phải nhỏ hơn hoặc bằng độ rộng bit của kiểu.

  ### Union
  Tương tự như Struct, Union là một kiểu dữ liệu trong C cho phép bạn lưu trữ các biến khác nhau, nhưng chỉ tại một vị trí bộ nhớ. 
  - Union chỉ có thể lưu trữ một trong các biến thành viên của nó tại một thời điểm.
  - Điều này giúp tiết kiệm bộ nhớ khi bạn cần lưu trữ các loại dữ liệu khác nhau nhưng không cần lưu trữ tất cả cùng một lúc.
  - Kích thước của Union là kích thước của biến có kích thước lớn nhất và toàn bộ các biến trong đó sẽ sử dụng cùng một vùng địa chỉ đó.

```c
typedef union 
{
    uint16_t var1;      // 2 byte
    uint8_t var2;       // 1 byte
    uint32_t var3;      // 4 byte
}frame;
int main()
{
    printf("Kich thuoc: %d byte\n",sizeof(frame);
    return 0;
}
```
OUTPUT:
```
Kich thuoc: 4 byte
```

Example:
```c
typedef union 
{
    uint16_t var1;      // 2 byte
    uint8_t var2;       // 1 byte
    uint32_t var3;      // 4 byte
}frame;
int main()
{                                           //                                 LSB                          MSB
    frame test;                             //  data in 4 byte address:   //--------//--------//--------//--------//

    test.var3 = 243534;                     // 0x03B74E    =>     Data:   //---4E---//---B7---//---03---//---00---//  


    printf("test.var1: %p\n",test.var1);    // 2 byte data tu LSB         //---4E--//---B7---//                             => 0xB74E
    printf("test.var2: %p\n",test.var2);    // 1 byte data tu LSB         //---4E---//                                      => 0x4E
    printf("test.var3: %p\n",test.var3);    // 4 byte data tu LSB         //---4E---//---B7---//---03---//---00---//        => 0x3B74E
    return 0;
}
```
OUTPUT:
```
test.var1: 0000B74E
test.var2: 0000004E
test.var3: 0003B74E
```
vì các thành viên chia sẻ cùng 1 vị trí bộ nhó lên khi khai báo cho biến có kích thước lớn nhất, sau đó ta lấy giá trị của các biến thành viên khác thì khi đó nó sẽ đọc các byte giá trị của biến có kích thước lớn nhất đó theo kích thước của biến thành viên cần hiển thị. 

</details>









# Lesson 8: MEMORY LAYOUT
<details>
  <summary>Chi tiết</summary>

Khi viết một chương trình C/C++ thì source code (file.h, file.c, file.exe, .....) sẽ được lưu trữ trong bộ nhớ FLASH hoặc SSD, còn khi chương trình được thực thi các mã nguồn code sẽ được biên dịch vào mã mãy và được đưa vào bộ nhớ RAM để thực thi. Bộ nhớ của chương trình có thể chia thành các phần như sau:
  ### 1. Text Segment
  Đây là vùng địa chỉ thấp nhất lưu trữ mã lệnh của chương trình.
  - lưu trữ các biến const và dữ liệu trong con trỏ chuỗi khai báo như sau: char *ptr = "abc";
  - Vùng này chỉ có thể đọc và thực thi chứ không thể sửa được dữ liệu.

  ### 2. Data Segment
  Đây là vùng nhớ nằm phía trên của Text Segment:
  - Chứa các biến global và biến static
  - Có quyền truy cập cả đọc và ghi.
  - Các biến này sẽ được thu hồi sau khi kết thúc toàn bộ chương trình.

  Phân vùng này còn phân ra 2 làm phân vùng nhỏ là BSS và DS:
  - BSS: chứa các biến global và biến static không khai báo giá trị khởi tạo hoặc khai báo giá trị khởi tạo bằng 0.
  - DS: chứa các biến global và biến static khai báo giá trị khởi tạo khác 0.

  ### 3. Heap Segment
  Đây là vùng nhớ nằm trên Data Segment, kích thước của vùng nhớ có thể thay đổi được tùy thuộc vào từng chương trình.
  - Dùng cho cấp phát bộ nhớ động.
  - Được cấp phát và giải phóng bằng các hàm như: malloc(), calloc(), realloc(), và free().
  - Bộ nhớ do người dùng tự quản lý. Vì vậy cần tự thu hồi vùng bộ nhớ Heap đã cấp phát khi không còn sử dụng để tránh hiện tượng MEMORY LEAK.\
 
  ### 4. Stack Segment
  Đây là vùng nhớ nằm trên cùng có cấu trúc LIFO (last in first out) và được cấp phát bởi hệ thống
  - Dùng quản lý các biến cục bộ và các lời gọi hàm.
  - Có quyền đọc và ghi dữ liệu.
  - Mỗi khi hàm được gọi, Stack sẽ cấp phát một khối bộ nhớ (stack frame) cho hàm đó để thực hiện quá trình Stacking và Unstacking.
  - Sau khi thoát khỏi hàm frame stack sẽ được tự động giải phóng bởi hệ thống.
  - Nếu ta sử dụng quá nhiều biến cục bộ hoặc hàm lồng nhau thì có thể sẽ hết bộ nhớ Stack và xảy ra lỗi Stack Over Flow. ví dụ như hàm đệ quy vô hạn.
  
```c
void deQuy() {
    deQuy();
}

int main() {
    deQuy();
    return 0;
}
```
  ### 5. Cấp phát động và giải phóng bộ nhớ
  #### 5.1 Hàm malloc()
  - Hàm malloc() là hàm sử dụng để cấp phát 1 mảng liên tục trong bộ nhớ theo kích thước byte mong muốn.
  - Giá trị trả về của hàm là một con trỏ kiểu void vì vậy ta sẽ phải ép kiểu sang kiểu dữ liệu cần dùng. Trả về NULL nếu không thành công.
  - Vì hàm này không xóa (clear) hoặc sửa đổi (modify) bộ nhớ, do đó nội dung của bộ nhớ được cấp phát sẽ được xem như là chứa rác.
  ```c
    uint8_t *ptr = NULL;
    ptr = (uint8_t*)malloc(4 * sizeof(uint8_t));
    for (int i = 0; i < 4; i++)
    {
        printf("Gia tri: %d\n",ptr + i);
    }
```

  #### 5.2 Hàm calloc()
  - Hàm calloc cũng tương tự như malloc nhưng calloc cấp phát (allocate) và xóa (clear) bộ nhớ cùng lúc.
  - Cấp phát 1 bộ nhớ bằng với số phần tử cấp phát * kích thước kiểu dữ liệu.
    ```c
    int *ptr = calloc(5,sizeof(int));
    ```
  Ta cũng có thể sử dụng hàm malloc() và memset() để thay thế cho calloc(). Hàm memset sẽ thay đổi giá trị trong một buffer. 
  - Đối số đầu tiên là con trỏ tới buffer cần điều chỉnh nội dung. Đối số thứ hai là giá trị để thay đổi nội dung của buffer, và đối số cuối cùng là số byte bị thay đổi.
  ```c
  int *ptr = malloc(5 * sizeof(int));
  memset(ptr, 0, 5* sizeof(int));
```

  #### 5.3 Hàm realloc()
  - Hàm cấp phát lại kích thước của 1 mảng động trước đó khi ta muốn thay đổi kích thước ban đầu của mảng cấp phát. Kích thước được yêu cầu có thể nhỏ hơn hoặc lớn hơn lượng cấp phát đang có.
  - Nếu bộ nhớ mới được yêu cầu cấp phát nhỏ hơn bộ nhớ hiện tại, thì phần bộ nhớ dư bị trả lại heap.
  - Nếu kích thước lớn hơn hiện tại, nếu được thì, bộ nhớ sẽ được cấp phát thêm ngay sau vị trí cấp phát hiện tại.
  - Nhưng nếu vị trí hiện tại không đủ bộ nhớ thì, bộ nhớ được sẽ được cấp phát ở vị trí mới trong heap và dữ liệu cũ được copy sang vùng mới.

Cú pháp khai báo:
```c
uint16_t ptr = realloc(ptr, 6 * sizeof(uint16_t));
```
Example:
```c
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
void test2()
{
    int *array = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);

    int *array1 = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array1[0]: %p\n", array1);
    printf("dia chi array1[1]: %p\n", array1 + 1);

    array = (int*)realloc(array,sizeof(int) * 4);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);

    free(array);
    free(array1);
}

int main()
{
  test2();
  return 0;
}
```
Ouput:
```
dia chi array[0]: 00A71B00
dia chi array[1]: 00A71B04
dia chi array1[0]: 00A71B10
dia chi array1[1]: 00A71B14
dia chi array[0]: 00A71B20
dia chi array[1]: 00A71B24
```

  ### 6. Memori leaks
  Lỗi rò rỉ bộ nh xảy ra khi bộ nhớ được cấp phát không bao giờ được sử dụng lại nhưng lại không được giải phóng. Vì vậy các vùng bộ nhớ đó không thể đòi lại và sử dụng được nữa. Nếu bộ nhớ cứ liên tục được cấp phát     rồi mất, thì chương trình sẽ đến lúc ngưng hoạt động. Điều này xảy ra khi:
  - Bị mất địa chỉ bộ nhớ (losing the address).
  - Hàm free() không bao giờ được sử dụng hoặc rò rỉ ẩn (hidden leak).

Example:
```c
char *ptr;
while (1) {
    ptr = (char*) malloc(1000000);
    printf("Allocating\n");
}
```

#### 6.1 Bị mất địa chỉ bộ nhớ (losing the address)
```c
void test2()
{
    int *array = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);

    array = (int*)malloc(sizeof(int) * 2);
    printf("dia chi array[0]: %p\n", array);
    printf("dia chi array[1]: %p\n", array + 1);

    free(array);
}
int main()
{
    test2();
    printf("------------------------\n");
    test2();
    return 0;
}
```
OUTPUT:
```
dia chi array[0]: 009E1B00
dia chi array[1]: 009E1B04
dia chi array[0]: 009E1B10
dia chi array[1]: 009E1B14
------------------------
dia chi array[0]: 009E1B10
dia chi array[1]: 009E1B14
dia chi array[0]: 009E1B20
dia chi array[1]: 009E1B24
```
Như ta đã thấy, Khi array được gán tiếp một địa chỉ mới. Địa chỉ của lần cấp phát bộ nhớ đầu tiên bị mất khi array được cấp phát bộ nhớ lần thứ hai. Chính vì vậy không có con trỏ nào trỏ vào phân vùng địa chỉ cũ của array vì vậy không thể giải phóng nó và nó sẽ bị mất đi truy cập trong khi vẫn bị đánh dấu là đang sử dụng và ta không thể sử dụng lại nó nữa.

#### 6.2 Rò rỉ ẩn (hidden leak)
Nó thể xảy ra khi giải phóng những cấu trúc (structure) được tạo bằng cách sử dụng từ khóa struct. Nếu trong structure chứa con trỏ tới bộ nhớ cấp phát động, thì những con trỏ này phải được giải phóng trước khi structure được giải phóng. nếu không ta sẽ mất con trỏ trò vào vùng đó khi giải phóng truct trước.

</details>













# Lesson 9: JSON
<details>
  <summary>Chi tiết</summary>

  ### Định nghĩa
  - JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript).
  - Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
  - JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính.

```json
{
  "name": "John Doe",
  "age": 30.1234,
  "city": "New York",
  "isStudent": true,
  "grades": [85, 90, 78]
}

```

  ### Cấu trúc
  - Định dạng JSON sử dụng các cặp key – value để dữ liệu sử dụng.
  - Nó hỗ trợ các cấu trúc dữ liệu như đối tượng và mảng.
  - Chuỗi JSON được bao lại bởi dấu ngoặc nhọn {}.
  - Các key, valuecủa JSON bắt buộc phải đặt trong dấu nháy kép “.
  - Nếu có nhiều dữ liệu thì dùng dấu phẩy , để ngăn cách.
  - Value cho phép các kiểu dữ liệu cơ bản: numbers, String, Booleans, arrays, objects, null.
```c
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union 
    {
        int boolean;
        double number;
        char *string;
        struct 
        {
            struct JsonValue *values;
            size_t count;
        } array;
        struct 
        {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;
```

</details>











# Lesson 10: Liked List
<details>
  <summary>Chi tiết</summary>


  ### 1. Định Nghĩa
  - Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. 
  - Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút là một cấu trúc có hai thành phần:
    + Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó.
    + Thành phần liên kết: lưu địa chỉ phần tử liên kết với nó trong danh sách, nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL.
  #### Cấu trúc của 1 node trong Singly Linked List.
```c
typedef struct node
{
    int value;
    struct node* next;
}node;
```
  
  ### 2. Đặc điểm
  - Được cấp phát bộ nhớ khi chạy chương trình.
  - Có thể thay đổi kích thước qua việc thêm, xóa phần tử.
  - Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM.
  - Các phần tử được lưu trữ ngẫu nhiên (không liên tiếp) trong RAM.
  - Có hai loại linked list chính:
    + Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
    + Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.

  
  ### 3. So sánh với array

  |Array (mảng)|Linked List (danh sách liên kết)|
  |:----------|:-----------|
  |- Bộ nhớ được cấp phát liên tiếp nhau|- Bộ nhớ lưu trữ các node không cần liên tiếp nhau, các node chứa con trỏ liên kết đến các node cạnh nó|
  |- Kích thước cố định sau khi cấp phát|- Kích thước linh hoạt, có thể thay đổi bằng cách thêm, xóa node|
  |- Có thể truy cập bất cứ phần tử nào ngay lập tức với số chỉ của nó trong mảng|- Muốn truy cập tới phần tử thứ i phải duyệt danh sách từ vị trí đầu tới i|
  |- Thêm hoặc xóa phần tử rất khó khăn, phải dịch chuyển các phần tử khác để giữ tính liên tiếp trong bộ nhớ|- Thêm xóa rất dễ dàng bằng việc sửa con trỏ liên kết node|
  |- Bố nhớ chỉ cần lưu trữ các phần tử|- Bộ nhớ cần lưu trữ phần tử và con trỏ liên kết => tốn bộ nhớ hơn|
  |- Array được sử dụng khi ta cần sử dụng để lưu trữ mảng với số lượng phần tử đã biết trước và phục vụ truy xuất các phẩn tử ngẫy nhiên nhanh|- Linked list được sử dụng khi ta càn sử dụng để lưu trữ mảng linh hoạt về số lượng và có thể thêm xóa các phần tử vào vị trí bất kì dễ dàng|
  
</details>













# Lesson 11: STACK_QUEUE
<details>
  <summary>Chi tiết</summary>

Ngăn xếp (stack) và hàng đợi (queue) là hai cấu trúc dữ liệu cơ bản trong lập trình. Chúng có cách tổ chức và thao tác với dữ liệu khác nhau, phù hợp với những bài toán cụ thể.
  ### 1. Stack (ngăn xếp)
  #### Nguyên tắc hoạt động:
  - Cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra.
  #### Các thao tác chính:
  - Push: Thêm một phần tử vào đỉnh ngăn xếp.
  - Pop: Loại bỏ và trả về phần tử ở đỉnh ngăn xếp.
  - Peek/Top: Trả về phần tử ở đỉnh ngăn xếp mà không loại bỏ nó.
  #### Ứng dụng:
  - Duyệt biểu thức toán học và xử lý dấu ngoặc.
  - Quản lý lời gọi hàm trong ngôn ngữ lập trình.
  - Thuật toán duyệt đồ thị (DFS - Depth First Search).

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty( Stack stack) {
    return stack.top == -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}
```
  
  ### 2. Queue (hàng đợi)
  Nguyên tắc hoạt động:
  - Cấu trúc dữ liệu tuân theo nguyên tắc "First In, First Out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra.

  Các thao tác chính:
  - Enqueue: Thêm một phần tử vào cuối hàng đợi.
  - Dequeue: Loại bỏ và trả về phần tử ở đầu hàng đợi.
  - Peek/Front: Trả về phần tử ở đầu hàng đợi mà không loại bỏ nó.

  Ứng dụng:
  - Truyền/nhận dữ liệu từ vi điều khiển.
  - Quản lý tác vụ trong các hệ thống điều hành.
  - Thuật toán duyệt đồ thị (BFS - Breadth First Search).

```c
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 6);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    enqueue(&queue, 70);                                    // Queue overflow

    printf("Front element: %d\n", front(queue));            // 10

    printf("Dequeue element: %d\n", dequeue(&queue));       // 10
    printf("Dequeue element: %d\n", dequeue(&queue));       // 20

    printf("Front element: %d\n", front(queue));            // 30

    enqueue(&queue, 70);                                    
    enqueue(&queue, 80);                                    
    printf("Dequeue element: %d\n", dequeue(&queue));       // 30
    printf("Front element: %d\n", front(queue));            // 40

    return 0;
}

```
    
  ### 3. So sánh 
 |Đặc Điểm|	Ngăn Xếp (Stack)|	Hàng Đợi (Queue)|
 |:---|:---|:---|
|Nguyên tắc|	LIFO (Last In, First Out)|	FIFO (First In, First Out)|
|Thao tác chính|	Push, Pop, Peek|	Enqueue, Dequeue, Peek|
|Truy cập|	Truy cập phần tử cuối cùng (đỉnh)|	Truy cập phần tử đầu tiên (front)|
|Ứng dụng|	Quản lý lời gọi hàm, xử lý dấu ngoặc, thuật toán DFS|  Quản lý tác vụ, xử lý yêu cầu hệ thống, thuật toán BFS|
|Sử dụng|  Xử lý các tác vụ theo nguyên tắc LIFO như quản lý lời gọi hàm hoặc duyệt đồ thị theo chiều sâu |  Xử lý các tác vụ theo nguyên tắc FIFO như quản lý tác vụ hoặc duyệt đồ thị theo chiều rộng|


</details>















# Lesson 12:
<details>
  <summary>Chi tiết</summary>

  ### Tiêu đề phụ 1.3
  Nội dung của tiêu đề phụ 1.3.
  
  ### Tiêu đề phụ 1.3
  Nội dung của tiêu đề phụ 1.3.
  
  ### Tiêu đề phụ 1.3
  Nội dung của tiêu đề phụ 1.3.

</details>
