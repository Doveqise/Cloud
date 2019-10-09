#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, num = 0;
const int maxn = 1e5 + 5;
int w[maxn], afw[maxn], fa[maxn], id[maxn], son[maxn], top[maxn], dep[maxn], siz[maxn];
int hd[maxn];
int tot = 0;
struct node
{
    int l, r, lc, rc, sum, flg;
    node()
    {
        flg = 0;
    }
} tr[400010];
struct edge
{
    int to;
    int nxt;
} rd[200010];
void add(int frm, int to)
{
    rd[++num].nxt = hd[frm];
    rd[num].to = to;
    hd[frm] = num;
}
void build(int u, int l, int r)
{
    tr[u].l = l,tr[u].r = r;
    if (l == r)
    {
        tr[u].sum = 1;
        tr[u].lc = afw[l];
        tr[u].rc = afw[l];
        return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
    tr[u].lc = tr[u * 2].lc,tr[u].rc = tr[u * 2 + 1].rc;
    if (tr[u * 2].rc == tr[u * 2 + 1].lc)
        tr[u].sum--;
}
void change(int u, int x, int y, int w)
{
    int l = tr[u].l;
    int r = tr[u].r;
    if (l == x && r == y)
    {
        tr[u].flg = tr[u].lc = tr[u].rc = w;
        tr[u].sum = 1;
        return;
    }
    int mid = (l + r) / 2;
    int ls = u * 2;
    int rs = u * 2 + 1;
    if (tr[u].flg != 0)
    {
        change(ls, l, mid, tr[u].flg);
        change(rs, mid + 1, r, tr[u].flg);
        tr[u].flg = 0;
    }
    if (y <= mid)
        change(ls, x, y, w);
    else if (x > mid)
        change(rs, x, y, w);
    else
    {
        change(ls, x, mid, w);
        change(rs, mid + 1, y, w);
    }
    tr[u].sum = tr[ls].sum + tr[rs].sum;
    tr[u].lc = tr[ls].lc,tr[u].rc = tr[rs].rc;
    if (tr[ls].rc == tr[rs].lc)
        tr[u].sum--;
}
int query(int u, int x, int y)
{
    int l = tr[u].l,r = tr[u].r;
    if (l == x && r == y)
        return tr[u].sum;
    int mid = (l + r) / 2;
    int ls = u * 2,rs = u * 2 + 1;
    if (tr[u].flg != 0)
    {
        change(ls, l, mid, tr[u].flg);
        change(rs, mid + 1, r, tr[u].flg);
        tr[u].flg = 0;
    }
    if (y <= mid)
        return query(ls, x, y);
    else if (x > mid)
        return query(rs, x, y);
    else
    {
        int res = query(ls, x, mid) + query(rs, mid + 1, y);
        if (tr[ls].rc == tr[rs].lc)
            res--;
        return res;
    }
}
int check(int u, int x)
{
    int l = tr[u].l,r = tr[u].r;
    if (l == r && l == x)
        return tr[u].lc;
    int mid = (l + r) / 2;
    int ls = u * 2,rs = u * 2 + 1;
    if (tr[u].flg != 0)
    {
        change(ls, l, mid, tr[u].flg);
        change(rs, mid + 1, r, tr[u].flg);
        tr[u].flg = 0;
    }
    if (x <= mid)
        return check(ls, x);
    else
        return check(rs, x);
}
void dfs1(int x, int f)
{
    dep[x] = dep[f] + 1;
    fa[x] = f;
    siz[x] = 1;
    for (int i = hd[x]; i; i = rd[i].nxt)
    {
        int y = rd[i].to;
        if (y == f)
            continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if (siz[y] > siz[son[x]])
            son[x] = y;
    }
}
void dfs2(int x, int topf)
{
    id[x] = ++tot;
    afw[tot] = w[x];
    top[x] = topf;
    if (!son[x])
        return;
    dfs2(son[x], topf);
    for (int i = hd[x]; i; i = rd[i].nxt)
    {
        int y = rd[i].to;
        if (y == fa[x] || y == son[x])
            continue;
        dfs2(y, y);
    }
}
void solve(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        change(1, id[top[u]], id[u], w);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    change(1, id[u], id[v], w);
}
int query(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res += query(1, id[top[u]], id[u]);
        if (check(1, id[top[u]]) == check(1, id[fa[top[u]]]))
            res--;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    res += query(1, id[u], id[v]);
    return res;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        char ch;
        int u, v, w;
        cin >> ch;
        if (ch == 'C')
        {
            scanf("%d%d%d", &u, &v, &w);
            solve(u, v, w);
        }
        else
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", query(u, v));
        }
    }
    return 0;
}