#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 26

char zf_sb (char *cha_r)
{
	char a = 1;
	for (int x = 0; cha_r [ x ] ; x ++)
	{
		if (cha_r [x] == '0')
		{
			if (a * 2 > 26)return 0;
			a *= 2;
		}else if (cha_r [x] == '1'){
			if ( a * 2 + 1 > 26)return 0;
			a = a * 2 + 1 ;
		}
	}

	return a + 'a' - 1;
}
int main ()
{
	printf ("%c" , zf_sb ("111"));
}