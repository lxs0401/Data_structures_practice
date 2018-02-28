#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 20
typedef struct granode
{
	int cost;
}granode,grans[MAX_NUM][MAX_NUM];
typedef struct gra
{
	grans allvex;
	int data[MAX_NUM];
	int vexnum,arcnum;
}gra;

typedef struct Tree
{
	int data;
	struct Tree **child;
	int tree_num;
}Tree;
typedef struct g_list
{
	int cost;
	int data;
	int from_vex;
	Tree *from_tree;
}G_list;

gra *create(void);
void InserVex (gra *G,int data);
void DelVex (gra *G , int vex);
Tree *mintree_gra (gra *G , int root);
void InserArc (gra *G , int x , int y , int cost);
int main ()
{
	gra *G = create ();
	Tree *tree;
	InserVex(G,1);InserVex(G,2);InserVex(G,3);InserVex(G,4);InserVex(G,5);InserVex(G,6);
	InserArc(G,0,1,6);InserArc(G,0,2,1);InserArc(G,0,3,5);
	InserArc(G,2,1,5);InserArc(G,2,4,6);InserArc(G,2,5,4);InserArc(G,2,3,5);
	InserArc(G,1,4,3);InserArc(G,4,5,6);InserArc(G,5,3,2);
	tree = mintree_gra(G,0);

}
Tree *mintree_gra (gra *G , int root)
{
	Tree *tree = (Tree *) malloc (sizeof(Tree));
	G_list *list = (G_list *) malloc (sizeof(G_list) * MAX_NUM);
	int list_num = 0;

	tree -> child = (Tree **) malloc (sizeof(Tree *) * MAX_NUM); 
	tree -> tree_num = 0;
	tree -> data = G -> data[root];
	for (int i = 0 ; i < MAX_NUM ; i ++)
	{
		list[i] . cost = 0;
	}
	list[root] . cost = -1;
	for (int i = 0 ; i < MAX_NUM ; i ++)
	{
		if (G -> allvex[root][i] . cost > 0)
		{
			list[i] . cost = G -> allvex[root][i] . cost;
			list[i] . from_vex = root;
			list[i] . from_tree = tree;
			list[i] . data = G -> data[i];
			list_num += 1;
		} 
    }
    list[root] . cost = -1;
	while (list_num > 0)
	{
		int mingnode = -1,minnodecost = -1;
		Tree *conTree = (Tree *) malloc (sizeof(Tree));
		conTree -> child = (Tree **) malloc (sizeof(Tree *) * MAX_NUM);
		conTree -> tree_num = 0;

		for (int i = 0 ; i < MAX_NUM ; i ++)
		{
			if ((list[i] . cost > 0 && minnodecost == -1) || (list[i] . cost > 0 && minnodecost > list[i] . cost))
			{
				minnodecost = list[i] . cost;
				mingnode    = i;
			}
		}
		conTree -> data = list[mingnode] . data;
		list[mingnode] . cost = -1;
		list_num -= 1;
		list[mingnode] . from_tree -> child [list[mingnode] . from_tree -> tree_num] = conTree;
		list[mingnode] . from_tree -> tree_num += 1;
		for (int i = 0 ; i < MAX_NUM ; i ++)
		{
			if ((list[i] . cost == 0 && G -> allvex[mingnode][i] . cost > 0) || 

				(list[i] . cost > 0 && G -> allvex [mingnode][i] . cost > 0 && list[i] . cost > G -> allvex [mingnode][i] . cost))
			{
				if (list[i] . cost == 0)list_num += 1;
				list[i] . cost = G -> allvex[mingnode][i] . cost;
				list[i] . from_vex = mingnode;
				list[i] . from_tree = conTree;
				list[i] . data = G -> data[i];
			}
		}
	}
	return tree;
}

gra *create(void)
{
	gra *G = (gra *) malloc (sizeof(gra));
	G -> vexnum = G -> arcnum = 0;
	return G;
}
void InserVex (gra *G,int data)
{
	for (int i = 0 ; i < MAX_NUM ; i ++)
	{
		G -> allvex[G -> vexnum][i] . cost = 0;
	}
	G -> data[G -> vexnum]  = data;
	G -> vexnum += 1;
}
void DelVex (gra *G , int vex)
{
	for (int i = vex ; i < MAX_NUM ; i ++)
	{
		for (int j = 0 ; j < MAX_NUM ; j ++)
		{
			G -> allvex[i][j] = G -> allvex[i + 1][j];
		}
	}
}
void InserArc (gra *G , int x , int y , int cost )
{
	G -> allvex[x][y] . cost = cost;
	G -> allvex[y][x] . cost = cost;
}
