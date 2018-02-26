#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EH 0
#define LH 1
#define RH 2
#define TRUE  1
#define FALSE 0

#define HEAD  0
#define TAIL  1

typedef struct Tree
{
    char data;
    int status;
    struct Tree *lchild,*rchild;
}Tree;
struct List
{
    Tree *data;
    struct List *next;
    struct List *prev;
};
typedef struct dui
{
    struct List *queue;
    struct List *end;
    int len;
}queue;

void push_queue (queue *Q,Tree *data);
void pop_queue (queue *Q,Tree **data,int from);
queue *create_queue (void);
void Right_Blance (Tree **tree);
void Left_Blance (Tree **tree);
void Lmove(Tree **tree);
void Rmove(Tree **tree);
int InsertAVL (Tree **tree,int data,int *taller);
void printt (Tree *tree)
{
    queue *a = create_queue();
    Tree **l = (Tree **) malloc (sizeof(Tree *) * 20);
    int i = 0;
    push_queue(a,tree);
    printf("%c",tree -> data);
    for (int j = 0 ; j < 20 ; j ++)
    {
        l[j] = (Tree *) malloc (sizeof(Tree));
    }
    while(a -> len > 0)
    {
        printf("\n");
        for (i = 0 ; a -> len > 0 ; i ++)
        {
            pop_queue(a,l + i,HEAD);
        }
        for (int j = 0 ; j < i ; j ++)
        {
            l[j] -> lchild != NULL ? printf("(%c,%c) ",l[j] -> data,l[j] -> lchild -> data),push_queue(a,l[j] -> lchild):printf("(%c,^)",l[j] -> data);
            l[j] -> rchild != NULL ? printf("(%c,%c) ",l[j] -> data,l[j] -> rchild -> data),push_queue(a,l[j] -> rchild):printf("(%c,^)",l[j] -> data);
        }

    }
}
queue *create_queue (void)
{
    queue *Q = (queue *) malloc (sizeof(queue));
    Q -> queue = NULL;
    Q -> end   = NULL;
    Q -> len   = 0;
    return Q;
}
void pop_queue (queue *Q,Tree **data,int from)
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
void push_queue (queue *Q,Tree *data)
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
int main ()
{
    Tree *tree = NULL;
    char *str = (char *) malloc (sizeof(char) * 30);
    int len;
    int taller = FALSE;
    scanf("%s",str);
    len = strlen(str);
    for (int i = 0 ; i < len ; i ++)
    {
        InsertAVL(&tree,str[i],&taller);
    }
    printt(tree);
}
int InsertAVL (Tree **tree,int data,int *taller)
{
    if ((*tree) == NULL)
    {
        (*tree) = (Tree *) malloc (sizeof(Tree));
        (*tree) -> data = data;
        *taller = TRUE;
        (*tree) -> status = EH;
        (*tree) -> lchild = (*tree) -> rchild = NULL;
        *taller = TRUE;
    }
    else 
    {
        if ((*tree) -> data == data)
        {
            return FALSE;
        }
        else if ((*tree) -> data < data)
        {
            if(InsertAVL(&((*tree) -> rchild),data,taller) == FALSE)
            {
                return FALSE;
            }
            if (*taller == TRUE)
            {
                switch ((*tree) -> status)
                {
                    case EH : (*tree) -> status = RH; *taller = TRUE;   break;
                    case RH : Left_Blance(tree);      *taller = FALSE;  break;
                    case LH : (*tree) -> status = EH; *taller = FALSE;  break;
                }
            }
        }
        else if ((*tree) -> data > data)
        {
            if(InsertAVL(&((*tree) -> lchild),data,taller) == FALSE)
            {
                return FALSE;
            }
            if (*taller == TRUE)
            {
                switch ((*tree) -> status)
                {
                    case EH : (*tree) -> status = LH;*taller = TRUE;   break;
                    case LH : Right_Blance(tree);  *taller = FALSE;    break;
                    case RH : (*tree) -> status = EH; *taller = FALSE; break;
                }
            }
        }
    }
    return TRUE;
}
void Rmove(Tree **tree)
{
    Tree *p = (*tree) -> lchild;
    (*tree) -> lchild = p -> rchild;
    p -> rchild = *tree;
    *tree = p;
    return ;
}
void Lmove(Tree **tree)
{
    Tree *p = (*tree) -> rchild;
    (*tree) -> rchild = p -> lchild;
    p -> lchild = *tree;
    *tree = p;
    return ;
}
void Left_Blance (Tree **tree)
{

    if ((*tree) -> rchild -> status == RH)
    {
        (*tree) -> status = (*tree) -> rchild -> status = EH;
        Lmove(tree);
    }
    else if ((*tree) -> rchild -> status == LH)
    {
        Tree *rchild = (*tree) -> rchild,*rlchild = rchild -> lchild;
        switch (rlchild -> status)
        {
            case EH : rchild -> status = (*tree) -> status = EH;break;
            case LH : rchild -> status = RH ; (*tree) -> status = EH; break;
            case RH : rchild -> status = EH ; (*tree) -> status = LH; break;
        }
        rlchild -> status = EH;
        Rmove( &((*tree) -> rchild) );
        Lmove(tree);
    }
}
void Right_Blance (Tree **tree)
{

    if ((*tree) -> lchild -> status == LH)
    {
        (*tree) -> status = (*tree) -> lchild -> status = EH;
        Rmove(tree);
    }
    else if ((*tree) -> lchild -> status == RH)
    {
        Tree *lchild = (*tree) -> lchild,*lrchild = lchild -> rchild;
        switch (lrchild -> status)
        {
            case EH : lchild -> status = (*tree) -> status = EH;      break;
            case RH : lchild -> status = LH ; (*tree) -> status = EH; break;
            case LH : lchild -> status = EH ; (*tree) -> status = RH; break;
        }
        lrchild -> status = EH;
        Lmove( &((*tree) -> lchild) );
        Rmove(tree);
    }
}
