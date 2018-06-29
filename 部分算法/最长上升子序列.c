#include <stdio.h>
int D[1001];
int str[1001];
int dp (int from , int len)
{
	int i;
	int max = -1;
	if(from > len){
		return 0;
	}
	if (from >= 0 && D[from] > 0)return D[from];
	else
	{
		for (i = from + 1 ; i < len ; i ++)
		{
			if (from == -1 || str[from] < str[i])
			{
				D[i] = dp(i,len);
				if (max < D[i]) max = D[i];
			}
		}
		return max + 1;
	}
}
