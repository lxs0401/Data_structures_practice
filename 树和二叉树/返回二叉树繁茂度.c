#include <stdio.h>
#include <stdlib.h>
#define MAX_POINT 50

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;



int fhecs_sd (BiTree tree)
{
	BiTree *zhan,*zhan2,*temp;
	int n = 0 , x , y = 0;
	int s = 1 , h = 0;
	int hx;
	
	zhan = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT);
	zhan2 = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT);
	zhan[0] = tree;
	n += 1;
	
	do
	{
		hx = 0;
		for( x = 0 ; x < n ; x++)
		{
			printf("%c",zhan[x] -> data);
			if (zhan[x] -> lchild)
			{
				hx = 1;
				zhan2[y] = zhan[x] -> lchild;
				y += 1;
			}
			if (zhan[x] -> rchild)
			{
				hx = 1;
				zhan2[y] = zhan[x] -> rchild;
				y += 1;
			}
		}
		h += 1;
		n = y;
		if (y > s)
		{
			s = y;
		}
		y = 0;
		temp = zhan;
		zhan = zhan2;
		zhan2 = temp;
	} while (hx);
	
	return h * s;
}


