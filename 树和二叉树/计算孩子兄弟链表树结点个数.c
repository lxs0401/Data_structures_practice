#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100
typedef struct CSNode 
{
	char data;
	struct CSNode *child,*silb;
}CSNode , *CSTree;
CSTree cj_xdt(char *tree_c , int len);
int jsecs_sm (CSTree tree);

int main ()
{
	CSTree a;
	a = cj_xdt ("1(2(3)(4)(5(6)))",16);
	printf ("%d",jsecs_sm (a));
}

int jsecs_sm (CSTree tree)
{
	CSTree *zhan , point;
	int n = 0;
	int number = 0;
	zhan = (CSTree *) malloc(sizeof (CSTree) * TREE_MAX);
	point = tree;
	
	while (n >= 0)
	{
		while (point -> child)
		{
			number += 1; 
			zhan [n] = point;
			n += 1;
			point = point -> child;
		}
		number += 1;
		while (n >= 0 && point -> silb == NULL)
		{
			point = zhan [n - 1];
			n -= 1;
		}
		if (n >= 0)
		{
			point = point -> silb;
			zhan [n - 1] = point;
		}
	}
	return number;
}


CSTree cj_xdt(char *tree_c , int len)
{
	CSTree *zhan , point , tree;
	int n = 0;
	
	zhan = (CSTree *) malloc (sizeof (CSTree) * TREE_MAX);
	tree = point = (CSTree) malloc (sizeof (CSNode));
	point -> child = NULL;
	point -> silb = NULL;
	
	for (int x = 0 ; x < len ; x ++)
	{
		if (tree_c [x] == '(')
		{
			zhan[n] = point;
			n += 1;
			if (point -> child != NULL)
			{
				point = point -> child;
				while ( point -> silb )
				{
					point = point -> silb;
				}
				point -> silb = (CSTree) malloc (sizeof (CSNode));
				point = point -> silb;
				point -> silb = NULL;
				point -> child = NULL;
			}
			else
			{
				point -> child = (CSTree) malloc (sizeof (CSNode));
				point = point -> child;
				point -> silb = NULL;
				point -> child = NULL;
			}
		}
		else if (tree_c [x] == ')')
		{
			point = zhan [n - 1];
			n -= 1;
		}
		else if (tree_c [x] >= '0' && tree_c [x] <= '9')
		{
			point -> data = tree_c [x];
		}
	}
	return tree;
}
