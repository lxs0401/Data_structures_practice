#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX 100
#define MAX_POINT 50

typedef struct BiTNode {
	int DescNum;
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;



int ecs_dsecnum (BiTree tree)
{
	int a = 0,b = 0;
	
	if (tree -> lchild)
	{
		a = ecs_dsecnum (tree -> lchild);
	}
	if (tree -> rchild)
	{
		b = ecs_dsecnum (tree -> rchild);
	}
	if (a + b > 0)
	{
		tree -> DescNum = a + b;
		return a + b + 1;
	}
	else
	{
		tree -> DescNum = 0;
		return 1;
	}
	
}
