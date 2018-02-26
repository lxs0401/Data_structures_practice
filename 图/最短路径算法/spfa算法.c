#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(x,y) ((x *)malloc(sizeof(x)*y))
#define UNVISITED 0
#define VISITED   1
struct edge
{
    int to;
    int weight;
    int next;
} data[4000010];
int head[500010];
int cont;

int queue[500010];
int tail,top;
void push(int data)
{
    top = (top + 1) % 500010;
    queue[top] = data;
}
int pop(void)
{
    tail = (tail + 1) % 500010;
    return queue[tail];
}
void newedge(int u, int v, int w)
{
    data[cont].to = v;
    data[cont].next = head[u];
    data[cont].weight = w;
    head[u] = cont;
    cont += 1;
}
int spfa(int vexnum , int source,int dest)
{
    int *vexCosts = MALLOC(int,vexnum + 1);
    int *visit = MALLOC(int,vexnum + 1);

    for(int i = 0 ; i <= vexnum ; i ++)vexCosts[i] = -1,visit[i] = UNVISITED; //init
    vexCosts[source] = 0;
    visit[source] = VISITED;
    push(source);
    while(top != tail)
    {
        int vex = pop();
        visit[vex] = UNVISITED;
        for (int next = head[vex]; next != -1 ; next = data[next].next)
        {
            if(vexCosts[data[next].to] == -1 || vexCosts[data[next].to] > data[next].weight + vexCosts[vex]) 
            {
                vexCosts[data[next].to] = data[next].weight + vexCosts[vex];
                if(visit[data[next].to] == UNVISITED)
                {
                    push(data[next].to);
                    visit[data[next].to] = VISITED;
                }
            }

        }
    }
    
    return vexCosts[dest];
}
int main()
{
    int vexnum, arcnum;
    while (scanf("%d%d", &vexnum, &arcnum) != EOF)
    {
        int source,dest;
        { //init
            cont = 0;
            for (int i = 0; i <= vexnum; i++)
            {
                head[i] = -1;
            }
            tail = top = 0;
        }
        for (int i = 0 ; i < arcnum ; i ++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            newedge(u,v,w);
            newedge(v,u,w);
        }
        scanf("%d%d",&source,&dest);
        printf("%d\n",spfa(vexnum,source,dest));
    }
}