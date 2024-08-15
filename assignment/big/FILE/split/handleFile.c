#include "handleFile.h"

void splitString(const char *str, const char *delim, int countLine) {
    char *copy = strdup(str);           // Sao chép chuỗi gốc để giữ nguyên chuỗi gốc
    char *token = copy;                 //chuỗi để xử lý thành từng phần nhỏ
    char *next_token = NULL;            //chuỗi dùng để phân tách từng phần nhỏ
    int column = 0;                     // stt cột

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
    //printf("Line: %d %s %s %d %d\n\n",home_data[countLine].Price, home_data[countLine].Seller, home_data[countLine].Postcode,home_data[countLine].LandSize, home_data[countLine].YearBuilt);
    free(copy);  // Giải phóng bộ nhớ đã sao chép chuỗi
}

int getDataFromFile(const char *name,const char *mode, int numLine)
{
    char line[255];
    int countLine = 0;
    
    FILE*fp = fopen(name,mode);             //mỏ file chon mode read only
    if(!fp)
    {
        printf("Khong the mo file!\n");
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
        printf("Khong the mo file!\n");
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

    printf("Seller ban duoc nhieu nha nhat la: %s voi %d can\n", name[max], count[max]);
}
