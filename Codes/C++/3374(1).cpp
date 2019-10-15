#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
struct node
{
    int type, p, val;
    bool operator<(const node b) const
    {
        return p == b.p ? type > b.type : p < b.p;
    }
} q[maxn << 2], tmp[maxn << 2];
int n, m, tot, qtot;
ll ans[maxn];
void solve(int l, int r)
{
    if (l == r - 1)
        return;
    int i, j, k, mid;
    ll sum = 0;
    i = k = l;
    j = mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid, r);
    while (i < mid && j < r)
    {
        if (q[i] < q[j])
        {
            if (q[i].type == 2)
                sum += q[i].val;
            tmp[k++] = q[i++];
        }
        else
        {
            if (q[j].type != 2)
                ans[q[j].val] += q[j].type * sum;
            tmp[k++] = q[j++];
        }
    }
    while (i < mid)
        tmp[k++] = q[i++];
    while (j < r)
    {
        if (q[j].type != 2)
            ans[q[j].val] += q[j].type * sum;
        tmp[k++] = q[j++];
    }
    for (int i = l; i < r; i++)
        q[i] = tmp[i];
}
signed main()
{
    int i, op, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        q[++tot].type = 2;
        q[tot].p = i;
        q[tot].val = x;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            q[++tot].type = 2;
            q[tot].p = x;
            q[tot].val = y;
        }
        else
        {
            q[++tot].type = -1;
            q[tot].p = x - 1;
            q[tot].val = ++qtot;
            q[++tot].type = 1;
            q[tot].p = y;
            q[tot].val = qtot;
        }
    }
    solve(1, tot + 1);
    for (int i = 1; i <= qtot; i++)
        printf("%lld\n", ans[i]);
    return 0;
}