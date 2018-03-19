#include <stdio.h>
typedef long long ll;
ll f(ll a,ll b,ll n){
  int t,y;
  t=1; y=a;
  while (b!=0){
    if (b&1==1) t=t*y%n;
    y=y*y%n; b=b>>1;
  }
  return t;
}
ll pow_mod(ll a,ll b)
{
  return (b % 2 == 1 ? a : 1) * (b / 2 == 0 ? 1 : pow_mod(a*a,b / 2));
}
int main ()
{
  printf("%d",pow_mod(2,3));
}