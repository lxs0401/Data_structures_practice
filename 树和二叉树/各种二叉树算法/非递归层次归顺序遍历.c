#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50

typedef struct BiTNode 
{
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;



void sxbl_ecs(BiTree tree)
{
	BiTree *zhan,*zhan2,point;
	BiTree *temp;
	int	hs = 0;
	int n = 0, x = 0 , y = 0;
	
	zhan = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT );
	zhan2 = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT );
	
	zhan[n] = tree;
	n += 1;
	
	do
	{
		hs = 0;
		while (y < n)
		{
			printf ("%c ",zhan[y] -> data);
			if (zhan[y] -> lchild)
			{
				hs = 1;
				zhan2[x] = zhan[y] -> lchild;
				x += 1;
			}
			if (zhan[y] -> rchild)
			{
				hs = 1;
				zhan2[x] = zhan[y] -> rchild;
				x += 1;
			}
			y += 1;
		}
		n = x;
		y = 0;
		x = 0;
		temp = zhan;
		zhan = zhan2;
		zhan2 = temp;
	}while (hs);
	
} 
