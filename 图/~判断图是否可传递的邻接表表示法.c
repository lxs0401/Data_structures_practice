#define MAX_VERTEX_NUM 20
#include <stdio.h>
#include <stdlib.h>

typedef struct ArcNode 
{
	int  adjvex;
	struct ArcNode *nextarc;
	char *info;
}ArcNode;

typedef struct VNode 
{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum , arcnum;
	int kind;
}ALGraph;
void DeleteArc (ALGraph *G , int x , int y);
void DeleteVex(ALGraph *G , int v);
void InsertVex(ALGraph *G , char data);
void InsertArc(ALGraph *G , int  x , int y);

int Graph_trans (ALGraph *G)
{
	
	int vexnum = G -> vexnum;
	for (int x = 0 ; x < vexnum ; x ++)
	{
		ArcNode *yy = G -> vertices [x] . firstarc;
		for ( ArcNode *y = G -> vertices [x] . firstarc ; y != NULL ; y = y -> nextarc )
		{

			for (ArcNode *z = G -> vertices [y -> adjvex] . firstarc ; z != NULL ; z = z -> nextarc)
			{
				if (z -> adjvex != x)
				{
					while (yy != NULL && yy -> adjvex != z)yy = yy -> nextarc;
					if (yy != NULL) return 0;
				}
			}
		}

	}
	return 1;
}

void DeleteArc (ALGraph *G , int x , int y)
{
	ArcNode *Node;
	{/*main*/
		Node = G -> vertices [x] . firstarc;
		if (Node != NULL && G -> vertices [x] . firstarc -> adjvex == y)
		{
			G -> vertices [x] . firstarc  = Node -> nextarc;
			G -> arcnum -= 1;
		}
		else
		{
			for ( ; Node != NULL && Node -> nextarc != NULL && Node -> nextarc -> adjvex != y ; Node = Node -> nextarc);
			if (Node != NULL && Node -> nextarc != NULL && Node -> nextarc -> adjvex == y )
			{
				Node -> nextarc = Node -> nextarc -> nextarc;
				G -> arcnum -= 1;
			}
		}
	}
}

void DeleteVex(ALGraph *G , int v)
{
	
	{/*删除以v为弧头的边*/

		int vexnum = G -> vexnum;
		ArcNode *Node ;

		for (int x = 0 ; x < vexnum ; x ++)
		{
			if (x != v)
			{
				DeleteArc (G , x , v);
			}
		}
	}

	G -> vexnum -= 1;
	for (int x = v ; x < G -> vexnum; x ++)
	{
		G -> vertices [x] = G -> vertices [x + 1];
	}
	G -> vertices [G -> vexnum] . firstarc = NULL;
	G -> vertices [G -> vexnum] . data = 0;
}

void InsertVex(ALGraph *G , char data)
{
	G -> vexnum += 1;
	G -> vertices [G -> vexnum - 1] . data = data;
}
void InsertArc(ALGraph *G , int  x , int y )
{
	ArcNode *Node;

	G -> arcnum += 1;
	Node = (ArcNode *) malloc (sizeof (ArcNode));
	Node -> adjvex = y;

	Node -> nextarc = G -> vertices [x] . firstarc;

	G -> vertices[x] . firstarc = Node;
}