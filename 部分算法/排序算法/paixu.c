#include <stdio.h>
#include <stdlib.h>
#define NEW(x,y) ((x *)malloc(sizeof(x)*y))
void mp_paixu(int *character,int strle_n)  //冒泡排序
{
	int temp;
	for( int i=0 ;i < strle_n; i++ )
	{
		for(int j=0 ; j < strle_n-i - 1 ;j++ )
		{
			if( character [j] < character [j + 1] )
			{
				temp = character[j];
				character[j] = character[j + 1];
				character[j + 1] = temp;
			}
		}
	}
}

void cr_paixi(int *character,int strle_n)  //插入排序
{
	int temp;
	for(int num = 1 ;num < strle_n; num ++ )
	{
		for(int t_num = num ; t_num && ( character[t_num] < character[t_num - 1] ) ; t_num --)
		{
			temp = character[t_num];
			character[t_num] = character[t_num - 1];
			character[t_num - 1] = temp;
		}
	}
}
void hb_paixu(int *character,int strle_n)  //合并排序
{
	int *arr=character,*b=(int *)malloc(sizeof(int)*strle_n);
	

	for(int seg=1;seg<strle_n;seg+=seg)
	{
		
		for(int start=0;start<strle_n;start+=seg+seg)
		{
			int start1=start,start2= ( start + seg > strle_n ) ? strle_n : (start+seg);
			int end1 = start + seg > strle_n ? strle_n : start+seg , end2 = start+seg+seg > strle_n ? strle_n : start + seg + seg;
			int k = start;
			while (start1 < end1 && start2 < end2)
				b[k++] = arr[start1] < arr[start2] ? arr[start2++] : arr[start1++];
			while (start1 < end1)
				b[k++] = arr[start1 ++];
			while (start2 < end2)
				b[k++] = arr[start2++];
		}
		int *temp = arr;
		arr = b;
		b = temp;
	}
	if(arr!=character){
		for(int i = 0 ; i < strle_n ; i ++){
			character[i] = arr[i];
		}
	}
}
void xz_paixu(int *character,int strle_n)
{
	int max,k;
	int i,j;
	for(i=0 , j ; i < strle_n - 1 ; i ++ ){
		max = i;
		for(j = i + 1 ; j < strle_n ;  j++ ){
			if(character[max] < character[j]){
				max = j;
			}
		}
		k = character[max];
		character[max] = character[i];
		character[i] = k;
	}
}
void hebing(int *nums,int len) //递归的合并排序
{
    int *temp = NEW(int,len);
    int this = 0;
    int lLen = len/2, rLen = len;
    int i = 0,j = len/2;
    if(len <= 1)return ;
    hebing(nums,lLen);
    hebing(nums + len/2,len - lLen);
    while(i < lLen && j < rLen)
    {
        if(nums[i] < nums[j])
        {
            temp[this] = nums[i];
            i += 1;
            this += 1;
        }
        else
        {
            temp[this] = nums[j];
            j += 1;
            this += 1;
        }
    }
    while(i < lLen)
    {
        temp[this] = nums[i];
        this += 1;
        i += 1;
    }
    while(j < rLen)
    {
        temp[this] = nums[j];
        this += 1;
        j += 1;
    }
    for(int i = 0 ; i < len ; i ++)
    {
        nums[i] = temp[i];
    }
}
