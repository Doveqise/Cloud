#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int inf = 1e9 + 7;
ll n, ans = inf;
ll m[maxn], x[maxn], y[maxn], jud[maxn];
ll out[maxn], l1 = inf, l2 = inf, r1 = -inf, r2 = -inf;
void solve(ll l1, ll r1, ll l2, ll r2)
{
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l1 <= x[i] && r1 >= x[i] && l2 <= y[i] && r2 >= y[i])
        {
            jud[i] = 0;
            continue;
        }
        if (l1 <= y[i] && r1 >= y[i] && l2 <= x[i] && r2 >= x[i])
        {
            jud[i] = 1;
            now += m[i];
        }
        else
            return;
    }
    if (now < ans)
    {
        ans = now;
        for (int i = 1; i <= n; i++)
            out[i] = jud[i];
    }
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &x[i], &y[i], &m[i]);
        if (x[i] <= y[i])
        {
            l1 = min(l1, x[i]);
            r1 = max(r1, x[i]);
            l2 = min(l2, y[i]);
            r2 = max(r2, y[i]);
        }
        else
        {
            l1 = min(l1, y[i]);
            r1 = max(r1, y[i]);
            l2 = min(l2, x[i]);
            r2 = max(r2, x[i]);
        }
    }
    printf("%lld ", 2 * (r1 + r2 - l1 - l2));
    solve(l1, r1, l2, r2);
    solve(l1, r2, l2, r1);
    solve(l2, r1, l1, r2);
    solve(l2, r2, l1, r1);
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%lld", out[i]);
    return 0;
}
