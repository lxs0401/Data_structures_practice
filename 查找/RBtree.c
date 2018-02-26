#include <stdio.h>
#include <stdlib.h>

#define MALLOC(x, y) ((x *)malloc(sizeof(x) * y))
#define RED   1
#define BLACK 0
#define TRUE  1
#define FALSE 0
typedef struct RBtree
{
    _Bool nill;
    _Bool color;
    int data;
    struct RBtree *lchild, *rchild;
    struct RBtree *p;
} rbtree;
void leftRotete(rbtree *x,rbtree **root);
void rightRotete(rbtree *x,rbtree **root);
void rbInsert(rbtree *tree,rbtree *node,rbtree **root);
void rbInsertFixup(rbtree *tree,rbtree *node,rbtree **root);
rbtree *init(void);
rbtree *newnode(int data);
int main ()
{
    rbtree *tree = init();
    int len;
    scanf("%d",&len);

    for(int i = 0 ; i < len ; i ++) 
    {
        int data;
        scanf("%d",&data);
        rbInsert(tree,newnode(data),&tree->p);
    }

}
rbtree *newnode(int data)
{
    rbtree *node = MALLOC(rbtree,1);
    node->color = RED;
    node->data = data;
    node->nill = FALSE;
    return node;
}
rbtree *init(void)
{
    rbtree *newtree = MALLOC(rbtree,1);
    newtree->nill = TRUE;
    newtree->lchild = newtree->rchild = newtree;
    newtree->color = BLACK;
    newtree->p = newtree;
    return newtree;
}
void rbInsertFixup(rbtree *tree,rbtree *node,rbtree **root)
{
    while(node->p->color == RED)
    {
        if(node->p->p->lchild == node->p)
        {
            rbtree *y = node->p->p->rchild;
            if(y->color == RED)
            {
                node->p->color = BLACK;
                y->color = BLACK;
                node->p->p->color = RED;
                node = node->p->p;
            }
            else if (node == node->p->rchild)
            {
                node = node->p;
                leftRotete(node,root);
                node->p->color = BLACK;
                node->p->p->color = RED;
                rightRotete(node->p->p,root);
            }
            else
            {
                node->p->color = BLACK;
                node->p->p->color = RED;
                rightRotete(node->p->p,root);
            }
        }
        else
        {
            rbtree *y = node->p->p->lchild;
            if(y->color == RED)
            {
                node->p->color = BLACK;
                y->color = BLACK;
                node->p->p->color = RED;
                node = node->p->p;
            }
            else if (node == node->p->lchild)
            {
                node = node->p;
                rightRotete(node,root);
                node->p->color = BLACK;
                node->p->p->color = RED;
                leftRotete(node->p->p,root);
            }
            else
            {
                node->p->color = BLACK;
                node->p->p->color = RED;
                leftRotete(node->p->p,root);
            }
        }
    }
    (*root)->color = BLACK;
}
void rbInsert(rbtree *tree,rbtree *node,rbtree **root)
{
    rbtree *y = tree,*x = *root;//nill,root
    while(x->nill == FALSE)
    {
        y = x;
        if(node->data < x->data){
            x = x->lchild;
        }
        else {
            x = x->rchild;
        }
    }
    node->p = y;
    if(y->nill == TRUE){
        *root = node;
    }
    else if (node->data < y->data){
        y->lchild = node;
    }
    else{
        y->rchild = node;
    }
    node->lchild = tree;    //nill
    node->rchild = tree;    //nill
    node->color = RED;
    rbInsertFixup(tree,node,root);
}
void leftRotete(rbtree *x,rbtree **root)
{
    rbtree *y = x->rchild;
    x->rchild = y->lchild;
    if(y->lchild->nill == FALSE){
        y->lchild->p = x;
    }
    y->p = x->p;
    if(x->p->nill == TRUE){
        *root = y;
    }
    else if (x == x->p->lchild){
        x->p->lchild = y;
    }
    else {
        x->p->rchild = y;
    }
    y->lchild = x;
    x->p = y;
}
void rightRotete(rbtree *x,rbtree **root)
{
    rbtree *y = x->lchild;
    x->lchild = y->rchild;
    if(y->rchild->p == FALSE){
        y->rchild->p = x;
    }
    y->p = x->p;
    if(x->p->nill == TRUE){
        *root = y;
    }
    else if(x->p->lchild == x){
        x->p->lchild = y;
    }
    else{
        x->p->rchild = y;
    }
    y->rchild = x;
    x->p = y;
}
