#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
const int inf = 1e8 + 9;
struct node
{
    int x, y, type, id, ans;
} a[maxn], b[maxn], tmp[maxn];
int n, q, siz, nd[maxn];
int lowbit(int x) { return x & (-x); }
void update(int x, int v)
{
    for (; x <= siz; x += lowbit(x))
        nd[x] = max(nd[x], v);
}
int query(int x)
{
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans = max(ans, nd[x]);
    return ans ? ans : -inf;
}
void clear(int x)
{
    for (; nd[x]; x += lowbit(x))
        nd[x] = 0;
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    int t1 = l, t2 = mid + 1, k = l;
    while (t2 <= r)
    {
        while (t1 <= mid && b[t1].x <= b[t2].x)
        {
            if (b[t1].type == 1)
                update(b[t1].y, b[t1].x + b[t1].y);
            tmp[k++] = b[t1++];
        }
        if (b[t2].type == 2)
            a[b[t2].id].ans = min(a[b[t2].id].ans, b[t2].x + b[t2].y - query(b[t2].y));
        tmp[k++] = b[t2++];
    }
    for (int i = l; i < t1; i++)
        if (b[i].type == 1)
            clear(b[i].y);
    while (t1 <= mid)
        tmp[k++] = b[t1++];
    for (int i = l; i <= r; i++)
        b[i] = tmp[i];
}
void solve(int dx, int dy)
{
    for (int i = 1; i <= n + q; i++)
    {
        b[i] = a[i];
        if (dx)
            b[i].x = siz - b[i].x;
        if (dy)
            b[i].y = siz - b[i].y;
    }
    cdq(1, n + q);
}
signed main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        a[i] = (node){++x, ++y, 1, i, inf};
        siz = max(siz, x > y ? x : y);
    }
    for (int i = 1, opt, x, y; i <= q; i++)
    {
        scanf("%d%d%d", &opt, &x, &y);
        a[i + n] = (node){++x, ++y, opt, i + n, inf};
        siz = max(siz, x > y ? x : y);
    }
    siz++;
    solve(0, 0), solve(0, 1), solve(1, 0), solve(1, 1);
    for (int i = n + 1; i <= n + q; i++)
        if (a[i].type == 2)
            printf("%d\n", a[i].ans);
    return 0;
}
