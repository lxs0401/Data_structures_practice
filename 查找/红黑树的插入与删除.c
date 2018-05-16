#include <stdio.h>
#include <stdlib.h>

#define MALLOC(x, y) ((x *)malloc(sizeof(x) * y))
#define RED   0
#define BLACK 1
#define TRUE  1
#define FALSE 0
typedef struct RBtree
{
	_Bool nill;
	_Bool color;
	int key;
	struct RBtree *lchild, *rchild;
	struct RBtree *p;
} rbtree;
void rbInsert(rbtree *tree,rbtree *node,rbtree **root); //insert
void rbDelete(rbtree **root,rbtree *node,rbtree *nill); //delete
rbtree *search(int key,rbtree *root);                   //search
rbtree *init(void);
rbtree *newnode(int key);

int main ()
{
	rbtree *nill = init(),*root = nill;
	int len;
	scanf("%d",&len);

	for(int i = 0 ; i < len ; i ++)
	{
		int key;
		scanf("%d",&key);
		rbInsert(nill,newnode(key),&root);
	}
	for(int i = 0 ; i < len ; i ++)
	{
		rbtree *delete;
		int key;
		scanf("%d",&key);
		delete = search(key,root);
		if(delete->nill != TRUE)rbDelete(&root,delete,nill);
	}
}
rbtree *search(int key,rbtree *root)
{
	if(root->nill == TRUE || root->key == key){
		return root;
	}
	else if (key < root->key){
		return search(key,root->lchild);
	}
	else {
		return search(key,root->rchild);
	}
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
	if(y->rchild->nill == FALSE){
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

rbtree *treeSuccessor(rbtree *node) //
{
	rbtree *prev;
	rbtree *mininum = node -> rchild;
	while (mininum->lchild->nill == FALSE){
		mininum = mininum->lchild;
	}
	return mininum;
}
void rbDeleteFixup(rbtree **root,rbtree *x)
{
	rbtree *w;
	while(x != *root && x->color == BLACK)
	{
		if(x == x->p->lchild)
		{
			w = x->p->rchild;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				leftRotete(x->p,root);
				w = x->p->rchild;
			}
			if(w->color == BLACK && w->lchild->color == BLACK && w->rchild->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else if (w->color == BLACK && w->lchild->color == RED && w->rchild->color == BLACK)
			{
				w->color = RED;
				rightRotete(w,root);
				w = x->p->rchild;
			}
			else if (w -> color == BLACK && w->rchild->color == RED)
			{
				w->color = x->p->color;
				x->p->color = BLACK;
				w->rchild->color = BLACK;
				leftRotete(x,root);
				x = *root;
			}
		}
		else
		{
			w = x->p->lchild;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				rightRotete(x->p,root);
				w = x->p->lchild;
			}
			if(w->color == BLACK && w->lchild->color == BLACK && w->rchild->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else if (w->color == BLACK && w->rchild->color == RED && w->lchild->color == BLACK)
			{
				w->color = RED;
				leftRotete(w,root);
				w = x->p->lchild;
			}
			else if (w -> color == BLACK && w->lchild->color == RED)
			{
				w->color = x->p->color;
				x->p->color = BLACK;
				w->lchild->color = BLACK;
				rightRotete(x,root);
				x = *root;
			}
		}
	}
	x->color = BLACK; //
}
void rbDelete(rbtree **root,rbtree *node,rbtree *nill)
{
	rbtree *z = node,*y,*x;
	if(node->lchild == nill || node->rchild == nill){
		y = z;
	}
	else{
		y = treeSuccessor(z);
	}
	if (y->lchild != nill){
		x = y->lchild;
	}
	else{
		x = y->rchild;
	}
	x->p = y->p;
	if(y->p == nill){
		*root = x;
	}
	else if (y == y->p->lchild){
		y->p->lchild = x;
	}
	else{
		y->p->rchild = x;
	}
	if(y != z){
		z->key = y->key;
		//copy y's satellite data into z
	}
	if (y->color == BLACK)
	{
		rbDeleteFixup(root,x);
	}
}
rbtree *newnode(int key)
{
	rbtree *node = MALLOC(rbtree,1);
	node->color = RED;
	node->key = key;
	node->nill = FALSE;
	return node;
}
rbtree *init(void)
{
	rbtree *newtree = MALLOC(rbtree,1);
	newtree->nill = TRUE;
	newtree->color = BLACK;
	return newtree;
}

void rbInsertFixup(rbtree *node,rbtree **root)
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
void rbInsert(rbtree *nill,rbtree *node,rbtree **root)
{
	rbtree *y = nill,*x = *root;//nill,root
	while(x->nill == FALSE)
	{
		y = x;
		if(node->key < x->key){
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
	else if (node->key < y->key){
		y->lchild = node;
	}
	else{
		y->rchild = node;
	}
	node->lchild = nill;    //nill
	node->rchild = nill;    //nill
	node->color = RED;
	rbInsertFixup(node,root);
}
