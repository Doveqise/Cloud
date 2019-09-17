#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int hd[maxn], to[maxn], nxt[maxn], val[maxn], f[maxn];
int tot, n, ans = 0;
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void dfs(int u, int fa)
{
    f[u] = val[u];
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa)
        {
            dfs(v, u);
            f[u] += max(0, f[v]);
        }
    }
    ans = max(ans, f[u]);
}
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}