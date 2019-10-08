#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
#define mid ((l + r) >> 1)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
int n;
int hd[maxn], nxt[maxn], to[maxn], val[maxn], w[maxn], wt[maxn], tot;
int a[maxn << 2], laz[maxn << 2], tag[maxn << 2];
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
void pushdown(int u)
{
    if (tag[u] >= 0)
    {
        laz[ls(u)] = laz[rs(u)] = 0;
        a[ls(u)] = a[rs(u)] = tag[ls(u)] = tag[rs(u)] = tag[u];
        tag[u] = -1;
    }
    if (laz[u])
    {
        laz[ls(u)] += laz[u];
        laz[rs(u)] += laz[u];
        a[ls(u)] += laz[u];
        a[rs(u)] += laz[u];
        laz[u] = 0;
    }
}
void pushup(int u)
{
    a[u] = max(a[ls(u)], a[rs(u)]);
}
void build(int u, int l, int r)
{
    tag[u] = -1;
    if (l == r)
    {
        a[u] = wt[l];
        return;
    }
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    pushup(u);
}
void add(int u, int l, int r, int x, int y, int v)
{
    if (x > r || y < l)
        return;
    if (x <= l && y >= r)
    {
        laz[u] += v;
        a[u] += v;
        return;
    }
    pushdown(u);
    if (x <= mid)
        add(ls(u), l, mid, x, y, v);
    if (y > mid)
        add(rs(u), mid + 1, r, x, y, v);
    pushup(u);
}
void cover(int u, int l, int r, int x, int y, int v)
{
    if (x > r || y < l)
        return;
    if (x <= l && y >= r)
    {
        a[u] = tag[u] = v;
        laz[u] = 0;
        return;
    }
    pushdown(u);
    cover(ls(u), l, mid, x, y, v);
    cover(rs(u), mid + 1, r, x, y, v);
    pushup(u);
}
int query(int u, int l, int r, int x, int y)
{
    int res = 0;
    if (x <= l && y >= r)
        return a[u];
    pushdown(u);
    if (x <= mid)
        res = max(res, query(ls(u), l, mid, x, y));
    if (y > mid)
        res = max(res, query(rs(u), mid + 1, r, x, y));
    return res;
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
        // printf("#### %d %d\n", u, v);
        fa[v] = u;
        w[v] = val[i];
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
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
void upadd(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        add(1, 1, n, id[top[u]], id[u], w);
        u = fa[top[u]];
    }
    if (id[u] > id[v])
        swap(u, v);
    // if (id[u] + 1 > id[v])
    //     add(1, 1, n, id[v], id[u] + 1, w);
    // else
    add(1, 1, n, id[u] + 1, id[v], w);
}
void upcover(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        cover(1, 1, n, id[top[u]], id[u], w);
        u = fa[top[u]];
    }
    if (id[u] > id[v])
        swap(u, v);
    // if (id[u] + 1 > id[v])
    //     cover(1, 1, n, id[v], id[u] + 1, w);
    // else
    cover(1, 1, n, id[u] + 1, id[v], w);
}
int queryrange(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res = max(res, query(1, 1, n, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if (id[u] > id[v])
        swap(u, v);
    // if (id[u] + 1 > id[v])
    //     return res = max(res, query(1, 1, n, id[v], id[u] + 1));
    // else
    return res = max(res, query(1, 1, n, id[u] + 1, id[v]));
}
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
signed main()
{
    scanf("%d", &n);
    for (int i = 1, a, b, c; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);
    while (1)
    {
        static char opt[10];
        int x, y, z;
        scanf("%s", opt);
        if (opt[0] == 'S')
            break;
        switch (opt[1])
        {
        case 'h':
            scanf("%d%d", &x, &y);
            x = dep[to[x * 2 - 1]] < dep[to[x << 1]] ? to[x << 1] : to[x * 2 - 1];
            cover(1, 1, n, id[x], id[x], y);
            break;
        case 'o':
            scanf("%d%d%d", &x, &y, &z);
            upcover(x, y, z);
            break;
        case 'd':
            scanf("%d%d%d", &x, &y, &z);
            upadd(x, y, z);
            break;
        default:
            scanf("%d%d", &x, &y);
            printf("%d\n", queryrange(x, y));
            break;
        }
    }
}