#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXKEYLEN 16
#define HUAN 0
typedef struct 
{
    char ch[MAXKEYLEN];
    int num;
}KeysType;
typedef enum {LEAF,BRANCH} NodeKind;
typedef struct DLTNode
{
    char symbol;
    struct DLTNode *next;
    NodeKind kind;
    union 
    {
        char *infoptr;
        struct DLTNode *first;
    };
}DLTNode,*DLTree;
void InsertDLTree (KeysType *key,DLTree T,char *info);
char *SearchDLTree (KeysType *key,DLTree T);
void DelDLTree (KeysType *key,DLTree T);

int main ()
{
    KeysType *key = (KeysType *) malloc (sizeof(KeysType));
    DLTree dt = (DLTree) malloc (sizeof(DLTNode));
    char *str = (char *) malloc (sizeof(char) * 20);
    key -> num = strlen(key -> ch);
    dt -> symbol = 'A';
    dt -> next = NULL;
    dt -> kind = LEAF;
    
    while(EOF != scanf ("%s%s",key -> ch,str))
    {
        key -> num = strlen (key -> ch);
        key -> ch[key -> num] = '*';
        key -> num += 1;
        key -> ch [key -> num] = '\0';
        InsertDLTree (key,dt,str);
        str = (char *) malloc (sizeof(char) * 20);
        printf("%s\n",SearchDLTree (key,dt));
    }
    while(EOF != scanf ("%s",key -> ch))
    {
        key -> num = strlen (key -> ch);
        key -> ch[key -> num] = '*';
        key -> num += 1;
        key -> ch [key -> num] = '\0';
        DelDLTree (key,dt);
        
    }
}
void DelDLTree (KeysType *key,DLTree T)
{
    DLTree  node = T,p = node,line,line_p;
    for (int i = 0 ; i < key -> num ; i ++)
    {
        while( node != NULL && node -> symbol != key -> ch[i] )p = node , node = node -> next;
        if (node != NULL && node -> kind == BRANCH)
        {
            if (p -> next == node || node -> next != NULL)
            {
                line_p = p;
                line = node;
            }
            p = node;
            node = node -> first;
        }
        else if (i + 1 < key -> num)return ;
        else if (node -> kind == LEAF)
        {
            if (p -> next == node || node -> next != NULL)
            {
                line_p = p;
                line = node;
            }
            if (line_p -> next == line)
            {
                line_p -> next = line -> next;
                line_p = line;
                line = line -> first;
            }
            else if (line_p -> first == line)
            {
                line_p -> first = line -> next;
                line_p = line;
                line = line -> first;
            }
            while (line != NULL && line -> kind != LEAF)
            {
                HUAN == 1 ? printf("%c ",line_p -> symbol): free(line_p);
                line_p = line;
                line = line -> first;
            }
            HUAN == 1 ? (line != NULL ? putchar(line -> symbol),putchar(line_p->symbol):putchar(line_p -> symbol)):(line != NULL ? free(line),free(line_p) : free(line_p));
        }
    }
}
void InsertDLTree (KeysType *key,DLTree T,char *info)
{
    DLTree node = T,p = node;
    for (int i = 0 ; i < key -> num ; i ++)
    {
        while(node != NULL && node -> symbol != key -> ch[i])p = node , node = node -> next;
        if (node != NULL && node -> kind == BRANCH)
        {
            node = node -> first;
        }
        else if (node == NULL)
        { 
            p -> next = (DLTree) malloc (sizeof(DLTNode));
            p -> next -> next = NULL;
            node = p -> next;
            node -> symbol = key -> ch[i];
            if (i + 1 < key -> num)
            {
                node -> kind = BRANCH;
                node -> first = (DLTree) malloc (sizeof(DLTNode));
                node = node -> first;
                node -> symbol = key -> ch[i + 1];
                node -> kind = LEAF;
                node -> next = NULL;
            }
            else node -> kind = LEAF;
        }
        else if (node -> kind == LEAF)
        {
            if (i + 1 < key -> num)
            {
                node -> kind = BRANCH;
                node -> first = (DLTree) malloc (sizeof(DLTNode));
                node = node -> first;
                node -> symbol = key -> ch[i + 1];
                node -> next = NULL;
                node -> kind = LEAF;
            }
            else 
            {
                node -> infoptr = info;
                return ;
            }
        }
    }
    node -> infoptr = info;
    return ;
}
char *SearchDLTree (KeysType *key,DLTree T)
{
    DLTree  node = T;
    
    for (int i = 0 ; i < key -> num ; i ++)
    {
        while( node != NULL && node -> symbol != key -> ch[i] )node = node -> next;
        if (node != NULL && node -> kind == BRANCH)
        {
            node = node -> first;
        }
        else if (i + 1 < key -> num)return NULL;
        else if (node -> kind == LEAF)return node -> infoptr;
    }
}