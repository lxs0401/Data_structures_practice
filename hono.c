#include <stdio.h>
#include <stdlib.h>
typedef struct ta
{
	int pan[10];
	int num;
	char zi;
}Ta;
Ta *ta;
int nn;
void exchange (Ta *x , Ta *y) //将X的第一个盘放到y上
{
    
	printf ("Move disk %d from %c to %c",x->pan[x -> num - 1],x -> zi,y -> zi);
	y -> pan[y -> num] = x -> pan[x -> num - 1];
	x -> num -= 1;
	y -> num += 1;
    if (ta -> num != nn)printf("\n");
}
void hanno(int n , Ta *x , Ta *y , Ta *z)
{
	if ( n == 1)
	{
        exchange (x,z);
		return;
	}else {
		hanno (n - 1 , x , z , y);
        exchange (x,z);
        hanno (n - 1, y , x , z);

	}
}
int main()
{
	Ta x,y,z;
	int n,i;
    scanf ("%d",&n);
    x . num = y . num = z . num = 0;
	for (i = 0 ; i < n ;i ++)
	{
		x . pan[x . num] = n-i;
		x . num += 1;
    }
    x.zi = 'A';
	y.zi = 'B';
    z.zi = 'C';
    nn = n;
    ta = &z;
	hanno(n,&x,&y,&z);
}