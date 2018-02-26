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
void InsertArc (MGraph *G , int x , int y , int adj);
void InsertVex (MGraph *G);
void shorttestpath_FLOYD(MGraph *G);
MGraph *create (void);
int main ()
{
    int n,m;
    MGraph *G = create();
    
    scanf ("%d%d",&n,&m);
    for (int i = 0 ; i < n ; i ++)InsertVex(G);
    for (int i = 0 ; i < m ; i ++)
    {
        int v,w,ai;
        scanf ("%d%d%d",&v,&w,&ai);
        InsertArc(G,v,w,ai);
    }
    shorttestpath_FLOYD(G);
}
MGraph *create (void)
{
    MGraph *G = (MGraph *) malloc (sizeof(MGraph));
    for (int i = 0 ; i < MAX_VERTEX_NUM ;i ++)
    {
        for (int j = 0 ; j < MAX_VERTEX_NUM ; j ++)
        {
            G -> arcs[i][j] . adj = INFINTIY;
        }
    }
    G -> vexnum = G -> arcnum = 0;
    G -> kind = DG;
    return G;
}
void shorttestpath_FLOYD(MGraph *G)
{
    int cost[MAX_VERTEX_NUM][MAX_VERTEX_NUM] , point[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {FALSE};
    for (int i = 0 ; i < G -> vexnum ; i ++)
    {
        for (int j = 0 ; j < G -> vexnum ; j ++)
        {
            cost [i][j] = G -> arcs[i][j] . adj ;
            if (i == j)cost[i][j] = 0;
            if (G -> arcs[i][j] . adj < INFINTIY)
            {
                point[i][j][i] = TRUE;
                point[i][j][j] = TRUE;
            }
        }
    }
    for (int k = 0 ; k < G -> vexnum ; k ++)
    {
        for (int i = 0 ; i < G -> vexnum ; i ++)
        {
            for (int j = 0 ; j < G -> vexnum ; j ++)
            {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost [i][j] = cost[i][k] + cost[k][j];
                }
                for (int u = 0 ; u < G -> vexnum ; u ++)
                {
                    point[i][j][u] = point[i][k][u] || point[k][j][u] ? TRUE : FALSE;
                }
            }
        }
    }
    for (int i = 0 ; i < G -> vexnum ; i ++)
    {
        for (int j = 0 ; j < G -> vexnum ;j ++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}
void InsertArc (MGraph *G , int x , int y , int adj)
{
	if ( G -> kind == DG || G -> kind == DN )
	{
		G -> arcs[x][y] . adj = adj;
	}
	else
	{
		G -> arcs[x][y] . adj = adj;
		G -> arcs[y][x] . adj = adj;
	}
	G -> arcnum += 1;
}
void InsertVex (MGraph *G )
{
	int ber = (G -> vexnum += 1) - 1;
	G -> vexs[ber] = TRUE;
}