int c_pipei(char *size,char *alpha) //字符串匹配 从左边的参数查找右边的参数，返回从右边数alpha位于size的字符个数
{
	int num,num_tw;
	
	for(num = 0;size[num];num++){
		
		for( num_tw = 0 ; (alpha[num_tw]) && (size [ num + num_tw ] == alpha [num_tw]) ; num_tw++ )
		{
			
			if( ( ! size[num+num_tw+1]) && ( alpha[num_tw+1]) )return -1;
			
			else if( !alpha [num_tw + 1] )
			{
				return num + 1 ;
			}
		}
	}
	return -1;
}
