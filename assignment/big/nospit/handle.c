#include "handle.h"

/////////////handle String
static int CharToNum(char x)
{
    return (int)x - 48;
}

static int stringToNum(char *string)
{
    int result = 0;
    int count = 0;
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        // printf("len %d string %d: %c\n",strlen(string),i,*string);
        if(*string == '.'){
            break;
        }
        result = CharToNum(*string) + count * 10;
        count = result;
        string++;
    }
    return result;
}

static void stringToArray(char *string, char array[],int size)
{
    int len = strlen(string);
    if(len > size)
    {
        len = size - 1;
    }
    for(int i = 0; i < len; i++){
        if(*string == '.'){
            array[i] = '\0';
            return;
        }
        array[i] = *string;
        string++;
    }
    array[len] = '\0';
}

static int stringCompare(const char *str1, const char *str2) 
{
   while (*str1 && (*str1 == *str2)) 
   {
        //printf("str1:%c str2:%c\n",*str1,*str2);
        str1++;
        str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}


////////////handle Sort
static void coppyDataHome(home *dich, home *nguon)
{
    dich->LandSize = nguon->LandSize;
    dich->YearBuilt = nguon->YearBuilt;
    dich->Price = nguon->Price;
    for(int i = 0; i < 11; i++)
    {
        dich->Seller[i] = nguon->Seller[i];
    }
    for(int i = 0; i < 8; i++)
    {
        dich->Postcode[i] = nguon->Postcode[i];
    }
    //printf("copy Line: %d %s %s %d %d\n\n",dich->Price, dich->Seller,  dich->Postcode, dich->LandSize, dich->YearBuilt);
}

static void merge(home home_data[], int left, int mid, int right)
{
    int i, j, k;
    int len1 = mid - left + 1;      //kich thuoc array ben trai
    int len2 = right - mid;         //kich thuoc array ben phai

    home L[len1], R[len2];          //2 array lưu trữ data khi tách đôi array ban đầu

    for(i = 0; i < len1; i++)
    {
        coppyDataHome(&L[i],&home_data[left + i]);
        //printf("L[%d]: %d %s %s %d %d\n\n", i, L[i].Price, L[i].Seller,  L[i].Postcode, L[i].LandSize, L[i].YearBuilt);
    }
    for(j = 0; j < len2; j++)
    {
        coppyDataHome(&R[j],&home_data[mid + 1 + j]);
        //printf("R[%d]: %d %s %s %d %d\n\n", j, R[j].Price, R[j].Seller,  R[j].Postcode, R[j].LandSize, R[j].YearBuilt);
    }

    i = 0;          //biến đếm phần tử array L[]
    j = 0;          //biến đếm phẩn tử array R[]     
    k = left;       //biến đếm của aray sau khi sắp xếp

    while((i < len1) && (j < len2))
    {
        if(L[i].YearBuilt < R[j].YearBuilt)
        {
            coppyDataHome(&home_data[k],&L[i]);
            i++;
            k++;
        }
        else
        {
            coppyDataHome(&home_data[k],&R[j]);
            j++;
            k++;
        }
    }

    while(i < len1)
    {
        coppyDataHome(&home_data[k],&L[i]);
        i++;
        k++;
    }

    while(j < len2)
    {
        coppyDataHome(&home_data[k],&R[j]);
        j++;
        k++;
    }
}

void mergeSort(home home_data[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;    // (left+right)/2

        mergeSort(home_data, left, mid);
        mergeSort(home_data,mid + 1, right);

        merge(home_data, left, mid, right);
    }
}


void radixSort(home home_data[], int size)
{
    int i;
    home sort[size];
    int coppyPostCode[size];
    int exp = 1;

    //coppy postcode từ data_home[] sang coppyPostCode[];
    for ( i = 0; i < size; i++)
    {
        coppyPostCode[i] = stringToNum(home_data[i].Postcode);
        //printf("PC %d: %d\n", i, coppyPostCode[i]);
    }

    //lay postcode lớn nhất
    int max = coppyPostCode[0];
    for(i = 0; i < size; i++)
    {
        if(coppyPostCode[i] > max)
        {
            max = coppyPostCode[i];
        }
    }

    while ((max / exp) > 0) 
    {
        int count[10] = {0};

        //đếm số lần xuất hiện của các chữ số theo hàng đang xét
        for ( i = 0; i < size; i++)
        {
            count[(coppyPostCode[i] / exp) % 10]++;
        }
        //lưu vị trí sắp xếp của các chữ số xuất hiện ( chỉ số của mảng)
        for ( i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        //sắp xếp data theo đúng vị trí vào mảng tạm thời sort[]
        for ( i = size - 1; i >= 0; i--)
        {
            coppyDataHome(&sort[--count[(coppyPostCode[i] / exp) % 10]],&home_data[i]);
        }
        //gan lai data đã sắp xếp về home_data[]
        for ( i = 0; i < size; i++)
        {
            coppyDataHome(&home_data[i],&sort[i]);
        }

        //lưu lại hàm coppyPostcode[] theo data mới
        for ( i = 0; i < size; i++)
        {
            coppyPostCode[i] = stringToNum(home_data[i].Postcode);
        }
        exp *= 10;
    }
    
    free(sort);
}

//////////////handle File
static void splitString(const char *str, const char *delim, int countLine) {
    char *copy = strdup(str);           //Sao chép chuỗi gốc để giữ nguyên chuỗi gốc
    char *token = copy;                 //chuỗi để xử lý thành từng phần nhỏ
    char *next_token = NULL;            //chuỗi dùng để phân tách từng phần nhỏ
    int column = 0;                     //stt cột

    while (token != NULL) {
        // Tìm vị trí của dấu phân cách tiếp theo
        next_token = strstr(token, delim);

        if (next_token != NULL) {
            // Đặt dấu kết thúc chuỗi tại vị trí của dấu phân cách
            *next_token = '\0';
            next_token += strlen(delim);    //lấy địa chỉ mới sau dấu phân cách
        }

        //5 7 10 14 16
        switch (column)
        {
        case 4:
            home_data[countLine].Price = stringToNum(token);
            break;
        case 6:
            stringToArray(token,home_data[countLine].Seller,11);
            break;
        case 9:
            stringToArray(token,home_data[countLine].Postcode,8);
            break;
        case 13:
            home_data[countLine].LandSize = stringToNum(token);
            break;
        case 15:
            home_data[countLine].YearBuilt = stringToNum(token);
            break;
        default:
            break;
        }
        token = next_token;
        column++;
    }
    //printf("splitString Line: %d %s %s %d %d\n\n",home_data[countLine].Price, home_data[countLine].Seller, home_data[countLine].Postcode,home_data[countLine].LandSize, home_data[countLine].YearBuilt);
    free(copy);  // Giải phóng bộ nhớ đã sao chép chuỗi
}

int getDataFromFile(const char *name,const char *mode, int numLine)
{
    char line[255];
    int countLine = 0;
    
    FILE*fp = fopen(name,mode);             //mỏ file chon mode read only
    if(!fp)
    {
        printf("Khong the mo file %s!\n",name);
        return 0;
    }
    fgets(line,255,fp);//read line 1

    while((!feof(fp))&&(countLine <= numLine))
    {
        fgets(line,255,fp);
        //printf("Line: %s\n",line);
        splitString(line, ",",countLine);
        countLine++;
    }
    fclose(fp);
    return 1;
}

int printDataToFile(const char *name,const char *mode,int line)
{
    int countLine = 0;
    FILE*fp = fopen(name,mode);//mỏ file chon mode read only
    if(!fp)
    {
        printf("Khong the mo file %s!\n",name);
        return 0;
    }

    fprintf(fp,"%s,%s,%s,%s,%s\n","Price","Seller","Postcode","LandSize","YearBuilt");
    while(line)
    {
        fprintf(fp,"%d,%s,%s,%d,%d\n",home_data[countLine].Price, home_data[countLine].Seller, home_data[countLine].Postcode,home_data[countLine].LandSize, home_data[countLine].YearBuilt);
        line--;
        countLine++;
    }
    fclose(fp);
    return 1;
}

void bestSeller(home data[], int size)
{
    char name[MAXLINE][11];
    int count[MAXLINE] = {0};                      //đếm số lần xuất hiện của tên theo vị trí tên phần tử trong mảng
    int sellerCount = 0;                           //số tên đã có trong name

    for (int i = 0; i < size; i++)              //duyet từng tên seller trong data[] (bằng i) so với tên đã lưu trong name[][] (bằng j)
    {
        int found = 0;
        for (int j = 0; j < sellerCount; j++)
        {
            if (stringCompare(name[j], data[i].Seller) == 0) {   //nếu trùng tên với tên đã có trong name[][] => tăng count[] đếm lên 1 và trở về duyệt data[] tiếp bằng i
                count[j]++;
                //printf("cnt %d: %d\n", j, count[j]);
                found = 1;
                break;
            }                                                     //nếu không trùng thì tiếp tục kiểm tra tên tiếp theo cho đến hết (bằng j)
        }

        //nếu kiểm tra tất cả tên trong name[][] đều không trùng thì => thêm tên vào name[][]
        if(!found)
        {
            strcpy(name[sellerCount], data[i].Seller);
            count[sellerCount]++;                           // sau khi lưu tên mới thì count tên đó = 1
            //printf("X cnt %d: %d\n", sellerCount, count[sellerCount]);
            sellerCount++;                                  // số tên tăng lên 1
        }
    }
    
    //kiểm tra tên có số lần xuất hiện nhiều nhất bằng count[]
    int max = 0;
    for (int i = 0; i < sellerCount; i++)
    {
        if(count[i] > count[max])
            max = i;
    }

    printf("Co tat ca %d Seller\n",sellerCount);
    printf("Seller ban duoc nhieu nha nhat la: %s voi %d can\n", name[max], count[max]);
}
