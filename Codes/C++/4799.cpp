#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
ll l = 1, mid, lim, n, num1, num2, t, m, ans = 0;
ll a[maxn], b[maxn], c[maxn], d[maxn];
void dfs1(int dep, ll sum, int pos)
{
    if (sum > m)
        return;
    if (dep > pos)
    {
        c[++num1] = sum;
        return;
    }
    dfs1(dep + 1, sum, pos);
    dfs1(dep + 1, sum + a[dep], pos);
}
void dfs2(int dep, ll sum, int pos)
{
    if (sum > m)
        return;
    if (dep > pos)
    {
        d[++num2] = sum;
        return;
    }
    dfs2(dep + 1, sum, pos);
    dfs2(dep + 1, sum + b[dep], pos);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    mid = (1 + n) >> 1, lim = n - mid;
    for (int i = 1; i <= mid; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= lim; i++)
        scanf("%lld", &b[i]);
    dfs1(1, 0, mid);
    dfs2(1, 0, lim);
    sort(c + 1, c + num1 + 1);
    sort(d + 1, d + num2 + 1);
    for (int i = num2; i >= 1; i--)
    {
        t = m - d[i];
        while (l <= num1 && c[l] <= t)
            l++;
        ans += (l - 1);
    }
    printf("%lld\n", ans);
    return 0;
}