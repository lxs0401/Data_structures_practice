#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild;
}BiTNode , *BiTree;

char qdwq_ecs(BiTree tree)
{
	int x = 0,y = 0;
	if (tree -> lchild)
	{
		if ( qdwq_ecs(tree -> lchild) == 0)
		{
			return 0;
		}
		x = 1;
	}
	
	if (tree -> rchild)
	{
		if (qdwq_ecs (tree -> rchild) == 0)
		{
			return 0;
		}
		y = 1;
	}
	if (x ^ y)return 0;
	return 1;
}
