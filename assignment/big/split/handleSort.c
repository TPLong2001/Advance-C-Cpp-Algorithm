#include"handleSort.h"

void coppyDataHome(home *dich, home *nguon)
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
    //printf("XX Line: %d %s %s %d %d\n\n",dich->Price, dich->Seller,  dich->Postcode, dich->LandSize, dich->YearBuilt);
}

void merge(home home_data[], int left, int mid, int right)
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