#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}
void quickSort(int *data,int len)
{
    int i = -1,j = 0;
    int temp = data[len - 1];
    if(len <= 0){
        return ;
    }
    while(j < len - 1)
    {
        if(data[j] <= temp)
        {
            i += 1;
            swap(data + i,data + j);
        }
        j += 1;
    }
    i += 1;
    swap(data + i,data + len - 1);
    quickSort(data,i);
    quickSort(data + i + 1,len - i - 1);
}
int main ()
{
    int data[20];
    int len;
    scanf("%d",&len);
    for (int i = 0 ; i < len ; i ++)
    {
        scanf("%d",data + i);
    }    
    quickSort(data , len);
    for(int i = 0 ; i < len ; i ++)
    {
        printf("%d ",data[i]);
    }
}