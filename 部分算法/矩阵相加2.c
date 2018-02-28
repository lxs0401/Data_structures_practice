#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_HANG
#define MAX_SIZE 25
#define MAX_HANG 5
#endif

struct jz_ {
	int size[MAX_SIZE];
	int mubuff [MAX_HANG][MAX_HANG];
};
struct jz_ jzj_f(struct jz_ a , struct jz_ b)
{
	struct jz_ c;
	int n = 0,o = 0,p = 0;
	for(int x = 0; x < MAX_SIZE ; x ++)
	{
		c.size[x] = 0;
	}
	for(int x = 0; x < MAX_HANG ; x++)
	{
		for(int y = 0; y < MAX_HANG ; y++)
		{
			if(a.mubuff[x][y] && b.mubuff[x][y])
			{
				c.mubuff[x][y] = 1;
				c.size[p] = a.size[n] + b.size[o];
				n ++;
				o ++;
				p ++;
			} else if (a.mubuff[x][y]){
				c.mubuff[x][y] = 1;
				c.size[p] = a.size[n];
				p ++;
				n ++;
			}else if(b.mubuff[x][y]){
				c.mubuff[x][y] = 1;
				c.size[p] = b.size[o];
				p ++;
				o ++;
			}else{
				c.mubuff [x][y] = 0; 
			}
		}
	}
	return c;
	
}
struct jz_ cjj_z (int (*size)[MAX_HANG],int x_max,int y_max)
{
	struct jz_ list;
	int n=0;
	for(int x = 0; x < x_max; x++)
	{
		for (int y = 0; y < y_max ; y++)
		{
			list.mubuff[x][y]=0;
		}
	}
	
	for(int x = 0 ;x < x_max; x++){
		for(int y = 0 ; y < y_max ; y++){
			if(size[x][y]){
				list.size[n] = size[x][y];
				list.mubuff[x][y] = 1;
				n ++;
			}
		}
	}
	return list;
}
int **  dyj_z ( struct jz_ list , int x_max , int y_max )
{
	int **size;
	int n = 0;
	size = (int **)malloc (sizeof(int *) * x_max);
	for(int x = 0;x < x_max; x++)
	{
		size[x] = (int *)malloc (sizeof(int) * y_max); 
		for(int y = 0;y < y_max; y++ )
		{
			size[x][y] = 0;
		}
	}
	
	for(int x = 0; x < x_max ; x ++)
	{
		for(int y = 0; y < y_max ; y++)
		{
			if(list.mubuff[x][y])
			{
				size[x][y] = list.size[n];
				n++;
			}
		}
	}
	return size;
}