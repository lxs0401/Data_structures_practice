#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50
#define TREE_MAX 50
#define MAX_TREE 20

#define LCHILD 1
#define RCHILD 2

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

BiTree fz_tree (BiTree tree , int l_or_r , BiTree percent);
BiTree cj_ecs (char *size , int len);


int main (void)
{
	BiTree a;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>",19);
	a = fz_tree (a,0,NULL);
	
}
BiTree fz_tree (BiTree tree , int l_or_r , BiTree percent)
{
	BiTree new_root = NULL , p = NULL;
	if (tree == NULL)
	{
		return NULL;
	}
	
	new_root = fz_tree(tree -> lchild,LCHILD,tree);
	p = fz_tree(tree -> rchild,RCHILD,tree);
	if (p != NULL)
	{
		new_root = p;
	}
	
	if ( percent != NULL )
	{
		if (l_or_r == LCHILD)
		{
			tree -> lchild = percent;
			tree -> rchild = NULL;
		}
		else if (l_or_r == RCHILD)
		{
			tree -> rchild = percent;
			tree -> lchild = NULL;
		}
	}
	else
	{
		tree -> rchild = NULL;
		tree -> lchild = NULL;
	}
	
	if (new_root == NULL)
	{
		return tree;
	}
	else
	{
		return new_root;
	}	
}

BiTree cj_ecs (char *size , int len) //创建二叉树
{
	BiTree *a , ret;
	int x = 0;
	
	a = (BiTree *) malloc (sizeof (BiTree) * TREE_MAX);
	ret = (BiTree) malloc (sizeof (BiTNode));
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