#include <stdio.h>
#include <stdlib.h>

#define SHFIT 5
#define MASK 0x1f
#define N 10000000

int a[1 + N/32];
void set(int i)
{
    a[i >> SHFIT] |= (1 << (i & MASK));
}
void clr(int i)
{
    a[i >> SHFIT] &= ~(i << (i & MASK));
}
int test(int i)
{
    return a[i >> SHFIT] & (i << (i & MASK));
}
int main ()
{
    int i;
    for (i = 0 ; i < N; i ++){
        clr(i);
    }
    while(scanf("%d",&i) != EOF){
        set(i);
    }
    for (i = 0 ; i < N ; i ++){
        if(test(i)){
            printf("%d ",i);
        }
    }

}