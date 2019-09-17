#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e3 + 5;
int f[maxn], a[maxn], n, C, ans;
void dfs(int rem, int res)
{
    ans = max(ans, res);
    if (res + f[rem] <= ans)
        return;
    for (int i = rem; i; i--)
        if (res + a[i] <= C)
            dfs(i - 1, res + a[i]);
    return;
}
signed main()
{
    scanf("%lld%lld", &n, &C);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > C)
            n = i - 1;
        f[i] = f[i - 1] + a[i];
    }
    dfs(n, 0);
    printf("%lld\n", ans);
    return 0;
}