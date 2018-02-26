#include <stdio.h>
#include <stdlib.h>
#ifndef MAX_HANG
#define MAX_SIZE 25
#define MAX_HANG 5
#endif
struct point_t {
	int buff;
	int i,j;
};
struct ju_z_t {
	struct point_t size[MAX_SIZE];
	int mubuff[MAX_HANG];
	int nu,mu,tu;
};

int zj_qs(struct ju_z_t list,int x,int y)
{
	int h_max = list.mubuff[x];
	int h = (x == 0) ? 0 : list.mubuff[x-1];
	
	for ( ; h < h_max ; h ++ ){
		if(list.size[h].j == y)
		{
			return list.size[h].buff;
		}
	}
	return NULL;
}
