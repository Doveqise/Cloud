#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;
ll n,ans=0;
vector<int>e;
vector<ll>p;
int quick_pow(int a,int k)
{
    int ans=1;
    for(;k;k>>=1,a=a*a%mod)
        if(k&1)
            ans=ans*a%mod;
    return ans;
}
void dfs(int cnt,ll g,ll m1,ll m2)
{
    if(cnt==p.size())
    {
        if(g==1)
            return;
        ans+=quick_pow(2,n/g)*(g/m2%mod*m1%mod)%mod;
        ans%=mod;
        return;
    }
    dfs(cnt+1,g,m1,m2);
    m1=m1*(p[cnt]-1)%mod;
    m2*=p[cnt];
    for(int i=1;i<=e[cnt];++i)
    {
        g*=p[cnt];
        dfs(cnt+1,g,m1,m2);
    }
}
signed main()
{
    scanf("%lld",&n);
    ll x=n;
    for(int i=2;i*i<=n;i++)
    {
        if(x%i)
            continue;
            p.push_back(i);
        int tot=0;
        while(!x%i)
        {
            x/=i;
            tot++;
        }
        e.push_back(tot);
    }
    if(x>1)
    {
        p.push_back(x);
        e.push_back(1);
    }
    dfs(0,1,1,1);
    ans=(ans-n+2)%mod;
    if(ans<0)
        ans+=mod;
    printf("%lld\n",ans);
    return 0;
}
