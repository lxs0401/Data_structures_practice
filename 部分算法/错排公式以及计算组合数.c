#include <stdio.h>
#include <stdlib.h>
long long c(long long n,long long m)
{
	if (m == 0)return 1;
	else if (n == 1)return 1;
	else if (m == n)return 1;
	else 
	{
		return c(n-1,m-1)+c(n-1,m);
	}
}
int main ()
{
    long long d[21] = {0,0,1};
    int time;
    for (int i = 3 ; i <= 20 ; i ++)
    {
        d[i] = (i-1)*(d[i - 1]+d[i - 2]);
    }
    scanf("%d",&time);
    for (int t = 0 ; t < time ; t ++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",c(a,b)*d[b]);
    }
}
