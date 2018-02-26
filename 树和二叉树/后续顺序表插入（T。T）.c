#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50
#define TREE_MAX 100


typedef struct BiTNode
{
	char data;
	char ltag , rtag;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

BiTree cj_ecs (char *size , int len);
BiTree ecs_cr (BiTree tree, BiTree x);
void sxh_ecs (BiTree tree);


BiTree pre = NULL;

int main ()
{
	BiTree a , b;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	b = cj_ecs ("8(9(0))",7);
	sxh_ecs (a);
	sxh_ecs (b);
	
	ecs_cr (a -> rchild,b);
	
}
BiTree ecs_cr (BiTree tree, BiTree x)
{
	BiTree point ,point2 , point3;
	point  = x;
	if (tree -> ltag == 0)
	{
		x -> rchild = tree;
		while (point -> ltag == 1)
		{
			point = point -> lchild;
		}
		point -> lchild = tree -> lchild;
		tree -> lchild = x;
		tree -> ltag = 1;
	}else {
		point3 = tree -> lchild;
		while (point3 -> ltag == 1)
		{
			point3 = point3 -> lchild;
		}
		while (point -> ltag == 1)
		{
			// point = x;
			point = point -> lchild;
		}
		
		point -> lchild = point3 -> lchild;
		point3 -> lchild = x -> lchild;  //?
		x -> lchild -> rchild = point3;
		x -> rtag = 1;
		x -> rchild = tree -> lchild;
		tree -> lchild = x;
		
		if (tree -> rtag == 0)
		{
			if (tree -> rchild -> ltag == 0)
			{
				tree -> rchild -> lchild = tree -> lchild;
			}
		}else {
			point2 = tree -> rchild;
			while (point2 -> ltag == 1)
			{
				point2 = point2 -> lchild;
			}
			point2 -> lchild = tree -> lchild;
		}
	}
}


void sxh_ecs (BiTree tree)
{
	if (tree)
	{
		sxh_ecs (tree -> lchild);
		sxh_ecs (tree -> rchild);
		tree -> ltag = (tree -> lchild) ? 1 : 0;
		tree -> rtag = (tree -> rchild) ? 1 : 0;
		if (pre)
		{
			if (!pre -> rchild)
			{
				pre -> rtag = 0;
				pre -> rchild = tree;
			}
			if (!tree -> lchild)
			{
				tree -> ltag = 0;
				tree -> lchild = pre;
			}
		}else if (!tree -> ltag){
			tree -> lchild = NULL;
		}
		pre =  tree;
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