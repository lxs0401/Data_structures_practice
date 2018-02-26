#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Tree
{
    char data;
    struct Tree *lchild,*rchild;
}Tree;
int * complitesw(int *w,int len);
Tree *enableSTree(char *str,int *sw,int len);
int main ()
{
    Tree *tree;
    int w[5] = {1,29,2,30,3};
    int *sw = (int *) malloc (sizeof(int) * 10);
    char str[10] = {'A','B','C','D','E'};
    sw = complitesw(w,5);
    tree = enableSTree(str,sw,5);

}
Tree *enableSTree(char *str,int *sw,int len)
{
    Tree *tree = (Tree *) malloc (sizeof(Tree));
    int min , min_cost = sw[len - 1];
    int lmin , minl;
    for (int i = 1 ; i < len ; i ++)
    {
        if (min_cost > abs(sw[len - 1] - sw[i] - sw[i - 1]))
        {
            min = i;
            min_cost = abs(sw[len - 1] - sw[i] - sw[i - 1]);
        }
    }
    
    lmin = min - 1;
    minl = min + 1;
    if (lmin >= 0 && sw[min] - sw[min - 1] < sw[lmin] - ((lmin - 1 >= 0) ? sw[lmin - 1] : 0))
    {
        min = lmin;
    }
    if (minl < len &&  sw[min] - (min - 1 >= 0 ? sw[min - 1] : 0) <  sw[minl] - (minl - 1 >= 0 ? sw[minl - 1]:0 ))
    {
        min = minl;
    }
    tree -> data = str[min];
    if (min > 0)
        tree -> lchild = enableSTree(str,sw,min); //min - 1 ,但数组下标为0
    else tree -> lchild = NULL;

    if (len - min - 1 > 0)
        tree -> rchild = enableSTree(str + min + 1,sw + min + 1,len - min - 1);
    else tree -> rchild = NULL;
    return tree;
}
int * complitesw(int *w,int len)
{
    int add = w[0];
    int *sw = (int *) malloc (sizeof(int) * len);
    sw [0] = w[0];
    for (int i = 1 ; i < len ; i ++)
    {
        add += w[i];
        sw[i] = add;
    }
    return sw;
}