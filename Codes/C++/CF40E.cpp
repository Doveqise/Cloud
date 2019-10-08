#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
typedef long long ll;
ll T[maxn], N[maxn];
ll n, m, k, mod;
ll qpow(ll x, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * x) % mod;
        x = (x * x) % mod;
        b >>= 1;
    }
    return res % mod;
}
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    int swp = 0;
    if (n < m)
        swap(n, m), swp = 1;
    if ((n + m) % 2)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        N[i] = 1;
    for (int i = 1, x, y, z; i <= k; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (swp)
            swap(x, y);
        T[x]++;
        N[x] *= z;
    }
    scanf("%lld", &mod);
    ll det = 0;
    for (int i = 1; i <= n; i++)
    {
        if (T[i] == m && N[i] == 1)
        {
            puts("0");
            return 0;
        }
        det += min(T[i], m - 1);
    }
    printf("%lld\n", qpow(2, 1ll * (n - 1) * (m - 1) - det));
    return 0;
}