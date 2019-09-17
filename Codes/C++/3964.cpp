#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    long long X, Y;
} a[maxn];
int x[maxn], y[maxn], n, id;
long long ans = 1ll << 62;
long long s1[maxn], s2[maxn];
signed main()
{
    scanf("%d", &n);
    for (int i = 1, p, q; i <= n; i++)
    {
        scanf("%d%d", &p, &q);
        x[i] = a[i].X = p + q;
        y[i] = a[i].Y = p - q;
    }
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        s1[i] = s1[i - 1] + x[i];
        s2[i] = s2[i - 1] + y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long tmp = 0;
        id = lower_bound(x + 1, x + 1 + n, a[i].X) - x;
        tmp += s1[n] - s1[id] - a[i].X * (n - id) + a[i].X * id - s1[id];
        id = lower_bound(y + 1, y + 1 + n, a[i].Y) - y;
        tmp += s2[n] - s2[id] - a[i].Y * (n - id) + a[i].Y * id - s2[id];
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans >> 1);
    return 0;
}
