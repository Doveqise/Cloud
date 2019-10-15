#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int cnt, n, m, pre = 1;
int rt[maxn << 5], sum[maxn << 5], a[maxn << 5], ls[maxn << 5], rs[maxn << 5];
int b[maxn], c[maxn];
#define mid ((l + r) >> 1)
struct Inter
{
    int l, r;
    bool operator<(const Inter b) const
    {
        return l == b.l ? r < b.r : l < b.l;
    }
} itv[maxn];
int f(int a, int b, int c)
{
    return (a * pre + b) % c + 1;
}
void build(int &u, int l, int r)
{
    u = ++cnt;
    if (l == r)
        return;
    build(ls[u], l, mid);
    build(rs[u], mid + 1, r);
    return;
}
void update(int &u, int v, int l, int r, int x, int k)
{
    u = ++cnt;
    ls[u] = ls[v], rs[u] = rs[v], sum[u] = sum[v], a[u] = a[v];
    a[u] += k;
    sum[u] += k * c[x];
    if (l == r)
        return;
    if (x <= mid)
        update(ls[u], ls[v], l, mid, x, k);
    else
        update(rs[u], rs[v], mid + 1, r, x, k);
    return;
}

int query(int u, int l, int r, int k)
{
    if (l == r)
        return sum[u] / a[u] * k;
    if (a[ls[u]] >= k)
        return query(ls[u], l, mid, k);
    else
        return sum[ls[u]] + query(rs[u], mid + 1, r, k - a[ls[u]]);
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int p = (i << 1) - 1, q = i << 1;
        scanf("%d%d%d", &itv[p].l, &itv[q].l, &itv[p].r);
        ++itv[q].l;
        itv[q].r = -itv[p].r;
        c[i] = itv[p].r;
    }
    sort(c + 1, c + 1 + n);
    int siz = unique(c + 1, c + 1 + n) - c - 1;
    build(rt[0], 1, siz);
    sort(itv + 1, itv + 1 + (n << 1));
    int pt = 1;
    for (int i = 1; i <= (n << 1); i++)
    {
        while (pt < itv[i].l)
        {
            rt[pt + 1] = rt[pt];
            pt++;
        }
        if (pt == n + 1)
            break;
        int k = lower_bound(c + 1, c + 1 + siz, abs(itv[i].r)) - c;
        update(rt[k], rt[k], 1, siz, k, itv[i].r > 0 ? 1 : -1);
    }
    for (int i = 1, x, ai, bi, ci; i <= m; i++)
    {
        scanf("%d%d%d%d", &x, &ai, &bi, &ci);
        int k = f(ai, bi, ci);
        if (a[rt[x]] <= k)
            printf("%d\n", pre = sum[rt[x]]);
        else
            printf("%d\n", pre = query(rt[x], 1, siz, k));
    }
    return 0;
}