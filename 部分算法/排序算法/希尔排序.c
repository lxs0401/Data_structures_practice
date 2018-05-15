#include <stdio.h>
void ShellSort(int a[],int dk,int length){/*ϣ��������*/
    int i,j,k;
    for(i = dk + 1;i <= length;i ++){
        if(a[i] < a[i - dk]){/*��a[i]�������������ӱ�*/
            k = a[i];
        for(j= i - dk ;j > 0 && k < a[j] ;j = j - dk)
            a[j + dk] = a[j];
        a[j + dk]=k;//���룻
        }
    }
}
int main(){
    int n,i,k;
    while(scanf("%d",&n)!=EOF){
        int a[10010],b[10010];
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        ShellSort(a,n/2,n);
        for(i=1;i<=n;i++){
            if(i==1)
                printf("%d",a[i]);
            else
                printf(" %d",a[i]);
        }
        printf("\n");
        ShellSort(b,1,n);
        for(i=1;i<=n;i++){
            if(i==1)
                printf("%d",b[i]);
            else
                printf(" %d",b[i]);
        }
        printf("\n");
    }
    return 0;
}