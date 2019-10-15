#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int cnt, n, m;
int rt[maxn << 5], a[maxn << 5], ls[maxn << 5], rs[maxn << 5];
int b[maxn];
#define mid ((l + r) >> 1)
void build(int &u, int l, int r)
{
    u = ++cnt;
    if (l == r)
    {
        a[u] = b[l];
        return;
    }
    build(ls[u], l, mid);
    build(rs[u], mid + 1, r);
}
void update(int &u, int v, int l, int r, int x, int p)
{
    u = ++cnt;
    ls[u] = ls[v], rs[u] = rs[v], a[u] = a[v];
    if (l == r)
    {
        a[u] = p;
        return;
    }
    if (x <= mid)
        update(ls[u], ls[v], l, mid, x, p);
    else
        update(rs[u], rs[v], mid + 1, r, x, p);
    return;
}

int query(int u, int l, int r, int k)
{
    if (l == r)
        return a[u];
    if (k <= mid)
        return query(ls[u], l, mid, k);
    else
        return query(rs[u], mid + 1, r, k);
}

signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    build(rt[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int v, opt, loc, val;
        scanf("%d%d", &v, &opt);
        switch (opt)
        {
        case 1:
            scanf("%d%d", &loc, &val);
            update(rt[i], rt[v], 1, n, loc, val);
            break;
        case 2:
            scanf("%d", &loc);
            rt[i] = rt[v];
            printf("%d\n", query(rt[v], 1, n, loc));
            break;
        }
    }
}