#include <bits/stdc++.h>
const int maxn = 1e2+5;
typedef long long ll;
using namespace std;
ll n,ans;
ll a[maxn], p[maxn];
void solve(ll x)
{
    for(ll i = 62; i >= 0; i--)
    {
        if(!(x >> i))
            continue;
        if(!p[i])
        {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}
signed main()
{
	scanf("%lld",&n);
    for(ll i = 1; i <= n; i++)
    {
    	scanf("%lld",&a[i]);
    	solve(a[i]);
	}
    for(ll i = 62; i >= 0; i--)
        if((ans ^ p[i]) > ans)
            ans ^= p[i];
    printf("%lld\n",ans);
    return 0;
}
