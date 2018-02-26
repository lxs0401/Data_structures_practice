#define MAX_VERTEX_NUM 20
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define HEAD  0
#define TAIL  1
typedef struct ArcNode 
{
    int adjvex;
    int ai;
	struct ArcNode *nextarc;
	char *info;
}ArcNode;

typedef struct VNode 
{
    int vex;
    int in_de;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum , arcnum;
	int kind;
}ALGraph;
struct List
{
    VNode *data;
    struct List *next;
    struct List *prev;
};
typedef struct dui
{
    struct List *queue;
    struct List *end;
    int len;
}queue;


void Findin_de (ALGraph *G , int vex);
void print_ayaroute (ALGraph *G ,int vex);

queue *create_queue (void);
void push_queue (queue *Q,VNode *data);
void pop_queue (queue *Q,VNode **data,int from);

void InsertVex(ALGraph *G);
void InsertArc(ALGraph *G , int  x , int y , int ai );
int visit[MAX_VERTEX_NUM] = {FALSE};


int main ()
{
    ALGraph *G = (ALGraph *) malloc (sizeof(ALGraph));
    int n,m;
    G -> vexnum = 0;
    G -> arcnum = 0;
    scanf ("%d%d",&n,&m);
    for (int i = 0 ; i < n ; i ++)InsertVex(G);
    for (int i = 0 ; i < m ; i ++)
    {
        int x,y,ai;
        scanf ("%d%d%d",&x,&y,&ai);
        InsertArc(G,x,y,ai);
    }
    printf("\n");
    print_ayaroute(G,0);
}
void Find_in_de (ALGraph *G , int vex)
{
    VNode *N;
    ArcNode *node;
    queue *Q = create_queue();
    push_queue (Q,&G -> vertices[vex]);
    while(Q -> len > 0)
    {
        pop_queue(Q,&N,HEAD);
        for (node = N -> firstarc ; node != NULL ;node = node -> nextarc)
        {
            G -> vertices[node -> adjvex] . in_de += 1;
            if (visit[node -> adjvex] == FALSE)
            {
                visit[node -> adjvex] = TRUE;
                push_queue(Q,&G -> vertices[node -> adjvex]);
            }
        }
    }
}
void print_ayaroute (ALGraph *G ,int vex)
{
    int min_time[MAX_VERTEX_NUM] = {0};
    int max_time[MAX_VERTEX_NUM];
    

    queue *Q = create_queue (),*T = create_queue();
    Find_in_de(G,0);
    push_queue(Q,&G -> vertices [vex]);
    while(Q -> len > 0)
    {
        VNode *node;
        ArcNode *arc;
        pop_queue(Q,&node,HEAD);
        push_queue(T,node);
        for (arc = node -> firstarc ; arc != NULL ; arc = arc -> nextarc)
        {
            if (arc -> ai + min_time[node -> vex] > min_time[arc -> adjvex])
            {
                min_time[arc -> adjvex] = arc -> ai + min_time[node -> vex];
            }
            G -> vertices[arc -> adjvex] . in_de -= 1;
            if (G -> vertices[arc -> adjvex] . in_de <= 0)
            {
                push_queue(Q,&G -> vertices[arc -> adjvex]);
            }
        }
    }
    for (int num = 0 ; num < G -> vexnum ; num ++)
    {
        max_time[num] = min_time[G -> vexnum - 1];
    }
    while(T -> len > 0)
    {
        VNode *node;
        ArcNode *arc;
        pop_queue(T,&node,TAIL);
        for (arc = node -> firstarc ; arc != NULL ; arc = arc -> nextarc)
        {
            if (max_time[node -> vex] > max_time[arc -> adjvex] - arc -> ai)
            {
                max_time[node -> vex] = max_time[arc -> adjvex] - arc -> ai;
            }
        }
        if (max_time[node -> vex] == min_time[node -> vex])
        {
            printf("%d,",node -> vex);
        }
    }
    
}
void InsertVex(ALGraph *G)
{
    G -> vertices [G -> vexnum] . vex = G -> vexnum;
    G -> vertices [G -> vexnum] . firstarc = NULL;
    G -> vertices [G -> vexnum] . in_de = 0;
    G -> vexnum += 1;
}

void InsertArc(ALGraph *G , int  x , int y , int ai )
{
	ArcNode *Node;

	G -> arcnum += 1;
	Node = (ArcNode *) malloc (sizeof (ArcNode));
	Node -> adjvex = y;
    Node -> ai = ai;
	Node -> nextarc = G -> vertices [x] . firstarc;

	G -> vertices[x] . firstarc = Node;
}
queue *create_queue (void)
{
    queue *Q = (queue *) malloc (sizeof(queue));
    Q -> queue = NULL;
    Q -> end   = NULL;
    Q -> len = 0;
    return Q;
}
void pop_queue (queue *Q,VNode **data,int from)
{
    struct List *retur;
    if (Q -> queue == NULL || Q -> end == NULL)return;
    if (from == HEAD)
    {
        retur = Q -> queue;
        Q -> queue = Q -> queue -> next;
        if (Q -> queue != NULL)Q -> queue -> prev = NULL;
        else Q -> end = NULL;
        *data = retur -> data;
        Q -> len -= 1;
        free (retur);
    }
    else if (from == TAIL)
    {
        retur = Q -> end;
        Q -> end = Q -> end -> prev;
        if (Q -> end != NULL)Q -> end -> next = NULL;
        else Q -> queue = NULL;
        *data = retur -> data;
        Q -> len -= 1;
        free (retur);
    }
    return ;
}
void push_queue (queue *Q,VNode *data)
{
    struct List *push = (struct List *) malloc (sizeof (struct List));
    push -> data = data;
    push -> next = NULL;
    if (Q -> end != NULL)Q -> end -> next = push;
    push -> prev = Q -> end;
    Q -> end = push;
    if (Q -> queue == NULL) Q -> queue = push;
    Q -> len += 1;
    return ;
}