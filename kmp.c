#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[1000001],arrb[1000001];
int *enableKMP (char *arr , int len)
{
    int *data =(int *) malloc (sizeof(int) * len + 1);
    int i=0,j = -1;
    data[0] = -1;
    while (i < len)
    {
        if (j == -1 || arr[j] == arr[i])
        {
            j += 1;
            i += 1;
            data[i] = j;
        }
        else
        {
            j = data[j];
        }

    }
    return data;
}
int kmp (char *a,char *b)
{
    int i,j;
    int len2 = strlen(b),len = strlen(a);
    int *kmp_list = enableKMP(b,len);
    for (i = 0 , j = 0; i < len && j < len2 ; i ++)
    {
        if (i < len && j < len2 && a[i] == b[j]) j += 1;
        else j = kmp_list[j] == -1 ? 0 : kmp_list[j];
    }
    free(kmp_list);
    if (j == len2) return i-j+1;
    else return -1;
}
int main ()
{
    while(scanf("%s%s",arr,arrb) != EOF)
    {
        printf("%d\n",kmp(arr,arrb));
    }
}