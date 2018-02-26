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



int SCGraph (ALGraph *G );    //判断强连通图
void pDFS (ALGraph *G , int i , char *visit);
void DFS (ALGraph *G , int i , char *visit , char *time , char *thistime );


void DFS (ALGraph *G , int i , char *visit , char *time , char *thistime )
{
	ArcNode *Node = NULL;

	visit [i] = TRUE;
	
	for (Node = G -> vertices [i] . firstarc ; Node != NULL ; Node = Node -> nextarc)
	{
		if (visit [Node -> adjvex] == FALSE)
		{
			DFS (G , Node -> adjvex , visit , time , thistime);
		}
	}
	time[*thistime] = i;
	(*thistime) += 1;
}
void pDFS (ALGraph *G , int i , char *visit)
{
	ArcNode *Node = NULL;

	visit [i] = TRUE;
	
	for (Node = G -> vertices [i] . firstarc ; Node != NULL ; Node = Node -> nextarc)
	{
		if (visit [Node -> adjvex] == FALSE)
		{
			pDFS (G , Node -> adjvex , visit);
		}
	}
}
int SCGraph (ALGraph *G )    //判断强连通图
{
	char *time , thistime = 0;
	char *visit;

	time = (char *) malloc (sizeof (char) * G -> vexnum);
	visit = (char *) malloc (sizeof (char) * G -> vexnum);

	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		visit [num] = FALSE;
		time [num] = FALSE;
	}
	DFS (G , 0 , visit , time , &thistime);
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		if (visit [num] == FALSE)
		{
			return FALSE;
		}
		time [num] = FALSE;
	}

	pDFS (G , time[0] , visit);
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		if (visit [num] == FALSE)
		{
			return FALSE;
		}
	}
	return TRUE;
}
int main ()
{
	ALGraph *G;
	G = (ALGraph *) malloc (sizeof (ALGraph));
	for (int vex = 0 ; vex < 3 ; vex ++)
	{
		G -> vertices [vex] . firstarc = NULL;
		G -> vertices [vex] . data = 0;
	}
	G -> vexnum = 0 , G -> arcnum = 0 , G -> kind = 0;

	InsertVex (G , 0 ) , InsertVex (G , 1) , InsertVex (G , 2);
	InsertArc (G , 0 , 1); InsertArc (G , 1 ,0);
	InsertArc (G , 0 , 2); InsertArc (G , 2 ,0);
	InsertArc (G , 1 , 2); InsertArc (G , 2 , 1); 
	printf ("%s",SCGraph (G) == TRUE ? "yes" : "no");
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