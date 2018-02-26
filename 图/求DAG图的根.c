#define MAX_VERTEX_NUM 20
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

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


void clear_visit (char *visit , int len);
int visit_ok (char *visit , int len );
void DFS (ALGraph *G , char u , char *visit);
char DAG_point (ALGraph *G);

int main ()
{
	ALGraph *G;

	G = (ALGraph *) malloc (sizeof (ALGraph));
	G -> vexnum = 0 , G -> arcnum = 0 , G -> kind = 0;

	for (int num = 0 ; num < MAX_VERTEX_NUM ; num ++)
	{
		G -> vertices [num] . data = 0;
		G -> vertices [num] . firstarc = NULL;
	}
	for (int num = 0 ; num < 5 ; num ++)
	{
		InsertVex (G , 0);
	}
	InsertArc (G , 4 , 0) , InsertArc (G , 4 , 2) , InsertArc (G , 0 , 1) , InsertArc (G , 2 , 3);
	printf ("%d" , DAG_point (G));
}
void clear_visit (char *visit , int len)
{
	for (int num = 0 ; num < len ; num ++)
	{
		visit [num] = FALSE;
	}
	return ;
}
int visit_ok (char *visit , int len )
{
	for (int num = 0 ; num < len ; num ++)
	{
		if (visit [num] == FALSE)
		{
			return FALSE;
		}
	}
	return TRUE;
}
void DFS (ALGraph *G , char u , char *visit)
{
	ArcNode *Node;

	visit [u] = TRUE; 
	for (Node = G -> vertices [u] . firstarc ; Node != NULL ; Node = Node -> nextarc)
	{
		if (visit [Node -> adjvex] == FALSE)
		{
			DFS (G , Node -> adjvex , visit);
		}
	}
}
char DAG_point (ALGraph *G)
{
	char *visit;

	visit = (char *) malloc (sizeof (char) * G -> vexnum);

	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		clear_visit (visit , G -> vexnum);
		DFS (G , num , visit);
		if (visit_ok (visit , G -> vexnum) == TRUE)
		{
			return num;
		}
	}

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