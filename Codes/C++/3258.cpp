#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;
int a[maxn], val[maxn], cf[maxn], fa[maxn], dep[maxn], siz[maxn], son[maxn], id[maxn], rl[maxn], hd[maxn], nxt[maxn << 1], to[maxn << 1], top[maxn];
int n, tot = 1, cnt = 0;
void add(int u, int v)
{
    to[++tot] = v;
    nxt[tot] = hd[u];
    hd[u] = tot;
}
void dfs1(int x, int fat, int dpt)
{
    dep[x] = dpt;
    siz[x] = 1;
    for (int i = hd[x]; i; i = nxt[i])
    {
        if (to[i] == fat)
            continue;
        dfs1(to[i], x, dpt + 1);
        fa[to[i]] = x;
        siz[x] += siz[to[i]];
        if (siz[to[i]] > siz[son[x]])
            son[x] = to[i];
    }
}
void dfs2(int x, int ltp)
{
    id[x] = ++cnt;
    rl[cnt] = x;
    top[x] = ltp;
    if (son[x])
        dfs2(son[x], ltp);
    for (int i = hd[x]; i; i = nxt[i])
    {
        if (to[i] == fa[x] || to[i] == son[x])
            continue;
        dfs2(to[i], to[i]);
    }
}
int lca(int x, int y)
{
    while (top[x] != top[y])
        if (dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    if (dep[x] > dep[y])
        return y;
    else
        return x;
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    val[a[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        int t = lca(a[i - 1], a[i]);
        cf[a[i - 1]]++;
        cf[a[i]]++;
        cf[fa[t]] -= 2;
        val[t]--;
    }
    for (int i = n; i > 0; i--)
    {
        val[rl[i]] += cf[rl[i]];
        cf[fa[rl[i]]] += cf[rl[i]];
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", val[i] - 1);
    return 0;
}