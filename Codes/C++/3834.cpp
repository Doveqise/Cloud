#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int cnt, n, m;
int rt[maxn << 5], sum[maxn << 5], a[maxn << 5], ls[maxn << 5], rs[maxn << 5];
int b[maxn], c[maxn];
#define mid ((l + r) >> 1)
void build(int &u, int l, int r)
{
    u = ++cnt;
    if (l == r)
        return;
    build(ls[u], l, mid);
    build(rs[u], mid + 1, r);
}
void update(int &u, int v, int l, int r, int x)
{
    u = ++cnt;
    ls[u] = ls[v], rs[u] = rs[v], sum[u] = sum[v] + 1;
    if (l == r)
        return;
    if (x <= mid)
        update(ls[u], ls[v], l, mid, x);
    else
        update(rs[u], rs[v], mid + 1, r, x);
    return;
}

int query(int u, int v, int l, int r, int k)
{
    if (l >= r)
        return l;
    int num = sum[ls[v]] - sum[ls[u]];
    if (num >= k)
        return query(ls[u], ls[v], l, mid, k);
    else
        return query(rs[u], rs[v], mid + 1, r, k - num);
    return 0;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]), c[i] = b[i];
    sort(c + 1, c + 1 + n);
    int siz = unique(c + 1, c + 1 + n) - c - 1;
    build(rt[0], 1, siz);
    for (int i = 1; i <= n; i++)
    {
        int l = lower_bound(c + 1, c + 1 + siz, b[i]) - c;
        update(rt[i], rt[i - 1], 1, siz, l);
    }
    for (int i = 1, l, r, k; i <= m; i++)
    {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", c[query(rt[l - 1], rt[r], 1, siz, k)]);
    }
}