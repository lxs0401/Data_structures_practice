#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50
#define TREE_MAX 100


typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild , *percent;
}BiTNode , *BiTree;
BiTree hxxs_ecshj (BiTree tree);
BiTree cj_ecs (char *size , int len);

int main ()
{
	BiTree a;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	
	a = hxxs_ecshj (a -> rchild -> rchild);
	
}

BiTree hxxs_ecshj (BiTree tree)
{
	if (tree -> percent -> lchild == tree && tree -> percent -> rchild)
	{
		tree = tree -> percent -> rchild;
		while (tree -> lchild)
		{
			tree = tree -> lchild;
		}
		return tree;
	}else {
		return tree -> percent;
	}
}

BiTree cj_ecs (char *size , int len) //创建二叉树
{
	BiTree *a , ret;
	int x = 0;
	
	a = (BiTree *) malloc (sizeof (BiTree) * TREE_MAX);
	ret = (BiTree) malloc (sizeof (BiTNode));
	ret -> percent = NULL;
	a [x] = ret;
	x ++;
	
	for ( int n = 0 ; n < len ; n ++ )
	{
		if (size [n] == '(')
		{
			a [x - 1] -> lchild = (BiTree) malloc (sizeof (BiTNode));
			a [x] = a [x - 1] -> lchild;
			
			a [x] -> rchild = NULL;
			a [x] -> lchild = NULL;
			a [x] -> data = 0;
			a [x] -> percent = (x > 0) ? a [x - 1] : NULL;
			x ++;
		}else if (size [n] == ')')
		{
			x --;
		}else if (size [n] == '<')
		{
			a [x - 1] -> rchild = (BiTree) malloc (sizeof (BiTNode));
			a [x] = a [x - 1] -> rchild;
			
			a [x] -> rchild = NULL;
			a [x] -> lchild = NULL;
			a [x] -> data = 0;
			a [x] -> percent = (x > 0) ? a [x - 1] : NULL;
			x ++;
		}else if (size [n] == '>')
		{
			x --;
		}else if (size[n] <= '9' || size[n] >= '0')
		{
			a [x - 1] -> data = size[n];
			a [x - 1] -> rchild = NULL;
			a [x - 1] -> lchild = NULL;
		}
	}
	return ret;
}