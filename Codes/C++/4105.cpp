#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+5;
ll n,sa,sb,sc,sd,mod;
ll a[maxn];
ll f(ll x)
{
    ll saa,sbb,scc,sdd;
    saa=sa%mod*x%mod*x%mod*x%mod;
    sbb=sb%mod*x%mod*x%mod;
    scc=sc%mod*x%mod;
    sdd=sd%mod;
    return saa+sbb+scc+sdd%mod;
}
signed main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&sa,&sb,&sc,&sd,&a[1],&mod);
    ll maxx=0,ans=0;
    for(int i=2;i<=n;i++)
    {
        a[i]=(f(a[i-1])+f(a[i-2]))%mod;
        maxx=max(maxx,a[i]);
        ans=max(ans,maxx-a[i]);
    }
    printf("%lld\n",(ans+1)>>1);
    return 0;
}