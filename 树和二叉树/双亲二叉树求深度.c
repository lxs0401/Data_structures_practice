#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX 10
typedef struct PTNode
{
	char data;
	int id;
	int perent;
}PTNode;
typedef struct
{
	PTNode nodes [TREE_MAX];
	int n;
}PTree;
PTree creat_tree (char *size , int len);
int max_scs_sd (PTree tree);
int main ()
{
	PTree a;
	a = creat_tree ("1(2(3)(4)(5(6(7))))",19);
	printf ("%d",max_scs_sd (a));
}
int max_scs_sd (PTree tree)
{
	int max = 0;
	PTNode *point;
	
	for (int x = tree . n ; x >= 0 ; x --)
	{
		int n = 0;
		point = &tree . nodes [x];
		while (point -> perent != -1)
		{
			point = &tree . nodes [point -> perent];
			n += 1;
		}
		if (n > max)
		{
			max = n;
		}
	}
	return max + 1;
}
PTree creat_tree (char *size , int len)
{
	PTree tree;
	PTNode **zhan , *point;
	int n = 0;
	
	zhan = (PTNode **) malloc (sizeof (PTNode *) * TREE_MAX);
	
	tree . n = 0;
	point = & tree . nodes [0];
	point -> perent = -1;
	point -> id = 0;
	for (int x = 0 ; x < len ; x ++)
	{
		if (size [x] == '(')
		{
			zhan [n] = point;
			n += 1;
			tree . n += 1;
			point = &tree . nodes [tree . n];
			point -> id = tree . n;
			point -> perent = zhan [n - 1] -> id;
		}
		else if (size [x] == ')')
		{
			point = zhan [n - 1];
			n -= 1;
		}
		else
		{
			point -> data = size [x];
		}
	}
	return tree;
}