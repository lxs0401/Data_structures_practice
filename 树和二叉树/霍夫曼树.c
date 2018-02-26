#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOTHING   0
#define CHARACTOR 1
typedef struct tree
{
    int flag;
    char data;
    int priortoy;
    struct tree *lchild, *rchild;
} tree;
#define MALLOC(x,y) ((x *)malloc(sizeof(x)*y))

void push(tree *heap, tree node, int index)
{
    tree temp = heap[index] = node;
    while (index > 0 && heap[index].priortoy < heap[(index - 1) / 2] . priortoy)
    {
        heap[index] = heap[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap[index] = temp;
}
tree pop(tree *heap, int len)
{
    int dad = 0 , son = dad * 2 + 1;
    tree node = heap[0];
    heap[0] = heap[len - 1];
    while(son < len - 1)
    {
        if (son + 1 < len - 1 && heap[son] . priortoy > heap[son + 1] . priortoy)son += 1;
        if(heap[dad] . priortoy < heap[son] . priortoy)break;
        else 
        {
            tree temp = heap[dad];
            heap[dad] = heap[son];
            heap[son] = temp;
            dad = son;
            son = son * 2 + 1;
        }
    }
    return node;
}
void getstrlong (int *strlong,tree *root,int deep)
{
    if (root == NULL)return ;
    else
    {
        if (root -> flag == CHARACTOR)strlong[root -> data + 128] = deep;
        getstrlong(strlong,root -> lchild,deep + 1);
        getstrlong(strlong,root -> rchild,deep + 1);
    }
}
int huffmanlong (char *str,tree *root,int heaplen)
{
    int truelong = 0;
    int i;
    int *strlong = MALLOC(int,260);
    for (i = 0 ; i < 260 ; i ++)strlong[i] = 0;
    getstrlong(strlong,root,0);
    for (i = 0 ; str[i] != '\0' ; i ++)
    {
        truelong += strlong[str[i] + 128];
    }
    return truelong;
}
int main ()
{
    int i,j;
    char *str = MALLOC(char,1000000);
    int priortoylist[260] = {};
    while(gets(str) != NULL)
    {
        tree *heap = MALLOC(tree,1000);
        tree root ;
        int heaplen = 0,atom;
        int truelong,ansciilong;
        for (i = 0 ; i < 260 ; i ++)priortoylist[i] = 0;
        for (i = 0 ; str[i] != '\0' ; i ++)
        {
            priortoylist[str[i] + 128] += 1;
        }
        for (i = 0 ; i < 260 ; i ++)
        {
            if (priortoylist[i] > 0)
            {
                tree node;
                node . data = i - 128;
                node . lchild = node . rchild = NULL;
                node . priortoy = priortoylist[i];
                node . flag = CHARACTOR;
                push(heap,node,heaplen);
                heaplen += 1;
            }
        }
        atom = heaplen;
        for (i = 0 ; i < atom - 1; i ++)
        {
            tree node;
            tree lchild,rchild;
            tree *childl = MALLOC(tree,1),*childr = MALLOC(tree,1);

            lchild = pop(heap,heaplen);heaplen -= 1;
            rchild = pop(heap,heaplen);heaplen -= 1;
            *childl = lchild;*childr = rchild;
            node . priortoy = lchild . priortoy + rchild . priortoy;
            node . flag = NOTHING;
            node . lchild = childl;
            node . rchild = childr;
            push(heap,node,heaplen);heaplen += 1;
        }
        root = pop(heap,heaplen);heaplen -= 1;
        truelong = huffmanlong (str,&root,heaplen);
        ansciilong = strlen(str) * 8;
        printf ("%d %d %.1f\n",ansciilong,truelong,ansciilong/(double)truelong);
        
    }
}