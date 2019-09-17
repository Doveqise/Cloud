#include<bits/stdc++.h>
const int mod = 1e5+3;
typedef long long ll;
using namespace std;
ll n,m;
ll quick_pow(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
}
    return res;
}
signed main()
{
    scanf("%lld%lld",&m,&n);
    printf("%lld",(quick_pow(m,n)-(m*quick_pow(m-1,n-1))%mod+mod)%mod);
    return 0;
 } 