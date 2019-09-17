#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
ull dp[2000][1000], l, r, a[2000], ans = 0;
ull dfs(ull pos, ull dig, bool flg, bool lim, ull sum)
{
    ull ans = 0;
    if (pos == -1)
        return sum;
    if (dp[pos][sum] != -1 && !lim && !flg)
        return dp[pos][sum];
    ull up = lim ? a[pos] : 9;
    for (ull i = 0; i <= up; i++)
        ans += dfs(pos - 1, dig, i ? 0 : flg, lim ? i == a[pos] : 0, sum + (!(i ? 0 : flg) && (i == dig)));
    if (!lim && !flg)
        dp[pos][sum] = ans;
    return ans;
}
ull solve(ull x, ull dig)
{
    memset(dp, -1, sizeof(dp));
    ull len = 0;
    while (x)
    {
        a[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, dig, 1, 1, 0);
}
signed main()
{
    ull T;
    scanf("%llu", &T);
    while (T--)
    {
        ans = 0;
        scanf("%llu%llu", &l, &r);
        for (ull i = 0; i <= 9; i++)
            ans = (ans + (solve(r, i) - solve(l - 1, i)) * i + mod) % mod;
        printf("%llu\n", (ans + mod) % mod);
    }
    return 0;
}