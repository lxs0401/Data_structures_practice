#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 50
#define TREE_MAX 50
#define MAX_TREE 20

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild , *rchild ;
}BiTNode , *BiTree;
void print_two_tree (BiTree tree);
void print_two_tree (BiTree tree)
{
	BiTree *list , *list2 ;

	int x1 = 0 , x2 = 0;
	list = (BiTree *) malloc (sizeof (BiTree) * 200);
	list2 = (BiTree *) malloc (sizeof (BiTree) * 200);
	list [x1] = tree;
	x1 += 1;
	printf("%c\n",tree -> data);
	while (x1 > 0)
	{
		char *lang;
		int lang_n = 0;
		
		lang = (char *) malloc (sizeof (char) * 30);
		for (int num = 0 ; num < x1 ; num ++)
		{
			if (list[num] -> lchild != NULL)
			{
				list2 [ x2 ] = list [num] -> lchild;
				x2 += 1;
			}
			if (list[num] -> rchild != NULL)
			{
				list2 [ x2 ] = list [num] -> rchild;
				x2 += 1;
			}
			if (list [num] -> lchild == NULL)
			{
				lang [lang_n] = ' ';
			}
			else
			{
				lang [lang_n] = list [num] -> lchild -> data;
			}
			lang_n += 1;
			if (list[num] -> rchild == NULL)
			{
				lang [lang_n] = ' ';
			}
			else
			{
				lang [lang_n] = list [num] -> rchild -> data;
			}
			lang_n += 1;
			
		}
		lang[lang_n] = 0;
		printf("%s",lang);
		printf ("\n");
		BiTree *temp;
		temp = list;
		list = list2;
		list2 = temp;
		x1 = x2;
		x2 = 0;
		free (lang);
	}
}
