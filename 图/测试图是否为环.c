#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int test (char *s , char *fst , char *lst , char *point_size , int point_num);
int test_loop (char *s , char *fst , char *lst);

int main ()
{
	char *s = "12", *fst = "01A" , *lst = "01A";
	printf ("%d",test_loop(s,fst,lst));
}
int test (char *s , char *fst , char *lst , char *point_size , int point_num)
{
	for (int num = 0 ; num < strlen (fst) ; num ++)
	{
		if (point_size [num] == FALSE && fst[num] != 'A')
		{
			for (char num2 = fst[num] - '0' ; num2 < lst[num] - '0' ; num2 ++)
			{
				if (s[num2] - '0' == point_num)
				{
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}
int test_loop (char *s , char *fst , char *lst)
{
	char *point_size;
	int size_num , size_num2;

	size_num = strlen( fst );

	point_size = (char *) malloc (sizeof (char) * 10);
	for (int num = 0 ; num < 10 ; num ++)
	{
		point_size [num] = FALSE;
	}
	while (size_num > 0)
	{
		size_num2 = size_num;
		for (int point_num = 0 ; point_num < strlen (fst) ; point_num ++)
		{
			if (point_size [point_num] == FALSE)
			{
				if (test (s,fst,lst,point_size,point_num) == TRUE)
				{
					point_size [point_num] = TRUE;
					size_num -= 1;
					break;
				}
			}
		}
		if (size_num == size_num2)
		{
			if (size_num > 0)return TRUE;
			else return FALSE;
		}
	}
	return FALSE;
}
