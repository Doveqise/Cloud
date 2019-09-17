#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int hd[maxn], to[maxn], nxt[maxn], val[maxn], f[maxn][maxn], sons[maxn];
int tot, n, rt, ans = 123456789, u, p;
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void dfs(int u, int fa)
{
    f[u][1] = sons[u];
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dfs(v, u);
        for (int j = p; j >= 1; j--)
            for (int k = 1; k <= j; k++)
                f[u][j] = min(f[u][j], f[u][j - k] + f[v][k] - 2);
    }
    ans = min(ans, f[u][p]);
}
signed main()
{
    memset(f, 0x3f, sizeof(f));
    scanf("%d%d", &n, &p);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        sons[u]++, sons[v]++;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}