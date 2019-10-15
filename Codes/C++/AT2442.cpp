#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
#define calc(x) (x > 0 ? -(x * s) : -(x * t))
#define solve(x, y, o) (o ? (x -= calc(y), y -= z, x += calc(y)) : (x -= calc(y), y += z, x += calc(y)))
ll a[maxn];
signed main()
{
    ll n, q, s, t;
    scanf("%lld%lld%lld%lld", &n, &q, &s, &t);
    ll pre, ans = 0;
    scanf("%lld", &pre);
    for (ll i = 1, x; i <= n; i++)
    {
        scanf("%lld", &x);
        a[i] = x - pre;
        pre = x;
        ans += calc(a[i]);
    }
    for (ll i = 1, x, y, z; i <= q; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        solve(ans, a[x], 0);
        if (y != n)
            solve(ans, a[y + 1], 1);
        printf("%lld\n", ans);
    }
    return 0;
}