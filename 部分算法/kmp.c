#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[1000001],arrb[1000001];
int *enableKMP (char *arr , int len)
{
	int *data =(int *) malloc (sizeof(int) * len + 1);
	int i=0,j = -1;
	data[0] = -1;
	while (i < len)
	{
		if (j == -1 || arr[j] == arr[i])
		{
			j += 1;
			i += 1;
			data[i] = j;
		}
		else
		{
			j = data[j];
		}

	}
	return data;
}

int main ()
{
	while(scanf("%s%s",arr,arrb) != EOF)
	{
		printf("%d\n",kmp(arr,arrb));
	}
}