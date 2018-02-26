#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100

typedef struct BiTNode {
	char route : 1;
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

BiTree cj_ecs (char *size , int len);
int yzjd_sm (BiTree tree);
int main()
{
	BiTree a;
	a = cj_ecs ("1(2(4)<5>)<3(6)<7>>" , 19);
	printf("%d",yzjd_sm(a) - 1);
}

int yzjd_sm (BiTree tree)
{
	if (tree -> lchild == NULL && tree -> rchild == NULL)
	{
		return 1;
	}
	else
	{
		int num = 0;
		
		num += (tree -> lchild != NULL) ? yzjd_sm (tree -> lchild) : 0;
		num += (tree -> rchild != NULL) ? yzjd_sm (tree -> rchild) : 0;
		return num;
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