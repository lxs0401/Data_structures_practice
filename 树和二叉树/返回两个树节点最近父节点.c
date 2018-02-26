#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild;
}BiTNode , *BiTree;

char cztf_ecs(BiTree tree,BiTree a,BiTree b,BiTree *c)
{
	char d = 0,e = 0;
	
	if (tree == a) 
	{
		return 1;
	}
	if (tree == b)
	{
		return 2;
	}
	if (tree -> lchild)
	{
		d = cztf_ecs (tree -> lchild,a,b,c);
	}
	if (tree -> rchild)
	{
		e = cztf_ecs (tree -> rchild,a,b,c);
	}
	if (d + e == 3)
	{
		*c = tree;
		return 0;
	}else {
		if (d)
		{
			return d;
		}
		if (e)
		{
			return e;
		}
	}
}

