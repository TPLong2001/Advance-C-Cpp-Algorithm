#include<stdio.h>

//extern void display();
//extern int count;

void count(){
    static int a = 0;
    printf("a = %d\n",a);
    a++;
}


int main(int argv, char const *argc[])
{
    // display();

    count();
    count();
    count();

    int i = 0;


    return 0;
}

// #include <stdio.h>
// #include <time.h>

// int main() {
//     // Lưu thời điểm bắt đầu
//     clock_t start_time = clock();
//     register int i;

//     // Đoạn mã của chương trình
//     for (i = 0; i < 2000000; ++i) {
//         // Thực hiện một số công việc bất kỳ
//     }

//     // Lưu thời điểm kết thúc
//     clock_t end_time = clock();

//     // Tính thời gian chạy bằng miligiây
//     double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

//     printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

//     return 0;
// }
