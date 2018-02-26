#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100
typedef struct BiTNode {
	unsigned int route : 1;
	char data;
	struct BiTNode *lchild , *rchild; 
}BiTNode , *BiTree;

BiTree cj_ecs (char *size , int len);
void hxbl_ecs (BiTree tree);
int main()
{
	BiTree a;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	hxbl_ecs (a);
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
void hxbl_ecs (BiTree tree)
{
	BiTree *zhan , point;
	int n = 0;
	
	zhan = (BiTree *) malloc (sizeof (BiTree) * 10);
	point = tree;
	
	do
	{
		while (point)
		{
			point -> route = 0;
			zhan[n] = point;
			n ++;
			point = point -> lchild;
		}
		
		while (n > 0 && ( (! (zhan[n - 1] -> rchild) ) || (zhan[n - 1] -> route) ) )
		{
			printf ("%c,",zhan[n - 1] -> data);
			n --;
		}
		if (n > 0)
		{
			zhan[n - 1] -> route = 1;
			point = zhan[n - 1];
			point = point -> rchild;
		}
	}while (n > 0);
}
