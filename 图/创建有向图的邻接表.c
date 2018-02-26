#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef enum {DG,DN,UDG,UDN} GraphKind;

typedef struct ArcNode 
{
	int adjvex;
	struct ArcNode *nextarc;
	char *info;
}ArcNode;
typedef struct VNode
{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct 
{
	AdjList vertices;
	int vexnum,arcnum;
	GraphKind kind;
}ALGraph;
ALGraph cj_linjie_pic (char *point_mess , char (* gu_mess)[2] , int vexnum , int arcnum);

int main (void)
{
	ALGraph a;
	char *point_mess , (* gu_mess)[2];
	int vexnum , arcnum;
	
	point_mess = (char *) malloc (sizeof (char) * 10);
	gu_mess = (char (*)[2]) malloc (sizeof (char [2]) * 10);
	printf ("Plaese INPUT point and edge num:");
	scanf ("%d,%d" , &vexnum , &arcnum);
	
	printf ("Plaese INPUT point message:");
	for (int num = 0 ; num < vexnum ; num ++)
	{
		point_mess[num] = getchar();
	}
	printf ("Plaese INPUT edge message:");
	gu_mess[0][0] = 0 , gu_mess[0][1] = 1;
	gu_mess[1][0] = 1 , gu_mess[1][1] = 2;
	gu_mess[2][0] = 0 , gu_mess[2][1] = 2;
	a = cj_linjie_pic(point_mess,gu_mess,vexnum,arcnum);
}

ALGraph cj_linjie_pic (char *point_mess , char (*gu_mess)[2] , int vexnum , int arcnum)
{
	ALGraph pic;
	
	
	pic . vexnum = vexnum;
	pic . arcnum = arcnum;
	pic . kind = DG;
	
	for (int num = 0 ; num < vexnum ; num ++)
	{
		pic.vertices [num] . data = point_mess[num];
		pic.vertices [num] . firstarc = NULL;
	}
	for (int num = 0 ; num < arcnum ; num ++)
	{
		struct ArcNode *p;
		if ( pic.vertices [gu_mess [num][0]].firstarc == NULL )
		{
			pic.vertices [gu_mess [num][0]].firstarc = (ArcNode *) malloc (sizeof (ArcNode));
			pic.vertices [gu_mess [num][0]].firstarc -> adjvex = gu_mess [num][1];
			pic.vertices [gu_mess [num][0]].firstarc -> info = NULL;
			pic.vertices [gu_mess [num][0]].firstarc -> nextarc = NULL;
		}
		else
		{
			p = pic.vertices [gu_mess [num][0]].firstarc;
			for (int num = 0 ; num < MAX_VERTEX_NUM && p -> nextarc != NULL ; num ++ , p = p -> nextarc );
			p -> nextarc = (ArcNode *) malloc (sizeof (ArcNode));
			p = p -> nextarc;
			p -> adjvex = gu_mess [num][1];
			p -> nextarc = NULL;
			p -> info = NULL;
		}
	
		
	}
	return pic;
}