#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100
typedef struct CSNode 
{
	char data;
	struct CSNode *child,*silb;
}CSNode , *CSTree;
int max_tree_d (CSTree tree);
CSTree cj_xdt(char *tree_c , int len);

int main ()
{
	CSTree a;
	a = cj_xdt ("1(2(3)(4)(5(6)))",16);
	printf ("%d",max_tree_d (a));
}

int max_tree_d (CSTree tree)
{
	CSTree point = tree;
	int n = 1, max = 1;
	int a; 
	if (tree -> child)
	{
		if ( (a = max_tree_d(tree -> child)) > max) 
		{
			max = a;
		}
	}
	
	while (point -> silb)
	{
		n += 1;
		point = point -> silb;
		if (point -> child != NULL)
		{
			a = max_tree_d(point -> child);
			if(a > max)
			{
				max = a;
			}
		}
		
	}
	if (max > n)
	{
		return max;
	}
	else
	{
		return n;
	}
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