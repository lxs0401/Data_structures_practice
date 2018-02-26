#include <stdio.h>
#include <stdlib.h>
#define MAX_X 3
#define MAX_Y 3
typedef struct OLNode
{
	int i,j;
	int e;
	struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct 
{
	OLink *rhead,*chead;
	int mu,nu,tu;
}CrossList;

void CrossAdd(CrossList *list , OLink p); //添加十字链表节点
int **dyjz_ (CrossList list,int x_max,int y_max); //打印十字链表
CrossList jzxj_(CrossList a , CrossList b); //矩阵相加
CrossList cjxs_ (int a[MAX_X][MAX_Y],int x_max,int y_max); //创建十字链表
void jzzj_ (CrossList a , CrossList b); //矩阵直接加


int main()
{
	int x[MAX_X][MAX_Y] = {
		{1,0,3},{3,2,0},{4,0,9}
	};
	int y[MAX_X][MAX_Y] = {
		{2,2,3},{0,2,3},{4,8,9}
	};
	int ** i; 
	CrossList list,list2,list3;
	list = cjxs_( y , MAX_X , MAX_Y );
	list2 = cjxs_( x , MAX_X , MAX_Y );
	jzzj_ (list,list2);
	i = dyjz_ ( list , MAX_X , MAX_Y );
	for (int x = 0; x < 3 ; x ++)
	{
		for(int y = 0; y < 3 ; y ++)
		{
			printf("%d,",i[x][y]);
		}
		printf("\n");
	}
	printf("%d,%d",list.tu , list2.tu );
}

void jzzj_ (CrossList a , CrossList b)
{
	int mu = a.mu , nu = a.nu , tu;
	OLink y , z;
	for (int x = 0 ; x < mu ; x ++ )
	{
		y = a.rhead[x];
		z = b.rhead[x];
		if ( z != NULL )
		{
			while ( y && z )
			{
				if ( y -> j > z -> j){
					
					CrossAdd(&a,z);
					z = z -> right;
					
				}else if ( (y -> j) == (z -> j) ){
					y -> e += z -> e;
					y = y -> right;
					z = z -> right;
				}else{
					y = y -> right;
				}
			}
			while (z)
			{
				CrossAdd(&a,z);
				z = z -> right;
			}
		}
	}
	return;
}
void CrossAdd(CrossList *list , OLink p)
{
	int i = p -> i , j = p -> j;
	OLink q;
	
	if( (list -> rhead[i] == NULL) || (list -> rhead[i] -> j > j) )
	{
		
		p -> right = list -> rhead[i];
		list -> rhead[i] = p;
		
	} else {
		
		q = list -> rhead[i];
		while ( (q -> right != NULL) && (q -> right -> j < j) )
		{
			q = q -> right;
		}
		
		p -> right = q -> right;
		q -> right = p;
		
	}
	if ( ( list -> chead[j] == NULL ) || (list -> chead[j] -> i > i) )
	{
		
		p -> down = list -> chead[j];
		list -> chead[j] = p;
		
	} else {
		
		q = list -> chead [j];
		
		while ( (q -> down) && (q -> down -> i < i) )
		{
			q = q -> down;
		}
		p -> down = q -> down;
		q -> down = p;
		
	}
	list -> tu ++;
	return ;
}
CrossList jzxj_(CrossList a , CrossList b)
{
	CrossList list;
	OLink p,p2;
	OLink l;
	int mu = a.mu , nu = a.nu;
	
	list.rhead = (OLink *)malloc( sizeof(OLink) * MAX_X );
	list.chead = (OLink *)malloc( sizeof(OLink) * MAX_Y );
	
	list.mu = mu , list.nu = nu , list.tu = 0;
	
	for( int x = 0 ; x < MAX_X ; x ++)
	{
		list.rhead[x] = NULL;
	}
	for (int x = 0 ; x < MAX_Y ; x ++)
	{
		list.chead[x] = NULL;
	}
	
	for(int x = 0; x < mu ; x ++)
	{
		if (a.rhead[x]){
			
			p = a.rhead[x];
			p2 = b.rhead[x];
			while(p && p2)
			{
				if( ( p -> j ) == ( p2 -> j ) )
				{
					l = (OLink) malloc( sizeof( OLNode ) );
					l -> i = x;
					l -> j = p -> j;
					l -> e = (p -> e) + (p2 -> e);
					CrossAdd(&list , l);
					p = p -> right;
					p2 = p2 -> right;
				
				}else if ( (p -> j) < (p2 -> j) )
				{
					l = (OLink) malloc( sizeof( OLNode ) );
					l -> i = x;
					l -> j = p -> j;
					l -> e = p -> e;
					CrossAdd(&list , l);
					p = p -> right;
				}else if ( (p -> j) > (p2 -> j) )
				{
					l = (OLink) malloc( sizeof( OLNode ) );
					l -> i = x;
					l -> j = p2 -> j;
					l -> e = p2 -> e;
					CrossAdd(&list , l);
					p2 = p2 -> right;
				}
			}
			while ( p )
			{
				 l = (OLink) malloc( sizeof( OLNode ) );
				 l -> i = x;
				 l -> j = p -> j;
				 l -> e = p -> e;
				 CrossAdd(&list , l);
				 p = p -> right;
			}
			while ( p2 )
			{
				l = (OLink) malloc( sizeof( OLNode ) );
				l -> i = x;
				l -> j = p2 -> j;
				l -> e = p2 -> e;
				CrossAdd(&list , l);
				p2 = p2 -> right;
			}
		}
	}
	return list;
	
}

CrossList cjxs_ (int a[MAX_X][MAX_Y],int x_max,int y_max)
{
	CrossList list;
	OLink p,q;
	
	list.mu = x_max;
	list.nu = y_max;
	list.tu = 0;
	
	list.rhead = (OLink *) malloc( sizeof(OLink) * x_max);
	list.chead = (OLink *) malloc( sizeof(OLink) * y_max);
	
	for(int x = 0; x < x_max ; x++ )
	{
		list.rhead[x] = NULL;
	}
	for(int y = 0; y < y_max ; y++ )
	{
		list.chead[y] = NULL;
	}
	/*置为0*/
	for(int x = 0;x < x_max ;x ++)
	{
		for(int y = 0;y < y_max ;y++)
		{
			if(a[x][y])
			{
				
				p = (OLink)malloc(sizeof(OLNode));
				p -> i = x;
				p -> j = y;
				p -> e = a[x][y];
				
				CrossAdd(&list,p);	
			}
		}
	}
	return list;
}
int **dyjz_ (CrossList list,int x_max,int y_max)
{
	int **size;
	size = (int **)malloc(sizeof(int) * x_max);
	
	for(int x = 0; x < y_max ; x++)
	{
		size[x] = (int *) malloc( sizeof(int) * y_max);
		for(int y = 0; y < y_max ;y ++)
		{
			size [x][y] = 0;
		}
	}
	
	for(int x = 0;x < x_max; x ++)
	{
		for(OLNode *n = list.rhead[x] ; n ;n = n -> right)
		{
			size[x][n -> j] = n -> e;
		}
	}
	return size;
}