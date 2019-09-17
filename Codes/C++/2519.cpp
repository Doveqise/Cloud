#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tn, f[N];
struct node
{
    int l, r, v;
} a[N], b[N];
bool cmp1(node a, node b)
{
    if (a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}
bool cmp2(node a, node b)
{
    if (a.r != b.r)
        return a.r < b.r;
    return a.l < b.l;
}
int fd(int l, int r, int val)
{
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid].r < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    int i, x, y, tmpn;
    scanf("%d", &tmpn);
    for (i = 1; i <= tmpn; i++)
    {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].l++;
        a[i].r = tmpn - a[i].r;
    }
    sort(a + 1, a + tmpn + 1, cmp1);
    for (i = 1; i <= tmpn; i++)
        if (a[i].l <= a[i].r)
            b[++tn] = a[i];
    for (i = 1; i <= tn; i++)
        if (i == 1 || b[i].l != b[i - 1].l || b[i].r != b[i - 1].r)
            a[++n] = b[i], a[n].v = 1;
        else if (a[n].v < a[n].r - a[n].l + 1)
            a[n].v++;
    sort(a + 1, a + n + 1, cmp2);
    f[1] = a[1].v;
    for (i = 2; i <= n; i++)
    {
        int nxt = fd(1, i - 1, a[i].l);
        f[i] = max(f[i - 1], f[nxt] + a[i].v);
    }
    printf("%d\n", tmpn - f[n]);
    return 0;
}