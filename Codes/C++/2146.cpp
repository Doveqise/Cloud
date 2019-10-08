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
void pushup(int u)
{
    a[u] = a[ls(u)] + a[rs(u)];
}
void pushdown(int u, int llen, int rlen)
{
    if (laz[u] != -1)
    {
        laz[ls(u)] = laz[u];
        laz[rs(u)] = laz[u];
        a[ls(u)] = laz[u] * llen;
        a[rs(u)] = laz[u] * rlen;
        laz[u] = -1;
    }
}
void update(int u, int l, int r, int x, int y, int v)
{
    if (x > r || y < l)
        return;
    if (x <= l && y >= r)
    {
        laz[u] = v;
        a[u] = v * (r - l + 1);
        return;
    }
    pushdown(u, mid - l + 1, r - mid);
    update(ls(u), l, mid, x, y, v);
    update(rs(u), mid + 1, r, x, y, v);
    pushup(u);
}
void change(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        update(1, 1, cnt, id[top[u]], id[u], w);
        u = fa[top[u]];
    }
    if (id[u] > id[v])
        swap(u, v);
    update(1, 1, cnt, id[u], id[v], w);
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
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int topf)
{
    id[u] = ++cnt;
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
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////////////////////////////////////*/
signed main()
{
    memset(laz, -1, sizeof(laz));
    scanf("%d", &n);
    fa[1] = 1;
    for (int i = 2, b; i <= n; i++)
    {
        scanf("%d", &b);
        fa[i] = b + 1;
        add(b + 1, i);
        add(i, b + 1);
    }
    scanf("%d", &m);
    dfs1(1);
    dfs2(1, 1);
    while (m--)
    {
        static char opt[10];
        int u;
        scanf("%s", opt);
        int now1 = a[1];
        switch (opt[0])
        {
        case 'i':
            scanf("%d", &u);
            u++;
            change(1, u, 1);
            printf("%d\n", abs(now1 - a[1]));
            break;
        default:
            scanf("%d", &u);
            u++;
            update(1, 1, n, id[u], id[u] + siz[u] - 1, 0);
            printf("%d\n", abs(now1 - a[1]));
            break;
        }
    }
}