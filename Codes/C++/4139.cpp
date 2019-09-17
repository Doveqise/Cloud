#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e7+5;
signed phi[maxn],prime[maxn];
int t,p,tot;
void init()
{
    phi[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        if (!phi[i])
        {
            prime[++tot] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxn)
                break;
            if (!(i % prime[j]))
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
int quick_pow(int x,int b,int mod)
{
    int ret=1;
    for(;b;x=x*x%mod,b>>=1)
        if(b&1)
            ret=ret*x%mod;
    return ret;
}
int solve(int x)
{
    return x==1?0:quick_pow(2,solve(phi[x])+phi[x],x);
}
signed main()
{
    init();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&p);
        printf("%lld\n",solve(p));
    }
}