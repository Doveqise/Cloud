#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 19260817;
typedef long long ll;
ll d[maxn], a[maxn], dcaq[maxn], aq[maxn];
ll solve(int x, int l, int r, bool flg)
{
    if (l > r)
        return 0;
    ll lft = (((aq[r] - aq[l - 1]) % mod + mod) % mod) * d[x] % mod;
    ll rht = ((dcaq[r] - dcaq[l - 1]) % mod + mod) % mod;
    return flg ? ((lft - rht) % mod + mod) % mod : ((rht - lft) % mod + mod) % mod;
}
signed main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll now = 0;
    for (ll i = 2, t; i <= n; i++)
    {
        scanf("%lld", &t);
        now += t;
        d[i] = (now %= mod);
    }
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] %= mod;
        aq[i] = (aq[i - 1] + a[i]) % mod;
        dcaq[i] = (dcaq[i - 1] + (a[i] * d[i]) % mod) % mod;
    }
    for (ll i = 1, x, l, r; i <= m; i++)
    {
        scanf("%lld%lld%lld", &x, &l, &r);
        printf("%lld\n", (solve(x, l, min(r, x - 1), 1) + solve(x, max(l, x + 1), r, 0)) % mod);
    }
}