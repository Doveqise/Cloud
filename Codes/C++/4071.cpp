#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
ll f[maxn] = {1}, d[maxn] = {0, 0, 1};
ll qpow(ll a, ll b)
{
    ll ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    for (int i = 1; i <= maxn; i++)
    {
        f[i] = f[i - 1] * i % mod;
        if (i >= 3)
            d[i] = (i - 1) * (d[i - 2] + d[i - 1]) % mod;
    }
}
signed main()
{
    init();
    int T, n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (n - m == 1)
            puts("0");
        else if (!(n - m))
            puts("1");
        else if (!m)
            printf("%lld\n", d[n]);
        else
            printf("%lld\n", 1LL * f[n] * qpow(f[n - m], mod - 2) % mod * qpow(f[m], mod - 2) % mod * d[n - m] % mod);
    }
    return 0;
}