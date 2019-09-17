#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int tot, n, m;
int hd[maxn], siz[maxn], f[maxn][maxn];
struct edge
{
    int nxt, to, wei;
} e[maxn << 1];
void add(int x, int y, int z)
{
    e[tot].wei = z;
    e[tot].to = y;
    e[tot].nxt = hd[x];
    hd[x] = tot++;
}
void dfs(int u, int fa)
{
    for (int i = hd[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        siz[u] += siz[v] + 1;
        for (int j = min(siz[u], m); j; j--)
            for (int k = min(j - 1, siz[v]); k >= 0; k--)
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + e[i].wei);
    }
}
signed main()
{
    memset(hd, -1, sizeof(hd));
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b, c; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    printf("%d", f[1][m]);
    return 0;
}