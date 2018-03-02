#define MAX_VERTEX_NUM 20
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	char *info;
} ArcNode;

typedef struct VNode
{
	char data;
	ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
} ALGraph;
void DeleteArc(ALGraph *G, int x, int y);
void DeleteVex(ALGraph *G, int v);
void InsertVex(ALGraph *G, char data);
void InsertArc(ALGraph *G, int x, int y);

int DFS(ALGraph *G, int i, int j, char *visit);

int main(void)
{
	ALGraph *G;
	char *visit;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	visit = (char *)malloc(sizeof(char) * 10);
	G->vexnum = 0, G->arcnum = 0, G->kind = 0;

	for (int num = 0; num < 5; num++)
	{
		G->vertices[num].firstarc = NULL;
		InsertVex(G, num);
		visit[num] = FALSE;
	}
	InsertArc(G, 0, 2);
	InsertArc(G, 0, 3);
	InsertArc(G, 3, 4);
	InsertArc(G, 1, 5);

	printf("%d", DFS(G, 1, 5, visit));
}

int DFS(ALGraph *G, int i, int j, char *visit)
{
	ArcNode *Node;
	int num;

	Node = G->vertices[i].firstarc;
	if (Node == NULL)
		return 0;
	for (; Node != NULL; Node = Node->nextarc)
	{
		num = Node->adjvex;
		if (num == j)
		{
			return TRUE;
		}
		if (visit[num] == FALSE)
		{
			if (DFS(G, num, j, visit) == TRUE)
			{
				visit[num] = TRUE;
				return TRUE;
			}
			visit[num] = TRUE;
		}
	}
	return FALSE;
}

void DeleteArc(ALGraph *G, int x, int y)
{
	ArcNode *Node;
	{ /*main*/
		Node = G->vertices[x].firstarc;
		if (Node != NULL && G->vertices[x].firstarc->adjvex == y)
		{
			G->vertices[x].firstarc = Node->nextarc;
			G->arcnum -= 1;
		}
		else
		{
			for (; Node != NULL && Node->nextarc != NULL && Node->nextarc->adjvex != y; Node = Node->nextarc)
				;
			if (Node != NULL && Node->nextarc != NULL && Node->nextarc->adjvex == y)
			{
				Node->nextarc = Node->nextarc->nextarc;
				G->arcnum -= 1;
			}
		}
	}
}

void DeleteVex(ALGraph *G, int v)
{

	{ /*删除以v为弧头的边*/
		int vexnum = G->vexnum;
		ArcNode *Node;

		for (int x = 0; x < vexnum; x++)
		{
			if (x != v)
			{
				DeleteArc(G, x, v);
			}
		}
	}

	G->vexnum -= 1;
	for (int x = v; x < G->vexnum; x++)
	{
		G->vertices[x] = G->vertices[x + 1];
	}
	G->vertices[G->vexnum].firstarc = NULL;
	G->vertices[G->vexnum].data = 0;
}

void InsertVex(ALGraph *G, char data)
{
	G->vexnum += 1;
	G->vertices[G->vexnum - 1].data = data;
}
void InsertArc(ALGraph *G, int x, int y)
{
	ArcNode *Node;

	G->arcnum += 1;
	Node = (ArcNode *)malloc(sizeof(ArcNode));
	Node->adjvex = y;

	Node->nextarc = G->vertices[x].firstarc;

	G->vertices[x].firstarc = Node;
}