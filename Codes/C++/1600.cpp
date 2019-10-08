#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define mid ((l + r) >> 1)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int n, m;
int hd[maxn], nxt[maxn], to[maxn], w[maxn], wt[maxn], tot;
int ton[maxn], bst[maxn], ans[maxn], dis[maxn], sta[maxn], s[maxn], t[maxn];
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
vector<int> path[maxn], pre[maxn];
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
void dfs1(int u)
{
    siz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int topf)
{
    top[u] = topf;
    if (son[u])
        dfs2(son[u], topf);
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
int lca(int u, int v)
{
    if (u == v)
        return u;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    return u;
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
void query(int u)
{
    int pre1 = ton[dep[u] + w[u]], pre2 = bst[w[u] - dep[u] + n];
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        query(v);
    }
    ton[dep[u]] += sta[u];
    for (int i = 0; i < path[u].size(); i++)
        bst[dis[path[u][i]]]++;
    for (int i = 0; i < pre[u].size(); i++)
        ton[dep[s[pre[u][i]]]]--;
    ans[u] += ton[dep[u] + w[u]] - pre1 + bst[w[u] - dep[u] + n] - pre2;
    for (int i = 0; i < pre[u].size(); i++)
        bst[dis[pre[u][i]]]--;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &s[i], &t[i]);
        int la = lca(s[i], t[i]);
        dis[i] = dep[s[i]] + n - 2 * dep[la];
        sta[s[i]]++;
        path[t[i]].push_back(i);
        pre[la].push_back(i);
    }
    query(1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}