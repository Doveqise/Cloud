#include<bits/stdc++.h>
using namespace std;
const long double e=2.71828182845904523536;
inline long double calc(int f,int x){return x*log((long double)f/x);}
signed main(){
    int n;scanf("%d",&n);int ans1;int ans=0;
    for(int i=5;i<=n;i++){ans1=floor(i/e);
    if(calc(i,ans1)<calc(i,ans1+1))++ans1;
    ans1/=__gcd(ans1,i);
    while(!(ans1%2))ans1/=2;while(!(ans1%5))ans1/=5;
    if(ans1!=1)ans+=i;else ans-=i;}
    printf("%d\n",ans);
    return 0;
}