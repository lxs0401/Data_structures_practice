#include <stdio.h>
#include <stdlib.h>

int list[5000010] = {};
int main ()
{
    list[1] = -1;
    list[0] = -1;
    int vis;
    int is = 1;
    for(int i = 2 ; i < 5000010 ; i ++)
    {
        if(list[i] == 0)
        {
            list[i] = is;
            is += 1;
            for (int j = i ; j < 5000010 ; j += i ){
                if(j != i)list[j] = -1;
            }
        }
    }
    while(scanf("%d",&vis) != EOF)
    {
        int i;
        for (i = vis ; list[i] == -1  ; i ++);
        printf("%d %d\n",list[i],i);
    }
}