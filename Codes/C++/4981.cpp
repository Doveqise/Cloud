#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
ll qpow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", qpow(n, n - 1));
    }
    return 0;
}