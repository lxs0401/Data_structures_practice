#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search (char *str,char key,int len);
int main ()
{
    char *str = (char *) malloc (sizeof(char) * 20);
    int len;
    char key;
    scanf ("%s",str);
    len = strlen(str);
    for (int i = 0 ; i < len ; i ++)
    {
        int mid = search(str,str[i],len);
        printf("%c",str[mid]);
    }
}
int search (char *str,char key,int len)
{
    int high = len - 1 , low = 0 , mid = (high + low) / 2;
    while(high >= low)
    {
        if (str[mid] == key) return mid;
        else if (str[mid] > key)
        {
            high = mid - 1;
            mid = (high + low) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (high + low) / 2;
        }
    }
    return -1;
}