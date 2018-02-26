#include <stdio.h>
#include <stdlib.h>

struct ma_dian{
	int x,y,type;
};

char ma( int (*i)[3] , int x , int y )
{
	int n = 0;
	while ( n < 3 )
	{
		if ( i[x][n] > i[x][y] )
		{
			return 0;
		}
		n ++;
	}
	n = 0;
	
	while ( n < 3 )
	{
		if ( i [n][y] < i [x][y] )
		{
			return 0;
		}
		n ++;
	}
	return 1;
}
struct ma_dian * jsma_dian(int (*i)[3],int xl,int yl)
{
	struct ma_dian *a;
	int num = 0;
	int n = 0;
	a = (struct ma_dian *) malloc( sizeof(struct ma_dian) * 25);
	
	for (int x = 0; x < xl; x ++)
	{
		for (int y = 0; y < yl ; y ++)
		{
			if ( ma(i,x,y) == 1 )
			{
				a[n].x = xl;
				a[n].y = yl;
				n ++;
			}
		}
	}
	a[num].type=123;
}
int main()
{
	int x[3][3]={
		{1,2,3},{1,2,4},{2,3,5}
	};
	struct ma_dian *a;
	a= jsma_dian(x,3,3);
}