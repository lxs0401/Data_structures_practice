#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX 100
#define MAX_TREE 20

typedef struct CSNode 
{
	char data;
	struct CSNode *child,*silb;
}CSNode , *CSTree;

CSTree s_dudao_s ( char (* du)[20] , int len );

int main ()
{
	char a[4][MAX_TREE] = {
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{3,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	CSTree qua;
	qua = s_dudao_s ( a , 4);
	
}
CSTree s_dudao_s ( char (* du)[20] , int len )
{
	CSTree *list ,*list2 , root;
	CSTree po;
	list = (CSTree *) malloc (sizeof (CSTree) * MAX_TREE);
	list2 = (CSTree *) malloc (sizeof (CSTree) * MAX_TREE);
	root = (CSTree) malloc (sizeof (CSNode));
	
	list[0] = root;
	root -> child = NULL;
	root -> silb  = NULL;
	for ( int x = 0 ; x < len ; x ++ )
	{
		int p = 0 , point_n = 0;
		for (int y = 0 ; du[x][y] > 0 ; y ++ )
		{
			char num = du [x][y];
		
			po = list2[p] =  list [ point_n ] -> child = (CSTree) malloc ( sizeof (CSNode) );
			p += 1;
			po -> silb  = NULL;
			po -> child = NULL;
			for (int pp = 1 ; num > pp ; pp ++ )
			{
				po -> silb = list2[p] = (CSTree) malloc ( sizeof (CSNode) );
				po = po -> silb;
				po -> child = NULL;
				po -> silb  = NULL;
				p += 1;
			}
			po -> child = NULL;
			po -> silb  = NULL;
			point_n += 1;
		}
		CSTree *temp;
		temp = list2;
		list2 = list;
		list = temp;
	}
	return root;
}
