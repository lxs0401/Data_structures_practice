void y_dong(char *a,int k,int i) //移动数组中的数据K位
{
	char temp;
	temp = a[i] ;
	if( a[i] ) y_dong(a , k + 1 , i + 1 );
	a[k] = temp;
	a[i] = '\0';
}
