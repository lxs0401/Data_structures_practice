void s(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
void max( int *arr , int i , int len )
{
	int dad = i , son = i * 2 + 1;
	
	while ( son < len )
	{
		if( (son + 1 < len) && (arr [son] < arr [son+1]) )
		{
			son++;
		}
		if(arr[dad] > arr[son])
		{
			return;
		} else {
			s( &arr[dad] , &arr[son] );
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void min(int *arr,int len)
{
	for( int i = len / 2 - 1 ;i >= 0 ; i -- )
	{
		max(arr,i,len);
	}
	
	for(int i = len - 1 ; i > 0 ; i -- )
	{
		s( &arr[0] , &arr[i] );
		max(arr,0,i);
	}
}
