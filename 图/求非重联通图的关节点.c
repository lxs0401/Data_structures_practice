/*
求图的关节点
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_POINT 10
#define MAX_COST 1000

void FindAp(int (*graph)[10],int *visted , int *low, int v,int *cont)
{
    int i;
    int min;
    visted[v] = min = ((*cont) += 1);
    
    for (i = 0 ; i < MAX_POINT ; i ++)
    {
        if (visted[i] <= 0 && graph[v][i] < MAX_COST)
        {
            FindAp(graph,visted,low,i,cont);
            if (low[i] < min)
                min = low[i];
            if (low[i] >= visted[v]) printf("point :%d\n",v); //如果要求非重连通图的割边，if (low[i] > visted[v]) printf("edge %d->%d",v,i);
        }else if (visted[i] < min && graph[v][i] < MAX_COST)
            min = visted[i];
    }
    low[v] = min;
}
int main ()
{
    int graph[MAX_POINT][MAX_POINT];
    int visted[10] = {0} , low[10] = {0};
    int time,i,j,cont = 1;
    int vexnum;
    scanf("%d%d",&time,&vexnum);
    for (i = 0 ; i < MAX_POINT ; i ++)
    {
        for (j = 0 ; j < MAX_POINT ; j ++)
        {
            graph[i][j] = MAX_COST;
        }
    }
    for (i = 0 ; i < time ; i ++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    visted[0] = 1;
    for (j = 0 ; j < MAX_POINT && graph[0][j] == MAX_COST; j ++);
    FindAp(graph,visted,low,j,&cont);
    if (cont < vexnum)
    {
        printf("point :%d\n",0);
        for (i = j + 1; i < MAX_POINT ; i ++)
        {
            if (graph[0][i] < MAX_COST && visted[i] <= 0)FindAp(graph,visted,low,i,&cont);
        }
    }
}