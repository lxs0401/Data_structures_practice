#include <stdio.h>
#include <stdlib.h>

#define INFINTIY 255
#define MAX_VERTEX_NUM 20

#define TRUE  1
#define FALSE 0

typedef enum {DG,DN,UDG,UDN} GraphKind;

typedef struct ArcCell
{
	int adj;
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
void shortestpath_DIJ (MGraph *G,int vex);
int main ()
{
    MGraph *G = (MGraph *) malloc (sizeof(MGraph));
    int n,m;
    for (int i = 0 ; i < MAX_VERTEX_NUM ; i ++)
    {
        G -> vexs[i] = FALSE;
        for (int j = 0 ; j < MAX_VERTEX_NUM ; j ++)
        {
            G -> arcs[i][j] . adj = INFINTIY;
        }
    }
    G -> vexnum = G -> arcnum = 0;
    G -> kind = DG;
    scanf ("%d%d",&n,&m);
    for (int i = 0 ; i < n ; i ++)InsertVex(G);
    for (int i = 0 ; i < m ; i ++)
    {
        int v0,v1,cost;
        scanf ("%d%d%d",&v0,&v1,&cost);
        InsertArc(G,v0,v1,cost,NULL);
    
    }
    for (int i = 0 ; i < n ; i ++)
    {
        shortestpath_DIJ(G,i);
        printf("\n");
    }
}
void shortestpath_DIJ (MGraph *G,int vex)
{
    int final[MAX_VERTEX_NUM] = {FALSE};
    int cost[MAX_VERTEX_NUM] , point [MAX_VERTEX_NUM];
    final[vex] = TRUE;
    for (int num = 0 ; num < G -> vexnum ; num ++)
    {
        cost[num] = G -> arcs[vex][num] . adj;
        point [num] = vex;
    }
    for (int num = 0 ; num < G -> vexnum ; num ++)
    {
        int min, mincost = INFINTIY;
        for (int v = 0 ; v < G -> vexnum ; v ++)
        {
            if ( final[v] == FALSE &&  mincost > cost[v] )
            {
                min = v;
                mincost = cost [v];
            }
        }
        final[min] == FALSE ? printf ("%d->%d ",point[min],min):0;
        final[min] = TRUE;
        
        for (int i = 0 ; i < G -> vexnum ; i ++)
        {
            if (final[i] == FALSE && G -> arcs[min][i] . adj + mincost < cost[i]) 
            {
                cost [i] = G -> arcs[min][i] . adj + mincost;
                point [i] = min;
            }
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