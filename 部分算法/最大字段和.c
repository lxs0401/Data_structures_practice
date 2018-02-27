#include <stdlib.h>
#include<stdio.h>
int main()
{
    int count;
    int a[100];
    int b[100];
    int i;
    int max;
    scanf("%d",&count);
    for(i=0; i<count; i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=a[0];
    max=b[0];
    for(i=1; i<count; i++)
    {
        if(b[i-1]>0)
            b[i]=b[i-1]+a[i];
        else
            b[i]=a[i];
        if(b[i]>max)
            max=b[i];
    }
    printf("%d\n",max);
    return 0;
}