#include <stdio.h>
#include <stdlib.h>

int * get_next(char *arr,int len)
{
	int i = 0,j = -1;
	int *next;
	next = (int *)malloc(sizeof(int)*len);
	
	next[0] = -1;
	while (i < len)
	{
		if( j < 0 || arr [j] == arr[i] )
		{
			i += 1;
			j += 1;
			next [i] = j;
		}else{
			j = next [j];
		}
	}
	return next;
}
int main()
{
	char *a = "1234567",*b = "12341234567";
	int *next;
	int x = -1, q = -1;
	
	next = get_next(a,7);
	
	while ((x < 11) && !(q >= 0 && a[q] == '\0'))
	{
		if( (q < 0) || (b [x] == a [q]) ){
			x += 1 , q += 1;
		}else{
			q = next [q];
		}
	}
	if( (q >= 0) && (a[q] == '\0') )
	{
		printf("YES");
	}else {
		printf("NO");
	}
}