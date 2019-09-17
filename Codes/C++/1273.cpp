#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e3 + 5;
int hd[maxn], to[maxn], nxt[maxn], val[maxn], f[maxn][maxn];
int tot, n, m;
void add(int u, int v, int w)
{
    nxt[++tot] = hd[u];
    hd[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
int dfs(int u, int fa)
{
    if (u > n - m)
        return 1;
    int res = 0, maxx;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa)
            res += (maxx = dfs(v, u));
        for (int j = res; j >= 0; j--)
            for (int p = 0; p <= min(maxx, j); p++)
                f[u][j] = max(f[u][j], f[u][j - p] + f[v][p] - val[i]);
    }
    return res;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int u = 1, lim; u <= n - m; u++)
    {
        scanf("%d", &lim);
        for (int p = 1, v, w; p <= lim; p++)
        {
            scanf("%d%d", &v, &w);
            add(u, v, w);
        }
    }
    for (int u = 1; u <= n; u++)
        for (int v = 0; v <= n; v++)
            f[u][v] = v ? -0x3f3f3f3f : 0;
    for (int u = n - m + 1; u <= n; u++)
        scanf("%d", &f[u][1]);
    dfs(1, 1);
    for (int j = n; j >= 0; j--)
        if (f[1][j] >= 0)
        {
            printf("%d\n", j);
            return 0;
        }
}