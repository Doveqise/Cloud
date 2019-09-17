#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200][100], l, r, a[200];
ll dfs(int pos, int dig, bool flg, bool lim, ll sum)
{
    ll ans = 0;
    if (pos == -1)
        return sum;
    if (dp[pos][sum] != -1 && !lim && !flg)
        return dp[pos][sum];
    int up = lim ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
        ans += dfs(pos - 1, dig, i ? 0 : flg, lim ? i == a[pos] : 0, sum + (!(i ? 0 : flg) && (i == dig)));
    if (!lim && !flg)
        dp[pos][sum] = ans;
    return ans;
}
ll solve(ll x, int dig)
{
    memset(dp, -1, sizeof(dp));
    int len = 0;
    while (x)
    {
        a[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, dig, 1, 1, 0);
}
signed main()
{
    scanf("%lld%lld", &l, &r);
    for (int i = 0; i <= 9; i++)
        printf("%lld ", solve(r, i) - solve(l - 1, i));
    return 0;
}
#include <bits/stdc++.h>
