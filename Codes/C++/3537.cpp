#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxk = 1e5 + 5;
const int inf = 1e9 + 7;
struct node
{
    int a, b, c, id;
    bool operator<(const node b) const
    {
        return a < b.a;
    }
} a[maxn], b[maxn * maxn];
int f[maxk], ans[maxn * maxn];
signed main()
{
    int n, m;
    f[0] = inf;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].c, &a[i].a, &a[i].b);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &b[b[i].id = i].a, &b[i].b, &b[i].c);
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    for (int i = 1, j = 1; i <= m; ans[b[i].id] = f[b[i].b] > b[i].a + b[i].c, i++)
        while (j <= n && a[j].a <= b[i].a)
            for (int k = maxk - 5; k >= a[j].c ? 1 : (!(j++)); k--)
                f[k] = max(f[k], min(f[k - a[j].c], a[j].b));
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "TAK" : "NIE");
    return 0;
}