#include <stdio.h>
#include <stdlib.h>

#define INFINTIY 255
#define MAX_VERTEX_NUM 20

#define TRUE 1
#define FALSE 0

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


/*void DeleteArc ( MGraph *G , int x, int y);
void DeleteVex ( MGraph *G , int v);
void InsertArc ( MGraph *G , int x , int y , int adj , char *info);
void InsertVex ( MGraph *G );
*/

void MGraph_start ( MGraph *G ) //初始化MGraph结构
{
	G -> vexnum = 0 , G -> arcnum = 0;
	G -> kind = DG;
	for (int x = 0 ; x < MAX_VERTEX_NUM ; x ++)
	{
		for (int y = 0 ; y < MAX_VERTEX_NUM ; y ++)
		{
			G -> arcs [x][y] . adj = INFINTIY;
			G -> arcs [x][y] . info = NULL;
		}
		G -> vexs [x] = FALSE;
	}
}
int pic_trans ( MGraph *G )
{
	int vexnum = G -> vexnum ;

	for (int x = 0 ; x < vexnum ; x ++)
	{
		if (G -> vexs [x] == TRUE)
		{
			for (int y = 0 ; y < MAX_VERTEX_NUM ; y ++)
			{
				if ( G -> arcs [x][y] . adj < INFINTIY )
				{
					for (int z = 0 ; z < MAX_VERTEX_NUM ; z ++)
					{
						if ( G -> arcs [y][z] . adj < INFINTIY )
						{
							if ( G -> arcs [x][z] . adj >= INFINTIY )
							{
								return FALSE;
							}
						}
					}
				}
			}
		}
		else
		{
			vexnum += 1;
		}
	}
	return TRUE;
}


/*
void DeleteArc (MGraph *G , int x, int y)
{
	if ( (G -> arcs [x][y] . adj == INFINTIY) && ((G -> kind != DG ) != DN) && (G -> arcs [y][x] . adj == INFINTIY) )
	{
		return;
	}
	else
	{
		G -> arcnum -= 1;
	}
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
void DeleteVex (MGraph *G , int v)
{
	int vexnum;

	if (G -> vexs [v] == FALSE)return ;
	G -> vexs[v] = FALSE;
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
}*/