#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3.5e4 + 5;
int n, tot;
int hd[maxn], to[maxn], nxt[maxn];
int a[maxn], b[maxn], f[maxn], ans[maxn], sum1[maxn], sum2[maxn];
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
signed main()
{
    memset(b, 0x3f, sizeof(b));
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] -= i;
    }
    a[++n] = 0x3f3f3f3f;
    a[0] = b[0] = -0x3f3f3f3f;
    b[1] = a[1], f[1] = 1;
    int len = 1;
    for (int i = 2; i <= n; i++)
    {
        int pt = upper_bound(b, b + len + 1, a[i]) - b;
        len = max(len, pt);
        f[i] = pt;
        b[pt] = min(b[pt], a[i]);
    }
    printf("%lld\n", n - f[n]);
    for (int i = 0; i <= n; i++)
        add(f[i], i);
    memset(ans, 0x3f, sizeof(ans));
    ans[0] = 0;
    for (int u = 1; u <= n; u++)
        for (int i = hd[f[u] - 1]; i; i = nxt[i])
        {
            int v = to[i];
            if (v > u || a[v] > a[u])
                continue;
            for (int k = v; k <= u; k++)
                sum1[k] = abs(a[k] - a[v]), sum2[k] = abs(a[k] - a[u]);
            for (int k = v + 1; k <= u; k++)
                sum1[k] += sum1[k - 1], sum2[k] += sum2[k - 1];
            for (int k = v; k < u; k++)
                ans[u] = min(ans[u], ans[v] + (sum1[k] - sum1[v]) + (sum2[u] - sum2[k]));
        }
    printf("%lld", ans[n]);
    return 0;
}