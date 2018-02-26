#define TRUE 1
#define FLASE 0
#define TREE_MAX 100
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild;
}BiTNode , *BiTree;

int pdecs_xs (BiTree b1 , BiTree b2); //对比二叉树相似性

int pdecs_xs (BiTree b1 , BiTree b2)
{
	BiTree *zhan , *zhan2;
	int n = 0 , n2 = 0;
	zhan = (BiTree *) malloc(sizeof (BiTree) * TREE_MAX);
	zhan2 = (BiTree *) malloc(sizeof (BiTree) * TREE_MAX);
	if ( (b1 == NULL) && (b2 == NULL) )
	{
		return 1;
	}else if ( (b2 == NULL) && b1)
	{
		return 0;
	}else if ( (b1 == NULL) && b2)
	{
		return 0;
	}
	zhan [n] = b1;
	zhan2 [n2] = b2;
	n ++;
	n2 ++;
	do {
		while ( (zhan[n - 1] -> lchild) && (zhan2[n2 - 1] -> lchild) )
		{
			zhan [n] = zhan [n - 1] -> lchild;
			n ++;
			
			zhan2 [n2] = zhan2 [n2 - 1] -> lchild;
			n2 ++;			
		}
		if (zhan2 [n2 - 1] -> lchild){
			return 0;
		}else if (zhan [n - 1] -> lchild){
			return 0;
		}

		while (n && n2 && (!(zhan[n - 1] -> rchild)) && (!(zhan2 [n2 - 1] -> rchild)) )
		{
			n-- , n2 --;
		}
		if (n && n2 && (!(zhan[n - 1] -> rchild)) )
		{
			return 0;
		}else if (n && n2 && (!(zhan2 [n2 - 1] -> rchild)))
		{
			return 0;
		}
		
		if (n && n2 && (zhan[n - 1] -> rchild) && (zhan2[n2 - 1] -> rchild) )
		{
			zhan [n - 1] = zhan [n - 1] -> rchild;
			zhan2 [n2 - 1] = zhan2 [n2 - 1] -> rchild;
		}
		
	}while (n);
	
	return 1;
}









