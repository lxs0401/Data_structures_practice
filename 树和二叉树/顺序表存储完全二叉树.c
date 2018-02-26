#include <stdio.h>
#include <stdlib.h>
#define TREE_MAX 100
#define MAX_POINT 50
struct file 
{
	char data;
	int lchild,rchild;
};
typedef struct list
{
	struct file *elem;
	int last;
}List;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;


List zhwqsx_ecs (BiTree tree)
{
	BiTree *zhan , *zhan2 , *temp;
	List s_tree;
	int n = 0 , x ,y = 0;
	int range = 0;
	int hx;
	
	zhan = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT);
	zhan2 = (BiTree *) malloc (sizeof (BiTree) * MAX_POINT);
	
	s_tree . elem = (struct file *) malloc (sizeof (BiTree) * MAX_POINT);
	s_tree . last = 0;
	zhan[0] = tree;
	n += 1;
	do
	{
		hx = 0;
		for (x = 0; x < n ; x ++)
		{
			printf ("%c",zhan[x]->data);
			s_tree.elem [s_tree.last].data = zhan[x] -> data;
			if (zhan[x] -> lchild)
			{
				hx = 1;
				s_tree.elem [s_tree.last].lchild = s_tree.last * 2 + 1;
				zhan2[y] = zhan [x] -> lchild;
				y += 1;
			}
			if (zhan[x] -> rchild)
			{
				hx = 1;
				s_tree.elem [s_tree.last].rchild = s_tree.last * 2 + 2;
				zhan2[y] = zhan[x] -> rchild;
				y += 1;
			}
			s_tree.last += 1;
		}
		n = y;
		y = 0;
		temp = zhan2;
		zhan2 = zhan;
		zhan = temp;
	}while (hx);
	return s_tree;
}

