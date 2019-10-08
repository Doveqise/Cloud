#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 5;
const int maxm = 3e3 + 5;
const int inf = 1e9 + 7;
typedef long long ll;
ll f[2][maxn][maxn], dis[maxn][maxn], p[maxm];
ll ans;
signed main()
{
    ll T;
    scanf("%lld", &T);
    while (T--)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lld", &dis[i][j]);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &p[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[0][i][j] = f[1][i][j] = inf;
        ll pre = 0, now = 1;
        f[pre][1][2] = 0;
        p[0] = 3;
        for (int t = 1; t <= m; t++)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[now][i][j] = inf;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (f[pre][i][j] != inf && i != j && i != p[t - 1] && j != p[t - 1])
                    {
                        if (i != p[t] && j != p[t])
                            f[now][i][j] = min(f[now][i][j], f[pre][i][j] + dis[p[t - 1]][p[t]]);
                        if (j != p[t])
                            f[now][p[t - 1]][j] = min(f[now][p[t - 1]][j], f[pre][i][j] + dis[i][p[t]]);
                        if (i != p[t])
                            f[now][i][p[t - 1]] = min(f[now][i][p[t - 1]], f[pre][i][j] + dis[j][p[t]]);
                    }
            pre ^= 1, now ^= 1;
        }
        ans = inf;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans = min(ans, f[pre][i][j]);
        printf("%lld\n", ans);
    }
    return 0;
}