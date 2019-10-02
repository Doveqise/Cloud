#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxh = 2e1 + 5;
int n, k;
int hd[maxn << 1], to[maxn << 1], nxt[maxn << 1], tot, f[maxn][maxh], dep[maxn];
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void dfs1(int u)
{
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!dep[v])
        {
            dep[v] = dep[u] + 1;
            dfs1(v);
            for (int j = 1; j <= k; j++)
                f[u][j] += f[v][j - 1];
        }
    }
}
void dfs2(int u)
{
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (dep[v] > dep[u])
        {
            for (int j = k; j >= 2; j--)
                f[v][j] -= f[v][j - 2];
            for (int j = 1; j <= k; j++)
                f[v][j] += f[u][j - 1];
            dfs2(v);
        }
    }
}
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i][0]);
    dep[1] = 1;
    dfs1(1), dfs2(1);
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 0; j <= k; j++)
            ans += f[i][j];
        printf("%d\n", ans);
    }
}