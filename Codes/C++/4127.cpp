#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r, dp[20][200][200];
int len, a[20], mod;
ll dfs(int pos, int sum, int lim, ll st)
{
    if (pos > len && !sum)
        return 0;
    if (pos > len)
        return (!st) && (sum == mod);
    if (!lim && dp[pos][sum][st] != -1)
        return dp[pos][sum][st];
    ll ret = 0;
    int res = lim ? a[len - pos + 1] : 9;
    for (int i = 0; i <= res; i++)
        ret += dfs(pos + 1, sum + i, i == res && lim, (10ll * st + i) % mod);
    return lim ? ret : dp[pos][sum][st] = ret;
}
ll split(ll x)
{
    len = 0;
    while (x)
        a[++len] = x % 10, x /= 10;
    ll ret = 0;
    for (mod = 1; mod <= 9 * len; mod++)
    {
        memset(dp, -1, sizeof dp);
        ret += dfs(1, 0, 1, 0);
    }
    return ret;
}
signed main()
{
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", split(r) - split(l - 1));
    return 0;
}