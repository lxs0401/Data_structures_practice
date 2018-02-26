#include <stdio.h>
#include <stdlib.h>

struct a{
	int x,y;
	int xi;
};
void cr_paixi(struct a *abc,int strle_n)  //插入排序
{
	struct a temp;
	for(int num = 1 ; num < strle_n ; num ++ )
	{
		for(int t_num = num ; t_num && ( abc[t_num].x + abc[t_num].x < abc[t_num-1].y + abc[t_num-1].y ); t_num -- )
		{
			temp = abc[t_num];
			abc[t_num] = abc[t_num-1];
			abc[t_num-1] = temp;
		}
	}
}
void fn(int (*str)[3],int x,int y)
{
	struct a *a;
	int q = 0;
	a = (struct a *)malloc(sizeof(struct a)*10);
	for(int i = 0 ; i < x ; i ++ ){
		for(int o = 0; o < y ; o ++ ){
			if( str[i][o] ){
				a[q].x = i;
				a[q].y = o;
				a[q++].xi = str[i][o];
			}
		}
	}
	cr_paixi(a,q);
	for(int aa = 0 ; aa < q ; aa ++ ){
		printf("%c%dx^%dy^%d ",a[aa].xi >= 0 ? '+':'-',a[aa].xi,a[aa].x,a[aa].y);
	}
}
int main()
{
	int i[3][3]={
		{0,1,0},
		{1,0,0},
		{0,1,2}
	};
	fn(i,3,3);
}