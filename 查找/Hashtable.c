#include <stdio.h>
#include <stdlib.h>
#define UNDEF 0
#define DEF 1
#define DELETE 2
#define END -1

#define OK   1
#define FAIL 0

#define A 2654435769/(double)4294967296
struct search
{
    int flag;
    int key;
    int data;
} list[16385];
int gethash(int key)
{
    return 16384*(key*A - (int)key*A);
}
void init(void)
{
    for (int i = 0; i < 16384; i++)
    {
        list[i].flag = UNDEF;
        list[i].data = UNDEF;
    }
    list[16384].flag = END;
}
int push(int key, int data)
{
    struct search *next = &list[gethash(key)];
    while (next->flag == DEF && next->key != key)
        next += 1;
    if (next->flag != END)
    {
        next->flag = DEF;
        next->key = key;
        next->data = data;
        return OK;
    }
    return FAIL;
}
int delete (int key, int data)
{
    struct search *next = &list[gethash(key)];
    while (next->flag == DELETE ||(next->flag == DEF && next->key != key))
        next += 1;
    if(next->flag == DEF)
    {
        next->flag = DELETE;
        return OK;
    }
    return FAIL;
}
struct search *search(int key)
{
    struct search *next = &list[gethash(key)];
    while (next->flag == DELETE ||(next->flag == DEF && next->key != key))
        next += 1;
    if(next->flag == DEF){
        return next;
    }
    return NULL;
}
int main()
{
    int key;
    init();
    scanf("%d", &key);
    for (int i = 0; i < key; i++)
    {
    }
}