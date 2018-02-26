#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
typedef enum {unvisited , visited} VisitIf;
typedef struct EBox
{
	VisitIf mark;
	int ivex , jvex;
	struct EBox *ilink , *jlink;
	char *info;
}EBox;
typedef struct VexBox
{
	char data;
	EBox * firstedge;
}VexBox;
typedef struct 
{
	VexBox adjmulist [MAX_VERTEX_NUM];
	int vexnum , edgenum;
}AMLGraph;

void InsertVex (AMLGraph *G , char data);      //删除图G的结点
void InsertEdge (AMLGraph *G , int i , int j); //删除图G中的边
void DeleteVex  (AMLGraph *G , int v);         //删除图G中的结点
int DeleteEdge2 (AMLGraph *G , int i , int j);
void DeleteEdge  (AMLGraph *G , int i , int j);//删除图G中的边

int main (void)
{
	AMLGraph *G;
	G = (AMLGraph *) malloc (sizeof (AMLGraph));
	G -> vexnum = 0;
	G -> edgenum = 0;
	for (int x = 0 ; x < MAX_VERTEX_NUM ; x ++)
	{
		G -> adjmulist [x] . firstedge = NULL;
		G -> adjmulist [x] . data = 0;
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		InsertVex (G , x);
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		for (int y = x ; y < 3 ; y ++)
		{
			if (x != y)
				InsertEdge (G , x , y);
		}
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		for (int y = x ; y < 3 ; y ++)
		{
			if (x != y)
				DeleteEdge(G , x , y);
		}
	}
	DeleteVex (G , 2);

}
int DeleteEdge2 (AMLGraph *G , int i , int j)
{
	EBox *Node , *up;
	Node = G -> adjmulist [i] . firstedge; 

	if (Node != NULL && (Node -> jvex == j || Node -> ivex == j) )
	{
		if (Node -> jvex == i)
		{
			G -> adjmulist [i] . firstedge = Node -> jlink;
		}
		else
		{
			G -> adjmulist [i] . firstedge = Node -> ilink;
		}
		return 1;
	}
	else
	{
		while (Node != NULL && Node -> jvex != j && Node -> ivex != j)
		{
			up = Node;
			if (Node -> jvex == i)
			{
				Node = Node -> jlink;
			}
			else
			{
				Node = Node -> ilink;
			}
		}
		if (Node != NULL && (Node -> jvex == j || Node -> ivex == j))
		{
			if (Node -> jvex == i)
			{
				if (up -> jvex == i)
				{
					up -> jlink = Node -> jlink;
				}
				else
				{
					up -> ilink = Node -> jlink;
				}
			}
			else
			{
				if (up -> jvex == i)
				{
					up -> jlink = Node -> ilink;
				}
				else
				{
					up -> ilink = Node -> ilink;
				}
			}
			return 1;
		}
	}
	return 0;
}
void DeleteEdge (AMLGraph *G , int i , int j)
{
	if (DeleteEdge2 (G , i , j))
	{
		G -> edgenum -= 1;
	}
	DeleteEdge2 (G , j , i);
}

void DeleteVex  (AMLGraph *G , int v)
{
	int *vexnum = &G -> vexnum;
	{
		EBox *Ebos , *up;
		Ebos = G -> adjmulist [v] . firstedge;

		while (Ebos != NULL)
		{
			DeleteEdge (G , Ebos -> ivex , Ebos -> jvex);
			if (Ebos -> ivex == v)
			{
				Ebos = Ebos -> ilink;
			}
			else
			{
				Ebos = Ebos -> jlink;
			}
		}
	}
	for (int num = v ; num < *vexnum ; num ++)
	{
		G -> adjmulist [num] = G -> adjmulist [num + 1];
	}
	G -> adjmulist [*vexnum - 1] . data = 0;
	G -> adjmulist [*vexnum - 1] . firstedge = NULL;
	*vexnum -= 1;
}
void InsertEdge (AMLGraph *G , int i , int j)
{
	EBox *Node;
	G -> edgenum += 1;
	Node = (EBox *) malloc (sizeof (EBox));
	Node -> mark = unvisited;
	Node -> ivex = i , Node -> jvex = j;
	Node -> ilink = G -> adjmulist [i] . firstedge;
	Node -> jlink = G -> adjmulist [j] . firstedge;

	G -> adjmulist [i] . firstedge = Node;
	G -> adjmulist [j] . firstedge = Node;
}
void InsertVex (AMLGraph *G , char data)
{
	G -> vexnum += 1;
	G -> adjmulist [G -> vexnum - 1] . data = data;
	G -> adjmulist [G -> vexnum - 1] . firstedge = NULL;
}