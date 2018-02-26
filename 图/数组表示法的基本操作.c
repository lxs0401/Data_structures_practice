#include <stdio.h>
#include <stdlib.h>

#define INFINTIY 255
#define MAX_VERTEX_NUM 20

#define TRUE  1
#define FLASE 0

typedef enum {DG,DN,UDG,UDN} GraphKind;

typedef struct ArcCell
{
	char adj;
	char *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct 
{
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum , arcnum;
	GraphKind kind;
}MGraph;

void DeleteArc (MGraph *G , int x, int y);
void DeleteVex (MGraph *G , int v);
void InsertArc (MGraph *G , int x , int y , int adj , char *info);
void InsertVex (MGraph *G );

int main()
{
	MGraph *G;
	G = (MGraph *) malloc (sizeof (MGraph));
	G -> vexnum = 0 , G -> arcnum = 0 , G -> kind = 0 ;
	for(int x = 0 ; x < MAX_VERTEX_NUM ; x ++)
	{
		G -> vexs [x] = FLASE;
		for (int y = 0 ; y < MAX_VERTEX_NUM ; y ++)
		{
			G -> arcs [x][y] . adj = INFINTIY;
			G -> arcs [x][y] . info = NULL;
		}
	}

	for (int x = 0 ; x < 10 ; x ++)
	{
		InsertVex (G);
	}
	for (int x = 0 ; x < 10 ; x ++)
	{
		for (int y = x ; y < 10 ; y ++)
		{
			if (x != y)
				InsertArc (G , x , y , 1 , NULL);
		}
	}
	for (int x = 0 ; x < 10 ; x ++)
	{
		for (int y = x ; y < 10 ; y ++)
		{
			if (x != y)
				DeleteArc (G , x , y);
		}
	}
	for (int x = 0 ; x < 10 ; x ++)
	{
		DeleteVex (G , x);
	}

}
void DeleteArc (MGraph *G , int x, int y)
{
	if ( (G -> arcs [x][y] . adj == INFINTIY) && ((G -> kind != DG ) != DN) && (G -> arcs [y][x] . adj == INFINTIY) )
	{
		return;
	}
	else
	{
		G -> arcnum -= 1;
		if (G -> kind == DG || G -> kind == DN)
		{
			G -> arcs [x][y] . adj = INFINTIY;
			G -> arcs [x][y] . info = NULL;
		}
		else
		{
			G -> arcs[y][x] . adj = INFINTIY;
			G -> arcs[y][x] . info = NULL;
			G -> arcs[x][y] . adj = INFINTIY;
			G -> arcs[x][y] . info = NULL;
		}
	}
}
void DeleteVex (MGraph *G , int v)
{
	int vexnum;

	if (G -> vexs [v] == FLASE)return ;
	G -> vexs[v] = FLASE;
	G -> vexnum -= 1;
	vexnum = G -> vexnum;
	for (int vex = 0 ; vex < vexnum ; vex ++)
	{
		if (G -> vexs [vex] == TRUE)
		{
			G -> arcs [vex][v] . adj = INFINTIY;
			G -> arcs [vex][v] . info = NULL;

		}
		else
		{
			vexnum += 1;
		}
	}
}

void InsertArc (MGraph *G , int x , int y , int adj , char *info)
{
	if ( G -> kind == DG || G -> kind == DN )
	{
		G -> arcs[x][y] . adj = adj;
		G -> arcs[x][y] . info = info;
	}
	else
	{
		G -> arcs[x][y] . adj = adj;
		G -> arcs[x][y] . info = info;
		G -> arcs[y][x] . adj = adj;
		G -> arcs[y][x] . info = info;
	}
	G -> arcnum += 1;
	
}
void InsertVex (MGraph *G )
{
	int ber = (G -> vexnum += 1) - 1;
	G -> vexs[ber] = TRUE;
}