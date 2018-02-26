#define MAX_VERTEX_NUM 20
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
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

int ifsimpleroute (ALGraph *G , int i , int j ,int k );
int if_route (int vex , ALGraph *G , int j , int k , char *vexlist );

int main ( void )
{
	ALGraph *G;
	G = (ALGraph *) malloc (sizeof (ALGraph));
	for (int num = 0 ; num < MAX_VERTEX_NUM ; num ++)
	{
		G -> vertices [num] . firstarc = NULL;
		G -> vertices [num] . data = 0;
	}
	G -> vexnum = 0 , G -> arcnum = 0 , G -> kind = 0;

	for (int num = 0 ; num < 5 ; num ++ )
	{
		InsertVex (G , num);
	}
	for (int x = 0 ; x < 5 ; x ++)
	{
		for (int y = 0 ; y < 5 ; y ++)
		{
			InsertArc (G , x , y);
		}
	}
	printf ("%d",ifsimpleroute (G , 0 , 4 , 5));
}
int if_route (int vex , ALGraph *G , int j , int k , char *vexlist )
{
	if ( k == 0 )
	{
		vexlist [vex] = FALSE;
		return vex == j ? TRUE : FALSE;
	}
	for (ArcNode *Node = G -> vertices [vex] . firstarc ; Node != NULL ; Node = Node -> nextarc)
	{
		if (vexlist [Node -> adjvex] == FALSE)
		{
			vexlist [Node -> adjvex] = TRUE;
			if (if_route(Node -> adjvex , G , j , k - 1 , vexlist) == TRUE)
			{
				return TRUE;
			}
		}
	}
	vexlist[vex] = FALSE;
	return FALSE;
}
int ifsimpleroute (ALGraph *G , int i , int j ,int k )
{
	char *vexlist;

	vexlist = (char *) malloc (sizeof (char) * G -> vexnum);
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		vexlist [num] = FALSE;
	}
	return if_route(i , G , j , k , vexlist);
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