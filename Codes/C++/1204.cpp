#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
struct node
{
    int l, r;
    bool operator<(const node b) const
    {
        return l < b.l;
    }
} q[maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &q[i].l, &q[i].r);
    sort(q + 1, q + 1 + n);
    int l = q[1].l, r = q[1].r, x = 0, y = 0;
    for (int i = 2; i <= n; i++)
        if (q[i].l <= r)
            r = max(r, q[i].r);
        else
            x = max(x, r - l), y = max(y, q[i].l - r), l = q[i].l, r = q[i].r;
    x = max(x, r - l);
    printf("%d %d", x, y);
    return 0;
}