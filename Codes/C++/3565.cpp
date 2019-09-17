#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 5;
ll hd[maxn], to[maxn << 1], nxt[maxn << 1], d[maxn], tmp[maxn], s1[maxn], s2[maxn];
ll n, ans, cnt, maxx;
void add(ll x, ll y)
{
    to[++cnt] = y;
    nxt[cnt] = hd[x];
    hd[x] = cnt;
}
void dfs(ll u, ll fa)
{
    maxx = max(maxx, d[u]);
    tmp[d[u]]++;
    for (ll i = hd[u]; i; i = nxt[i])
    {
        ll y = to[i]; 
        if (y == fa)
            continue;
        d[y] = d[u] + 1;
        dfs(y, u);
    }
}
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1, x, y; i < n; i++)
    {
        scanf("%lld%lld", &x, &y);
        add(x, y);
        add(y, x);
    }
    for (ll x = 1; x <= n; x++)
    {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        for (ll i = hd[x]; i; i = nxt[i])
        {
            ll y = to[i];
            maxx = 0;
            d[y] = 1;
            dfs(y, x);
            for (ll j = 1; j <= maxx; j++)
            {
                ans += s2[j] * tmp[j];
                s2[j] += s1[j] * tmp[j];
                s1[j] += tmp[j];
            }
            for (ll j = 1; j <= maxx; j++)
                tmp[j] = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}