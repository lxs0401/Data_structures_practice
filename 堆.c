#include <stdio.h>
#include <stdlib.h>

int len;
int index;
void up(int *heap,int index)
{
    int temp = heap[index];
    while(index > 0 && temp > heap[ (index - 1)/2 ]){
        heap[index] = heap[(index - 1)/2];
        index = (index - 1)/2;
    }
    heap[index] = temp;
}
void down (int *heap,int index,int len)
{
    int dad = index , son = dad * 2 + 1;
    while (son < len)
    {
        if (son + 1 < len && heap[son + 1] > heap[son])son += 1;
        if (heap[dad] > heap[son])break;
        else
        {
            int temp;
            temp = heap[dad];
            heap[dad] = heap[son];
            heap[son] = temp;
            dad = son;
            son = son * 2 + 1;
        }
    }
}
void push(int *heap,int data)
{
    heap[len] = data;
    len += 1;
    up(heap,len - 1);
}
int pop(int *heap)
{
    int data = heap[0];
    heap[0] = heap[len - 1];
    down(heap,0,len - 1);
    len -= 1;
    return data;
}
int main ()
{
    int *heap = (int *)malloc(sizeof(int)*10000);
    int num;
    int len = 0;
    while(scanf("%d",&num) != EOF)
    {
        push(heap,num,len);
        len += 1;
    }
    while(len > 0)
    {
        printf("%d ",pop(heap,len));
        len -= 1;
    }
}