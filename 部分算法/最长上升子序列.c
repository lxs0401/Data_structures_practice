#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(x,y) ((x *) malloc (sizeof(x)*y))
int main ()
{
    char *s1,*s2;
    s1 = MALLOC(char,501);
    s2 = MALLOC(char,501);
    while(scanf("%s%s",s1,s2) != EOF)
    {
        int lcs[501][501] = {0};
        int l1,l2;
        int i,j;
        l1 = strlen(s1),l2 = strlen(s2);
        for (i = 0 ; i < l1 ; i ++)
        {
            for (j = 0 ; j < l2 ; j ++)
            {
                if (s1[i] == s2[j])
                {
                    if (i - 1 < 0 || j - 1 < 0)lcs[i][j] = 1;
                    else lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else 
                {
                    if (i - 1 < 0 && j - 1 < 0)lcs[i][j] = 0;
                    else if (j - 1 < 0)lcs[i][j] = lcs[i - 1][j];
                    else if (i - 1 < 0) lcs[i][j] = lcs[i][j - 1];
                    else lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
                }
            }
        }
        printf("%d\n",lcs[l1 - 1][l2 - 1]);
    }
}
