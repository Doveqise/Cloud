#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int ea[maxn], mini[maxn], val[maxn], hd[maxn], to[maxn], nxt[maxn], tot;
void add(int u, int v)
{
    nxt[++tot] = hd[u];
    hd[u] = tot;
    to[tot] = v;
}
void dfs(int u, int fa, int minu)
{
    int py = 1;
    minu = min(val[u], minu);
    if (mini[u] > minu)
    {
        mini[u] = minu;
        py = 0;
    }
    int maxx = max(ea[fa], val[u] - minu);
    if (ea[u] < maxx)
    {
        ea[u] = maxx;
        py = 0;
    }
    if (py)
        return;
    for (int i = hd[u]; i; i = nxt[i])
        dfs(to[i], u, minu);
}
signed main()
{
    memset(mini, 0x3f, sizeof(mini));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v);
        if (w == 2)
            add(v, u);
    }
    dfs(1, 0, 0x3f3f3f3f);
    printf("%d\n", ea[n]);
    return 0;
}