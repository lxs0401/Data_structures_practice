#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100

typedef struct BiTNode {
	char route : 1;
	char data;
	struct BiTNode *lchild , *rchild , *perent;
}BiTNode , *BiTree;

BiTree cj_ecs (char *size , int len) //创建双亲节点二叉树
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
			
			a [x] -> perent = a [x - 1];
			
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
			
			a [x] -> perent = a [x - 1];
			
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
	ret -> perent = NULL;
	return ret;
}
void hxb_lecs(BiTree tree)
{
	BiTree point = tree;
	
	while (point)
	{
		while (point -> lchild)
		{
			point -> route = 0;
			point = point -> lchild;
		}
		
		while  (point && ( (point -> route) ||  (! point -> rchild) ) )  
		{
			printf ("%c,",point -> data);
			point = point -> perent;
		}
		
		if ( point )
		{
			point -> route = 1;
			point = point -> rchild;
		}
		
	}
}
int main()
{
	BiTree a;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	hxb_lecs (a);
}