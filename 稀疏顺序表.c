#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 25
#define MAX_HANG 5
struct point {
	int buff;
	int i,j;
};
struct ju_z {
	struct point size[MAX_SIZE];
	int mubuff[MAX_HANG];
	int nu,mu,tu;
};

struct ju_z  cj_xs(int (*jz)[3],int x_max,int y_max); 			 //创建稀疏矩阵
int **dy_xs(struct ju_z xsjz);				  				  //转换稀疏矩阵为普通矩阵
struct ju_z jz_xj(struct ju_z a,struct ju_z b); 				//稀疏矩阵相加
void jz_zj(struct ju_z a,struct ju_z b); 						//加在矩阵a上



void jz_zj(struct ju_z a,struct ju_z b)
{
	int mu = a.mu , nu = a.nu , tu = a.tu;
	int ah_max,bh_max;
	int o = 0,t = 0;
	
	for(int x=0;x < mu;x++)
	{
		ah_max = a.mubuff[x];
		bh_max = b.mubuff[x];
		while((o < ah_max) && (t < bh_max))
		{
			if(a.size[o].j == b.size[t].j)
			{
				a.size[o].buff += b.size[t].buff;
				t++,o++;
			}else if(b.size[t].j > a.size[o].j){
				o++;
			}
		}
	}
}

struct ju_z jz_xj(struct ju_z a,struct ju_z b)
{
	struct ju_z list;
	int mu = a.mu ,nu = a.nu , tu = a.tu;
	int ah_max,bh_max;
	int o=0,t=0;
	int h=0;
	if( ! ( a.mu == b.mu && a.nu == b.nu && a.tu == b.tu ) ) return list;
	else {list.mu = a.mu ; list.nu = a.nu ; }
	
	for(int x = 0; x < mu ; x ++ ){
		ah_max = a.mubuff[x] , bh_max = b.mubuff[x];
		
		while( ( o < ah_max ) && ( t < bh_max )){
			if(a.size[o].j < b.size[t].j){
				list.size[h] = a.size[o];
				o++; h++;
			}else if(a.size[o].j == b.size[t].j){
				list.size[h] = a.size[o];
				list.size[h].buff = a.size[o].buff + b.size[t].buff;
				o++; t++; h++;
			}else if (a.size[o].j > b.size[t].j){
				list.size[h] = b.size[t];
				t++; h++;
			}
		}
		
		while (o < ah_max){
			list.size[h] = a.size[o];
			h++;o++;
		}
		
		while (t < bh_max){
			list.size[h] = b.size[t];
			h++; t++;
		}
		
		list.mubuff[x] = h;
		
	}
	list . tu = h ;
	return list;
}

struct ju_z  cj_xs(int (*jz)[3],int x_max,int y_max)
{
	struct ju_z list;
	int h_max=0;
	
	list.mu = x_max;
	list.nu = y_max;
	
	for(int x = 0;x < x_max; x ++){
		for(int y = 0;y < y_max; y ++){
			if(jz[x][y]){
				list.size[h_max].buff = jz[x][y];
				list.size[h_max].i = x;
				list.size[h_max].j = y;
				h_max ++;
			}
		}
		list.mubuff[x] = h_max;
	}
	list.tu = h_max;
	return list;
}
int **dy_xs(struct ju_z xsjz)
{
	int h_max = xsjz.tu;
	int x_max , y_max;
	int **i;
	
	x_max = xsjz.mu , y_max = xsjz.nu ;
	
	i=(int **)malloc(sizeof(int *)*x_max);
	
	for(int x = 0 ; x < x_max ; x++){
		i[x] = (int *) malloc ( sizeof(int) * y_max );
	}
	for(int x=0;x < x_max;x++){
		for(int y=0;y < y_max;y++){
			i[x][y] = 0;
		}
	}
	for(int x=0;x<h_max;x++){
		i [xsjz.size[x].i] [xsjz.size [x].j] = xsjz.size[x].buff;
	}
	return i;
}
int main()
{
	int a[3][3]={
		{1,2,3},{1,2,2},{3,2,4}
	};
	int b[3][3]={
		{3,2,1},{1,0,3},{1,2,4}
	};
	int **l;
	struct ju_z list,list2,list3;
	list = cj_xs(a,3,3);
	list2 = cj_xs(b,3,3);
	jz_zj(list,list2);
	l = dy_xs(list);
	
}



