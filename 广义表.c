#include <stdio.h>
#include <stdlib.h>
typedef enum {ATOM , LIST}ElemTag;

typedef struct GLNode
{
	ElemTag tag;
	union {
		int e;
		struct GLNode *hp;
	}point;
	struct GLNode *tp;
}*GList;
int gy_xd (GList a , GList b);  //返回广义表a和广义表b是否想等
void copy_gyb(GList a , GList b); //复制光仪表
int gy_sd (GList list); //返回广义表深度
int cj_gy (GList list , char *size , int len); //创建广义表

int gy_xd (GList a , GList b)
{
	GList p,q;
	for ( p = a , q = b ; p || q ; p = p -> tp , q = q -> tp)
	{
		
		if ( (p == NULL) && q )
		{
			return 0;
		}
		if ( p && (q == NULL) )
		{
			return 0;
		}
		
		if (p -> tag == q -> tag)
		{
			if ( p -> tag == ATOM)
			{
				if ( p -> point.e != q -> point.e )
				{
					return 0;
				}
			}else{
				if ( ! gy_xd ( p -> point.hp , q -> point.hp ) )
				{
					return 0;
				}
			}
			
		}else {
			return 0;
		}
	}
	return 1;
}
void copy_gyb(GList a , GList b)
{
	GList p,q;
	
	for (   p = a , q = b   ;   p   ;   (p = p -> tp) , (q = q -> tp)  )
	{
		if (p -> tag == ATOM)
		{
			q -> tag = ATOM;
			q -> point.e = p -> point.e;
		}else if (p -> tag == LIST){
			q -> tag = LIST;
			q -> point.hp = (GList) malloc (sizeof (struct GLNode));
			copy_gyb ( p -> point.hp , q -> point.hp );
		}
		if (p -> tp)
		{
			q -> tp = (GList) malloc (sizeof (struct GLNode));
		}else{
			q -> tp = NULL;
		}
	
	}
}

int gy_sd (GList list)
{
	GList b;
	int x = 1;
	if (list == NULL) return 0;
	for ( b = list ; b ; b = b -> tp)
	{
		if (b -> tag == LIST )
		{
			x += gy_sd ( b -> point.hp );
		}
	}
	return x;
}
int cj_gy (GList list , char *size , int len)
 {
	 GList p;
	 p = list ;
	  for (int x = 0 ; x < len ; x ++ )
	  {
		  if (size [x] == '(')
		  {
			  p -> tag = LIST;
			  p -> point.hp = (GList) malloc(sizeof (struct GLNode));
			  x += cj_gy (p -> point.hp , size + x + 1 , len);
			  
		  }else if (size [x] > '0' && size [x] < '9'){
			  
			  p -> tag = ATOM;
			  p -> point.e = size [x];
			  
		  }else if ( size [x] == ',' ){
			  p -> tp = (GList) malloc (sizeof (struct GLNode));
			  p = p -> tp;
		  }else if ( size [x] == ')'){
			  
			  p -> tp = NULL;
			  return x + 1;
			  
		  }
	  }
	  p -> tp = NULL;
	  return 1;
 }
 int main()
 {
	 GList a,b;
	 a = (GList)malloc (sizeof (struct GLNode));
	 b = (GList)malloc (sizeof (struct GLNode));
	 cj_gy (a,"1,(1,2,3),2",11);
	 cj_gy (b,"1,(1,2,3)",9);
	 printf("%d",gy_xd (a,b));
	 
 }