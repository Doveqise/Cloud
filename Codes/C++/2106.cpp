#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2000000][10], l, r;
int tot, a[2000000], k = 2;
ll mod = 1000000007;
ll qpow(ll b)
{
    ll ret = 1, base = 10;
    while (b)
    {
        if (b & 1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ret;
}
ll dfs(int pos, int pre, bool flg, bool lim)
{
    ll ans = 0;
    if (pos == -1)
        return 1;
    if (dp[pos][pre] != -1 && !flg && !lim)
        return dp[pos][pre];
    int up = lim ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
        if (flg || abs(pre - i) <= k)
            ans += dfs(pos - 1, i, i ? 0 : flg, i == a[pos] ? lim : 0);
    if (!flg && !lim)
        dp[pos][pre] = ans;
    return ans;
}
ll solve(ll x)
{
    tot = 0;
    while (x)
    {
        a[tot++] = x % 10;
        x /= 10;
    }
    return dfs(tot - 1, 0, 1, 1);
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &k);
    printf("%lld\n", solve(qpow(k)) - solve(qpow(k - 1)));
    return 0;
}