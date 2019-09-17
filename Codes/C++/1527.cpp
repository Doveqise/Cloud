#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int maxq = 6e4 + 5;
int n, q, c[maxn][maxn], size[maxq], ans[maxq], id[maxq], t1[maxq], t2[maxq], t[maxq], cnt = 0;
struct mat
{
    int x, y, val;
    bool operator<(const mat b)
    {
        return val < b.val;
    }
} a[maxn * maxn];
struct node
{
    int x1, y1, x2, y2, k;
} b[maxq];

int lowbit(int x) { return x & -x; }

void pushup(int x, int y, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            c[i][j] += val;
}

int query(int x, int y)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            res += c[i][j];
    return res;
}

int cal(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

void solve(int l, int r, int ql, int qr)
{
    if (ql > qr)
        return;
    if (l == r)
    {
        for (int i = ql; i <= qr; i++)
            ans[id[i]] = a[l].val;
        return;
    }
    int mid = l + r >> 1, cnt1 = 0, cnt2 = 0, sum;
    for (int i = l; i <= mid; i++)
        pushup(a[i].x, a[i].y, 1);
    for (int i = ql; i <= qr; i++)
    {
        sum = cal(b[id[i]].x1, b[id[i]].y1, b[id[i]].x2, b[id[i]].y2);
        if (size[id[i]] + sum >= b[id[i]].k)
            t1[++cnt1] = id[i];
        else
            size[id[i]] += sum, t2[++cnt2] = id[i];
    }
    for (int i = l; i <= mid; i++)
        pushup(a[i].x, a[i].y, -1);
    int qcnt = ql - 1;
    for (int i = 1; i <= cnt1; i++)
        t[++qcnt] = t1[i], id[qcnt] = t[qcnt];
    for (int i = 1; i <= cnt2; i++)
        t[++qcnt] = t2[i], id[qcnt] = t[qcnt];
    solve(l, mid, ql, ql + cnt1 - 1), solve(mid + 1, r, ql + cnt1, qr);
}

signed main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++)
        id[i] = i;
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &x);
            a[++cnt] = (mat){i, j, x};
        }
    sort(a + 1, a + cnt + 1);
    for (int i = 1; i <= q; i++)
        scanf("%d%d%d%d%d", &b[i].x1, &b[i].y1, &b[i].x2, &b[i].y2, &b[i].k);
    solve(1, cnt, 1, q);
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}