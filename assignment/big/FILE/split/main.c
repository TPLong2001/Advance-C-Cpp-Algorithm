#include "handleFile.h"
#include "handleSort.h"

/////////main
int main(int argv, char const *argc[])
{
    if(!getDataFromFile("melb_data.csv","r",MAXLINE))
    {
        return 0;
    }

    if(!printDataToFile("HomeData.csv","w+",MAXLINE))
    {
        return 0;
    }

    mergeSort(home_data,0,MAXLINE);
    if(!printDataToFile("YearBuilt.csv","w+",MAXLINE))
    {
        return 0;
    }

    radixSort(home_data,MAXLINE);
    if(!printDataToFile("Postcode.csv","w+",MAXLINE))
    {
        return 0;
    }

    bestSeller(home_data,MAXLINE);

    return 0;
}