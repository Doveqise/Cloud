#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int frm, nxt, val;
} a[maxn << 1];
int n, e, sum = 0;
int fr[maxn], c[maxn], s[maxn], maxs[maxn];
void add(int f, int t, int v)
{
    a[++e].frm = t;
    a[e].nxt = fr[f];
    fr[f] = e;
    a[e].val = v;
}
void dp(int fa, int u)
{
    s[u] = c[u];
    for (int i = fr[u]; i; i = a[i].nxt)
        if (a[i].frm != fa)
        {
            dp(u, a[i].frm);
            s[u] += s[a[i].frm];
            maxs[u] = max(maxs[u], s[a[i].frm]);
        }
    maxs[u] = max(maxs[u], sum - s[u]);
}
void dfs(int fa, int u)
{
    for (int i = fr[u]; i; i = a[i].nxt)
        if (a[i].frm != fa)
        {
            s[a[i].frm] = s[u] + a[i].val;
            dfs(u, a[i].frm);
        }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    for (int i = 1, x, y, z; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    dp(1, 1);
    int tmp = 1;
    for (int i = 2; i <= n; i++)
        if (maxs[i] < maxs[tmp])
            tmp = i;
    s[tmp] = 0;
    dfs(tmp, tmp);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (long long)c[i] * s[i];
    printf("%lld", ans);
    return 0;
}