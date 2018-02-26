#include <stdio.h>
#include <malloc.h>

int q_paixu(char *size,int x,char *alpha,int max)
{
	int num=0;
	if(num < max){
		int cha;
		
		while( ( num < max ) && ( alpha[num] == size [x - 1]) )
		{
			alpha [num]  =  size [0];
			num ++;
		}
		if(num == max)
		{
			return 0;
		}
		for( cha=0 ; (cha < x) && (alpha[num] != size[cha]) ; cha ++ )
			;
		
		if( (cha < x ) && ( alpha [num] == size[cha] ) )
		{
			
			alpha[num] = size[cha+1];
			
		}else {
			
			return 0;
			
		}
		
		return 1;
	}else 
		return 0;
}

int main()
{
	char x[37] = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" , *a;
	a = (char *)malloc(sizeof(char)*14);
	for (int n=0; n < 13 ; n ++)
	{
		a [n] = x [0];
	}
	
	a [13] = 0;
	
	while(q_paixu(x,100,a,3))
	{
		;
	}
}
