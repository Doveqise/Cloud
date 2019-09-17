#include <bits/stdc++.h>
#define int long long
const int N = 1e6 + 5;
using namespace std;
int n, m, ans;
int a[N], val[N], pre[N], colpre[N];
int ls(int x)
{
    return x << 1;
}
int rs(int x)
{
    return x << 1 | 1;
}
struct node
{
    int lmax, rmax, sum, all;
} t[N << 2];
inline void pushup(int k)
{
    t[k].all = t[ls(k)].all + t[rs(k)].all;
    t[k].lmax = max(t[ls(k)].lmax, t[ls(k)].all + t[rs(k)].lmax);
    t[k].rmax = max(t[rs(k)].rmax, t[rs(k)].all + t[ls(k)].rmax);
    t[k].sum = max(max(t[k].lmax, t[k].rmax), t[ls(k)].rmax + t[rs(k)].lmax);
}
inline void update(int k, int l, int r, int x, int y)
{
    if (l == r)
    {
        t[k].all = t[k].rmax = t[k].lmax = t[k].sum = y;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(ls(k), l, mid, x, y);
    if (x > mid)
        update(rs(k), mid + 1, r, x, y);
    pushup(k);
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld", &val[i]);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = colpre[a[i]];
        colpre[a[i]] = i;
        if (pre[i])
            update(1, 1, n, pre[i], -val[a[i]]);
        if (pre[pre[i]])
            update(1, 1, n, pre[pre[i]], 0);
        update(1, 1, n, i, val[a[i]]);
        ans = max(ans, t[1].sum);
    }
    printf("%lld\n", ans);
    return 0;
}
