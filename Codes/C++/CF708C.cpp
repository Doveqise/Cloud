#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int hd[maxn], nxt[maxn << 1], to[maxn << 1], cnt;
int n, siz[maxn], fa[maxn], son[maxn], up[maxn];
struct node
{
    int fis, sec;
    void insert(int x)
    {
        x > fis ? (sec = fis, fis = x) : (x > sec ? sec = x : x = x);
    }
    int fetch(int x)
    {
        return x == fis ? sec : fis;
    }
} down[maxn];
void add(int x, int y)
{
    nxt[++cnt] = hd[x];
    hd[x] = cnt;
    to[cnt] = y;
}
int cal(int u)
{
    return siz[u] <= (n >> 1) ? siz[u] : down[u].fis;
}
void dfs1(int u)
{
    siz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        down[u].insert(cal(v));
    }
}
void dfs2(int u)
{
    if (n <= (n >> 1) + siz[u])
        up[u] = n - siz[u];
    else
    {
        up[u] = max(up[fa[u]], down[fa[u]].fetch(cal(u)));
    }
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        dfs2(v);
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
    if (n > siz[son[u]] + siz[u])
        son[u] = fa[u];
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs1(1);
    dfs2(1);
    for (int u = 1, maxs, maxx; u <= n; u++)
    {
        int v = son[u];
        if (v == fa[u])
        {
            maxs = n - siz[u];
            maxx = up[u];
        }
        else
        {
            maxs = siz[v];
            maxx = down[v].fis;
        }
        printf("%d ", maxs - maxx <= (n >> 1));
    }
    return 0;
}