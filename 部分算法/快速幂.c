ll f(ll a,ll b,ll n){
  int t,y;
  t=1; y=a;
  while (b!=0){
    if (b&1==1) t=t*y%n;
    y=y*y%n; b=b>>1;
  }
  return t;
}