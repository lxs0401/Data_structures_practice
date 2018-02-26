#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100

typedef struct BiTNode {
	char route : 1;
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

BiTree cj_ecs (char *size , int len);
char ecs_k(BiTree tree , int *k);

int main()
{
	BiTree tree;
	int k = 4;
	tree = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	printf ("%c",ecs_k (tree,&k));
}
char ecs_k(BiTree tree , int *k)
{
	char data;
	if (*k <= 0)
	{
		return tree -> data;
	}
	if (tree -> lchild)
	{
		*k -= 1;
		data = ecs_k(tree -> lchild , k);
		if (*k <= 0)
		{
			return data;
		}
		
	}
	if (tree -> rchild)
	{
		*k -= 1;
		data = ecs_k(tree -> rchild , k);
		if (*k <= 0)
		{
			return data;
		}
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
