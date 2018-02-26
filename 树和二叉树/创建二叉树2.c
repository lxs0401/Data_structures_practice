#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode {
	char data;
	struct BiTNode * percent;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;

BiTree fhbt_ecs (char (*tree)[3] , int len);

int main()
{
	char x[10][3] = {
		"ABL",
		"ACR",
		"BDL",
		"BER",
		"CFL",
		"CGR",
		"D^^",
		"E^^",
		"F^^",
		"G^^"
	};
	fhbt_ecs (x,10);
}
BiTree fhbt_ecs (char (*tree)[3] , int len)
{
	BiTree b_tree, *zhan;                                                                                                            
	int n , x = 0;
	
	zhan = (BiTree *) malloc (sizeof (BiTree) * len);
	for (int x = 0 ; x < len ; x++)
	{
		zhan[x] = NULL;
	}
	for (n = 0 ; n < len ; n++)
	{
		if ( zhan[(tree[n][0])-'A'] == NULL)
		{
			zhan[(tree[n][0])-'A'] = (BiTree) malloc(sizeof (BiTNode));
		}
	}
	b_tree = zhan[0];
	for (n = 0 ; n < len ; n++)
	{
		if ( tree[n][2] == 'L')
		{
			zhan[(tree[n][0])-'A'] -> lchild = zhan[(tree[n][1])-'A'];
		}else if ( tree[n][2] == 'R')
		{
			zhan[(tree[n][0])-'A'] -> rchild = zhan[(tree[n][1])-'A'];
		}else {
			zhan[(tree[n][0])-'A'] -> lchild = NULL;
			zhan[(tree[n][0])-'A'] -> rchild = NULL;
		}
	}
	return b_tree;
}
