#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50
#define TREE_MAX 100
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;


char fhecs_zzls (BiTree tree , BiTree point , BiTree *list , int n)
{
	if (tree == point)
	{
		
		list [n] = tree;
		list [n + 1] = NULL;
		return 1;
	}
	
	if (tree -> lchild)
	{
		if (fhecs_zzls(tree -> lchild,point,list,n + 1))
		{
			list[n] = tree;
			return 1;
		}
	}
	if (tree -> rchild)
	{
		if (fhecs_zzls(tree -> rchild,point,list,n + 1))
		{
			list[n] = tree;
			return 1;
		}
	}
	return 0;
}
