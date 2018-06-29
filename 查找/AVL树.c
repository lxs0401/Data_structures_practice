#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EH 0
#define LH 1
#define RH 2
#define TRUE  1
#define FALSE 0


typedef struct Tree
{
	char data;
	int status;
	struct Tree *lchild,*rchild;
}Tree;




void Right_Blance (Tree **tree);
void Left_Blance (Tree **tree);
void Lmove(Tree **tree);
void Rmove(Tree **tree);
int InsertAVL (Tree **tree,int data,int *taller);

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
		if ((*tree) -> data == data){
			return FALSE;
		}
		else if ((*tree) -> data < data)
		{
			if(InsertAVL(&((*tree) -> rchild),data,taller) == FALSE){
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
			if(InsertAVL(&((*tree) -> lchild),data,taller) == FALSE){
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
