#include<iostream>  
using namespace std;  
#define  V 1500  
unsigned int f[V];//ȫ�ֱ������Զ���ʼ��Ϊ0  
unsigned int weight[10];  
unsigned int value[10];  
#define  max(x,y)   (x)>(y)?(x):(y)  
int main()  
{  
      
    int N,M;  
    cin>>N;//��Ʒ����  
    cin>>M;//��������  
    for (int i=1;i<=N; i++)  
    {  
        cin>>weight[i]>>value[i];  
    }  
    for (int i=1; i<=N; i++)  
        for (int j = weight[i]; j<=M; j++)  
        {  
            f[j]=max(f[j],f[j-weight[i]]+value[i]);  
        }  
      
    cout<<f[M]<<endl;//������Ž�  
  
}  
