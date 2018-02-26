#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

void del_ecs(BiTree tree , int *x)
{
	if (*x == 0)
	{
		if (tree -> lchild)
		{
			del_ecs(tree -> lchild,x);
		}
		if (tree -> rchild)
		{
			del_ecs(tree -> rchild,x);
		}
		free (tree -> lchild);
		free (tree -> rchild);
		tree -> lchild = NULL;
		tree -> rchild = NULL;
	}else {
		
		if (tree -> lchild)
		{
			*x -= 1;
			del_ecs(tree -> lchild , x);
			if (*x <= 0) return;
		}
		if (tree -> rchild)
		{
			*x -= 1;
			del_ecs(tree -> rchild , x);
			if (*x <= 0) return;
		}
	}
}
