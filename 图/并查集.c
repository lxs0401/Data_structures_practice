#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LONG 1010

#define TRUE 1
#define FALSE 0
short list[MAX_LONG];
short rank[MAX_LONG];
struct heap
{
    int i, j;
    int weight;
} heap[499520];
int heaplen;

void up(int index)
{
    struct heap temp = heap[index];
    while (index > 0 && temp.weight < heap[(index - 1) / 2].weight)
    {
        heap[index] = heap[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap[index] = temp;
}
void down(int index, int len)
{
    int dad = index, son = dad * 2 + 1;
    while (son < len)
    {
        if (son + 1 < len && heap[son + 1].weight < heap[son].weight)
            son += 1;
        if (heap[dad].weight < heap[son].weight)
            break;
        else
        {
            struct heap temp;
            temp = heap[dad];
            heap[dad] = heap[son];
            heap[son] = temp;
            dad = son;
            son = son * 2 + 1;
        }
    }
}
void push(int i, int j, int weight)
{
    struct heap new;
    new.i = i;
    new.j = j;
    new.weight = weight;
    heap[heaplen] = new;
    up(heaplen);
    heaplen += 1;
}
struct heap pop(void)
{
    struct heap temp = heap[0];
    heap[0] = heap[heaplen - 1];
    down(0, heaplen - 1);
    heaplen -= 1;
    return temp;
}
int findboss(int x)
{
    if (list[x] == x)
        return x;
    else
        return list[x] = findboss(list[x]);
}
void init(int n)
{
    for (int i = 0; i <= n; i++)
        list[i] = i,rank[i] = 0;
}
int unit(int x, int y, int *ans, int weight)
{
    int rootx, rooty;
    rootx = findboss(x);
    rooty = findboss(y);
    if (rootx != rooty)
    {
        if (rank[rootx] > rank[rooty])
            list[rooty] = rootx;
        else
        {
            list[rootx] = rooty;
            if (rank[x] == rank[y])
                rank[y] += 1;
        }
        *ans += weight;
        return TRUE;
    }
    return FALSE;
}

int main()
{
    int T, t;
    int things[1010];
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        int vexnum;
        int ans = 0;
        heaplen = 0;
        scanf("%d", &vexnum);
        init(vexnum + 1);
        for (int i = 1; i <= vexnum; i++)
        {
            scanf("%d", &things[i]);
        }
        for (int i = 1; i <= vexnum; i++)
        {
            for (int j = i + 1; j <= vexnum; j++)
            {
                int weight;
                weight = 3 * (things[i] + things[j]) + 7;
                push(i, j, weight);
            }
        }
        for (int i = 0; i < vexnum - 1;)
        {
            struct heap edge = pop();
            if (unit(edge.i, edge.j, &ans, edge.weight) == TRUE)
                i += 1;
        }
        printf("%d\n", ans);
    }
}
