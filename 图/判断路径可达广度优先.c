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

typedef struct queue 
{
	char *list;
	int first_num , last_num;
}Queue;
void DeleteArc (ALGraph *G , int x , int y);
void DeleteVex(ALGraph *G , int v);
void InsertVex(ALGraph *G , char data);
void InsertArc(ALGraph *G , int  x , int y);

int BFS (ALGraph *G , int i , int j , char *visit);

Queue *create_queue (int num);
char out_queue(Queue *Q);
void in_queue(Queue *Q , char data);



int main (void)
{
	ALGraph *G;
	char *visit;
	G = (ALGraph *) malloc (sizeof (ALGraph));
	visit = (char *) malloc (sizeof (char) * 10);
	G -> vexnum = 0 , G -> arcnum = 0 , G -> kind   = 0;

	for (int num = 0 ; num < 5 ; num ++)
	{
		G -> vertices [num] . firstarc = NULL;
		InsertVex (G , num);
		visit [num] = FALSE;
	}
	InsertArc (G , 0 , 2);
	InsertArc (G , 0 , 3);
	InsertArc (G , 3 , 4);
	InsertArc (G , 1 , 5);

	printf ("%d",BFS (G,0,5,visit));
}


int BFS (ALGraph *G , int i , int j , char *visit)
{
	Queue *Q;
	int num = i;
	Q = create_queue (G -> vexnum * G -> vexnum);    //创建队列

	{
		ArcNode *Node;
		in_queue (Q,num);
		while (Q -> first_num != Q -> last_num)
		{
			for (Node = G -> vertices [num] . firstarc ; Node != NULL ; Node = Node -> nextarc)
			{
				if ( visit[Node -> adjvex] == FALSE )
				{
					if (Node -> adjvex == j) 
					{
						return 1;
					}
					in_queue (Q , Node -> adjvex);
					visit [Node -> adjvex] = TRUE;
				}
				
			}
			num = out_queue(Q);
		}
	}
	return 0;
}


Queue *create_queue (int num)
{
	Queue *Q;

	Q = (Queue *) malloc (sizeof (Queue));
	Q -> list = (char *) malloc (sizeof (char) * num);
	Q -> first_num = 0 , Q -> last_num = 0;
	return Q;
}
char out_queue(Queue *Q)
{
	Q -> first_num += 1;
	return Q -> list [Q -> first_num];
}
void in_queue(Queue *Q , char data)
{
	Q -> last_num += 1;
	Q -> list [Q -> last_num - 1] = data;

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