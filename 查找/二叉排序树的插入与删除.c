#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree
{
    char data;
    struct Tree *lchild,*rchild;
}Tree;
void InsertNode(Tree *tree , char data); //插入
void DeleteNode (Tree *tree, char data); //删除
int main ()
{
    Tree *tree = (Tree *) malloc (sizeof(Tree));
    char *str = (char *) malloc (sizeof(char) * 20);
    int len;
    scanf("%s",str);
    len = strlen(str);
    tree -> data = str[0];
    tree -> lchild = NULL;
    tree -> rchild = NULL;
    for (int i = 1 ; i < len ; i ++)
    {
        InsertNode(tree,str[i]);
    }
    for (int i = 1 ; i < len ; i ++)
    {
        DeleteNode(tree,str[i]);

    }
}

void DeleteNode (Tree *tree, char data)
{
    Tree *qnode , *node = tree,*p,*q,*s;
    while(node != NULL && node -> data != data)
    {
        qnode = node;
        if (node -> data > data)
        {
            node = node -> lchild;
        }
        else
        {
            node = node -> rchild;
        }
    }
    if (node == NULL) return;
    if (node -> lchild == NULL)
    {
        if (qnode -> lchild == node)qnode -> lchild = node -> rchild;
        else qnode -> rchild = node -> rchild;
    }
    else if(node -> rchild == NULL)
    {
        if (qnode -> lchild == node)qnode -> lchild = node -> lchild;
        else qnode -> rchild = node -> lchild;
    }
    else
    {
        q = p = node;
        s = p -> lchild;
        while(s -> rchild != NULL)
        {
            q = s;
            s = s -> rchild;
        }
        node -> data = s -> data;
        if (p != q)
        {
            q -> rchild = s -> lchild;
        }
        else 
        {
            q -> lchild = s -> lchild;
        }
    }
    return ;
}
void InsertNode(Tree *tree , char data)
{
    Tree *node = (Tree *) malloc (sizeof(Tree));
    node -> data = data;
    node -> lchild = node -> rchild = NULL;
    if (tree == NULL) return;
    else if (tree -> data == data)return ;
    if (tree -> data > data)
    {
        if (tree -> lchild == NULL)
        {
            tree -> lchild = node;
        }
        else
        {
            InsertNode(tree -> lchild,data);
        }
    }
    else 
    {
        if (tree -> rchild == NULL)
        {
            tree -> rchild = node;
        }
        else
        {
            InsertNode(tree -> rchild,data);
        }
    }
}