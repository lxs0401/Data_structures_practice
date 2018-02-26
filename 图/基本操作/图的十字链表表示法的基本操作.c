#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
typedef struct ArcBox 
{
	int tailvex,headvex;			//该弧的尾和头顶点的位置
	struct ArcBox *hlink,*tlink;	//分别为弧头相同和弧尾相同弧的链域
	char *info;
}ArcBox;

typedef struct VexNode 
{
	char data;
	ArcBox *firstin,*firstout;		//分别指向该顶点第一条入弧和出弧
}VexNode;

typedef struct 
{
	VexNode xlist[MAX_VERTEX_NUM];	//表头向量
	int vexnum , arcnum;			//有向图的当前定点数和弧数
}OLGraph;

void DeleteVex (OLGraph *G , int v);
void DeleteArc (OLGraph *G , int x , int y);
void InserArc (OLGraph *G , int x , int y);
void InsertVex (OLGraph *G , int v , char data);

int main ()
{
	OLGraph *G;
	G = (OLGraph *) malloc (sizeof (OLGraph));
	G -> arcnum = 0;
	G -> vexnum = 0;
	for (int x = 0 ; x < MAX_VERTEX_NUM ; x ++)
	{
		G -> xlist [x] . firstin = NULL;
		G -> xlist [x] . firstout = NULL;
		G -> xlist [x] . data = 0;
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		InsertVex (G , x , x);
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		for (int y = 0 ; y < 3 ; y ++)
		{
			if (x != y)
				InserArc (G , x , y);
		}
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		for (int y = 0 ; y < 3 ; y ++)
		{
			if (x != y)
				DeleteArc (G , x , y);
		}
	}
	for (int x = 0 ; x < 3 ; x ++)
	{
		DeleteVex (G , x);
	}
}
void DeleteArc (OLGraph *G , int x , int y)
{
	int vexnum = G -> vexnum;
	ArcBox *Node ,*up;
	{//删除x结点的弧信息
		Node = G -> xlist [x] . firstout;
		if (Node -> headvex == y)
		{
			G -> xlist [x] . firstout = Node -> tlink;
		}
		else
		{
			while (Node != NULL && Node -> headvex != y)
			{
				up = Node;
				Node = Node -> tlink;
			}
			if (Node != NULL && Node -> headvex == y)
			{
				up -> tlink = Node -> tlink; 
			}
		}
	}
	{//删除y结点的弧信息
		Node = G -> xlist [y] . firstin;
		if (Node -> tailvex == x)
		{
			G -> xlist [y] . firstin = Node -> hlink;
		}
		else
		{
			while (Node != NULL && Node -> tailvex != x)
			{
				up = Node;
				Node = Node -> hlink;
			}
			if (Node != NULL && Node -> tailvex == x)
			{
				up -> hlink = Node -> hlink;
			}
		}
	}
}
void InserArc (OLGraph *G , int x , int y)
{
	ArcBox *edge;
	edge = (ArcBox *) malloc (sizeof (ArcBox));

	edge -> tailvex = x;
	edge -> headvex = y;

	edge -> tlink = G -> xlist[x] . firstout;
	G -> xlist [x] . firstout = edge;

	edge -> hlink = G -> xlist[y] . firstin;
	G -> xlist[y] . firstin = edge;
}
void InsertVex (OLGraph *G , int v , char data)
{
	int vexnum = G -> vexnum;
	G -> vexnum += 1;
	vexnum += 1;

	G -> xlist [vexnum - 1] . firstin = NULL;
	G -> xlist [vexnum - 1] . firstout = NULL;
	G -> xlist [vexnum - 1] . data = data;
}
void DeleteVex (OLGraph *G , int v)
{
	int vexnum = G -> vexnum;

	{//删除该点的所有的弧	
		ArcBox *Node = NULL;

		for ( int num = 0 ; num < vexnum ; num ++ )
		{
			if (num != v)
			{
				if (G -> xlist [num] . firstout != NULL && G -> xlist [num] . firstout -> headvex == v)
				{
					G -> xlist [num] . firstout = G -> xlist [num] . firstout -> tlink;
				}
				else
				{
					Node = G -> xlist [num] . firstout;
					while (Node != NULL && Node -> tlink != NULL && Node -> tlink -> headvex != v)
					{
						Node = Node -> tlink;
					}
					if (Node != NULL && Node -> tlink != NULL && Node -> tlink -> headvex == v)
					{
						Node -> tlink = Node -> tlink -> tlink;
					}
				}

				if (G -> xlist [num] . firstin != NULL && G -> xlist [num] . firstin -> tailvex == v )
				{
					G -> xlist [num] . firstin = G -> xlist [num] . firstin -> hlink;
				}
				else
				{
					Node = G -> xlist [num] . firstin;
					while (Node != NULL && Node -> hlink != NULL && Node -> hlink -> tailvex != v)
					{
						Node = Node -> hlink;
					}
					if (Node != NULL && Node -> hlink != NULL && Node -> hlink -> tailvex == v)
					{
						Node -> hlink = Node -> hlink -> hlink;
					}
				}
			}
		}
	}

	for ( int num = 1 ; num < vexnum ; num ++ )
	{
		G -> xlist[num] = G -> xlist[num - 1];
	}
	G -> xlist [v] . firstin = NULL;
	G -> xlist [v] . firstout = NULL;
	G -> xlist [v] . data = 0;
	G -> vexnum -= 1;
}