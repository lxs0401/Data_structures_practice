#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX 10

typedef struct CTNode 
{
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct 
{
	char data;
	ChildPtr child;
}CTBox;
typedef struct 
{
	CTBox nodes [TREE_MAX];
	int n , r;
}CTree;

CTree cj_hzecs(char *tree , int len);
int max_ecs_sd (CTree tree , CTBox child);

int main ()
{
	CTree a;
	a = cj_hzecs ("1(2(3)(4)(5(6(7))))",19);
	printf ("%d",max_ecs_sd (a,a.nodes[0]));
}
int max_ecs_sd (CTree tree , CTBox child)
{
	ChildPtr next;
	int max = 0;
	int a;
	if (child . child== NULL)
	{
		return 1;
	}
	next = child . child;
	while (next != NULL)
	{
		if ((a = max_ecs_sd (tree,tree . nodes[next -> child])) > max)
		{
			max = a;
		}
		next = next -> next;
	}
	return max + 1;
}

CTree cj_hzecs(char *tree , int len)
{
	ChildPtr c_next;
	CTree c_tree;
	CTBox **zhan , *point;
	int n = 0;
	
	c_tree . n = 0 , c_tree . r = 0;
	
	zhan = (CTBox **) malloc (sizeof (CTBox *) * TREE_MAX);
	point = &c_tree . nodes [c_tree . r];
	point -> child = NULL;
	c_tree . n += 1;

	for (int x = 0 ; x < len ; x ++)
	{
		if (tree [x] == '(')
		{
			zhan [n] = point , n += 1;
			
			
			if (point -> child == NULL)
			{
				point -> child = (struct CTNode *) malloc (sizeof (struct CTNode));
				c_next = point -> child;
			}
			else 
			{
				c_next = point -> child;
				while (c_next -> next != NULL)
				{
					c_next = c_next -> next;
				}
				c_next -> next = (struct CTNode *) malloc (sizeof (struct CTNode));
				c_next = c_next -> next;
			}
			c_next -> next = NULL;
			c_next -> child = c_tree . n ;
			c_tree . n += 1;
			point = &c_tree . nodes [c_next -> child];
			point -> child = NULL;
		}
		else if (tree [x] == ')')
		{
			point = zhan [n - 1];
			n -= 1;
		}
		else
		{
			point -> data = tree[x];
		}
	}
	return c_tree;
}