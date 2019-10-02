#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x;
    scanf("%lld", &x);
    return x;
}
ll qpow(ll x, ll b, ll p)
{
    ll ret = 1, base = x;
    if (!b)
        return x % p;
    while (b)
    {
        if (b & 1)
            ret = ret * base % p;
        base = base * base % p;
        b >>= 1;
    }
    return ret;
}
signed main()
{
    ll n = read(), b = read(), p = read(), ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, read());
    printf("%lld\n", qpow((2 * ans) + 233, b, p));
    return 0;
}