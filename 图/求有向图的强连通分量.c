#include <stdio.h>
#include <stdlib.h>

#define INFINTIY (char)127
#define MAX_VERTEX_NUM 20

#define TRUE  1
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

void DeleteArc (MGraph *G , int x, int y);
void DeleteVex (MGraph *G , int v);
void InsertArc (MGraph *G , int x , int y , int adj , char *info);
void InsertVex (MGraph *G ); 

void print_scc (MGraph *G);
int pDFS (MGraph *G , int i , char *visit , int *time);
int DFS (MGraph *G , int i , char *visit , int *time , int *thistime);

int main ( void )
{
 	MGraph *G;

 	G = (MGraph *) malloc (sizeof (MGraph));
 	G -> vexnum = 0 , G -> arcnum = 0;
 	G -> kind = DG ;
 	for (int x = 0 ; x < MAX_VERTEX_NUM ; x ++)
 	{
 		for (int y = 0 ; y < MAX_VERTEX_NUM ; y ++)
 		{
 			G -> arcs [x][y] . adj = INFINTIY;
 			G -> arcs [x][y] . info = NULL;
 		}
 		G -> vexs [x] = 0;
 	}
 	for (int num = 0 ; num < 6 ; num ++)
 	{
 		InsertVex (G);
 	}
 	for (int num = 1 ; num < 4 ; num ++)
 	{
 		InsertArc (G , num - 1 , num , 1 , NULL);
 		InsertArc (G , num  , num - 1, 1 , NULL);
	}
	InsertArc (G , 4 , 5 , 1 , NULL);
 	print_scc(G);
 	return 0;
}

int DFS (MGraph *G , int i , char *visit , int *time , int *thistime)
{
	visit [i] = TRUE;
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		if (G -> arcs [i][num] . adj < INFINTIY && visit [num] == FALSE)
		{
			DFS (G , num , visit , time , thistime);
		}
	}
	time[*thistime] = i;
	(*thistime) += 1;
}
int pDFS (MGraph *G , int i , char *visit , int *time)
{
	visit [i] = TRUE;
	printf ("%d,",i);
	for (int num = 0 ; num < G -> vexnum ; num ++ )
	{
		if (G -> arcs[i][num].adj < INFINTIY && visit [num] == FALSE)
		{
			pDFS (G , num , visit , time);
		}
	}
}
void print_scc (MGraph *G)
{
	int thistime = 0 , *time;
	char *visit ;

	visit = (char *) malloc (sizeof (char) * G -> vexnum);
	time  = (int *) malloc (sizeof (int) * G -> vexnum);
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		visit [num] = FALSE;
		time [num] = -1;
	}
	printf("\n");
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		if (visit [num] == FALSE)
		{
			DFS (G , num , visit , time , &thistime);
		}
	}
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		visit [num] = FALSE;
	}
	for (int num = 0 ; num < G -> vexnum ; num ++)
	{
		if (visit [time[num]] == FALSE)
		{
			pDFS (G , time[num] , visit , time);
			printf("\n");
		}
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
}