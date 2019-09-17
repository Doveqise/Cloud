#include<bits/stdc++.h>
using namespace std;
const int maxn = 22680;
long long ans[maxn+5];
long long getans(long long x)
{
    return ans[maxn]*(x/maxn)+ans[x%maxn];
}
signed main()
{
    for(int i=1,t;i<=maxn;i++)
        if(maxn>=(t=i*((i-1)%9+1)))
            ans[t]=1;
    for(int i=2;i<=maxn;i++)
        ans[i]+=ans[i-1];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",getans(r)-getans(l-1));
    }
    return 0;
}