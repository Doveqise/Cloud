#include<bits/stdc++.h>
#define ll long long
int main(){
	ll ans,n,k;scanf("%lld %lld",&n,&k);ans=n*k;
    for(ll l=1,r,t;l<=n;l=r+1){
        t=k/l;if(!t)r=n;
        else r=std::min(k/t,n);
        ans-=(t*(r-l+1)*(l+r)>>1);}
    printf("%lld\n",ans);
    return 0;
}