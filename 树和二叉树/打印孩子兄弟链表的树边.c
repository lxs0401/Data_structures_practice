#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100
typedef struct CSNode 
{
	char data;
	struct CSNode *child,*silb;
}CSNode , *CSTree;
CSTree cj_xdt(char *tree_c , int len);
void dy_sb(CSTree tree , CSTree percent);
int main ()
{
	CSTree a;
	a = cj_xdt ("1(2(3)(4)(5(6)))",16);
	dy_sb (a,NULL);
}

void dy_sb(CSTree tree , CSTree percent)
{
	CSTree tree_ = tree;
	
	if (percent != NULL)
	{
			printf("(%c,%c)",percent -> data , tree_ -> data);
	}
	if (tree_ -> child)
	{
			dy_sb (tree_ -> child , tree_);
	}
	
	while (tree_ -> silb)
	{
		tree_ = tree_ -> silb;
		if (percent != NULL)
		{
			printf("(%c,%c)",percent -> data , tree_ -> data);
		}
		if (tree_ -> child)
		{
			dy_sb (tree_ -> child , tree_);
		}
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