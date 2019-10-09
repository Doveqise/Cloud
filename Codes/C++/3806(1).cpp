#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e2 + 5;
int n, m,rt, query[maxm];
int hd[maxn], to[maxn<<1], nxt[maxn<<1], val[maxn<<1], tot;
int sonv[maxn], siz[maxn], fa[maxn],cnt, dep[maxn], top[maxn], id[maxn], vis[maxn], jud[maxn];
void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
bool cmp(int u, int v)
{
    return dep[u] < dep[v];
}
void dfs1(int u, int res)
{
    siz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u] || vis[v])
            continue;
        fa[v] = u;
        dfs1(v, res);
        siz[u] += siz[v];
        sonv[u] = max(sonv[u], siz[v]);
    }
    sonv[u] = max(sonv[u], res - siz[u]);
    if (!rt || sonv[u] < sonv[rt])
        rt = u;
}
void dfs2(int u, int dis, int topf)
{
    id[++cnt] = u;
    dep[u] = dis;
    top[u] = topf;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u] || vis[v])
            continue;
        fa[v] = u;
        dfs2(v, dis + val[i], topf);
    }
}
void calc(int u)
{
    cnt = dep[u] = 0;
    top[u] = id[++cnt] = u;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v])
            continue;
        fa[v] = u;
        dfs2(v, val[i], v);
    }
    sort(id + 1, id + 1 + cnt, cmp);
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = cnt;
        if (jud[i])
            continue;
        while (l < r)
        {
            if (dep[id[l]] + dep[id[r]] > query[i])
                r--;
            else if (dep[id[l]] + dep[id[r]] < query[i])
                l++;
            else if (top[id[l]] == top[id[r]])
            {
                if (dep[id[r]] == dep[id[r - 1]])
                    r--;
                else
                    l++;
            }
            else
            {
                jud[i] = 1;
                break;
            }
        }
    }
}
void solve(int u)
{
    vis[u] = 1;
    calc(u);
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v])
            continue;
        rt = 0;
        fa[v] = u;
        dfs1(v, siz[v]);
        solve(v);
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b, c; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &query[i]);
    sonv[0] = n;
    dfs1(1, n);
    solve(rt);
    for (int i = 1; i <= m; i++)
        puts(jud[i] ? "AYE" : "NAY");
    return 0;
}