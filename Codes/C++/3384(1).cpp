#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define mid ((l + r) >> 1)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int n, m, r, mod;
int hd[maxn], nxt[maxn], to[maxn], w[maxn], wt[maxn], tot;
int a[maxn << 2], laz[maxn << 2];
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
void pushdown(int u, int llen, int rlen)
{
    laz[ls(u)] += laz[u];
    laz[rs(u)] += laz[u];
    a[ls(u)] += laz[u] * llen % mod;
    a[rs(u)] += laz[u] * rlen % mod;
    a[ls(u)] %= mod;
    a[rs(u)] %= mod;
    laz[u] = 0;
}
void pushup(int u, int l, int r, int x, int y, int v)
{
    if (x <= l && y >= r)
    {
        laz[u] += v;
        a[u] = (a[u] + v * (r - l + 1)) % mod;
    }
    else
    {
        if (laz[u])
            pushdown(u, mid - l + 1, r - mid);
        if (x <= mid)
            pushup(ls(u), l, mid, x, y, v);
        if (y > mid)
            pushup(rs(u), mid + 1, r, x, y, v);
        a[u] = (a[ls(u)] + a[rs(u)]) % mod;
    }
}
void build(int u, int l, int r)
{
    if (l == r)
    {
        a[u] = (wt[l] + mod) % mod;
        return;
    }
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    a[u] = (a[ls(u)] + a[rs(u)]) % mod;
}
int query(int u, int l, int r, int x, int y)
{
    int res = 0;
    if (x <= l && y >= r)
        return a[u] % mod;
    else
    {
        if (laz[u])
            pushdown(u, mid - l + 1, r - mid);
        if (x <= mid)
            res = (res + query(ls(u), l, mid, x, y)) % mod;
        if (y > mid)
            res = (res + query(rs(u), mid + 1, r, x, y)) % mod;
        return res;
    }
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
void dfs1(int u)
{
    siz[u] = 1;
    int maxson = -1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > maxson)
        {
            son[u] = v;
            maxson = siz[v];
        }
    }
}
void dfs2(int u, int topf)
{
    id[u] = ++cnt;
    wt[cnt] = w[u];
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
void upson(int u, int w)
{
    pushup(1, 1, n, id[u], id[u] + siz[u] - 1, w);
}
void uprange(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        pushup(1, 1, n, id[top[u]], id[u], w);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    pushup(1, 1, n, id[u], id[v], w);
}
int queryson(int u)
{
    return query(1, 1, n, id[u], id[u] + siz[u] - 1);
}
int queryrange(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res = (res + query(1, 1, n, id[top[u]], id[u])) % mod;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    return res = (res + query(1, 1, n, id[u], id[v])) % mod;
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
signed main()
{
    scanf("%d%d%d%d", &n, &m, &r, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1, a, b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs1(r);
    dfs2(r, r);
    build(1, 1, n);
    while (m--)
    {
        int opt, x, y, z;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            scanf("%d%d%d", &x, &y, &z);
            uprange(x, y, z);
            break;
        case 2:
            scanf("%d%d", &x, &y);
            printf("%d\n", queryrange(x, y));
            break;
        case 3:
            scanf("%d%d", &x, &y);
            upson(x, y);
            break;
        default:
            scanf("%d", &x);
            printf("%d\n", queryson(x));
            break;
        }
    }
}