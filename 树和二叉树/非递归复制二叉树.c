#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50


typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;


BiTree copy_ecs(BiTree tree)
{
	BiTree tree1,tree2, *zhan , *zhan2,tree3;
	int n = 0;
	tree3 = tree2 = (BiTree) malloc ( sizeof (BiTNode) );
	zhan = (BiTree *) malloc ( sizeof (BiTree) * MAX_POINT );
	zhan2 = (BiTree *) malloc ( sizeof (BiTree) * MAX_POINT );
	
	tree1 = tree;
	while (n >= 0) 
	{
		while (tree1 -> lchild)
		{
			zhan[n] = tree1;
			tree2 -> data = tree1 -> data;
			
			zhan2[n] = tree2;
			tree2 -> lchild = (BiTree) malloc (sizeof (BiTNode));
			
			tree2 = tree2 -> lchild;
			tree1 = tree1 -> lchild;
			n += 1;
		}
		
		tree2 -> data = tree1 -> data;
		tree2 -> lchild = NULL;
		while ( n >= 0 && !( tree1 -> rchild ))
		{
			tree2 -> rchild = NULL;
			if (n >= 0)
			{
				tree1 = zhan[n - 1];
				tree2 = zhan2[n - 1];
			}
			n -= 1;
		}
		if (n >= 0 && tree1 -> rchild)
		{
			tree1 = tree1 -> rchild;
			tree2 -> rchild = (BiTree) malloc (sizeof (BiTNode));
			tree2 = tree2 -> rchild;
		}
		
	}
	
	return tree3;
}

