// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll dp[100][100], l, r, a[100];
ll dfs(int pos, int dig, bool flg, bool lim, ll sum)
{
    ll ans = 0;
    if (pos == -1)
        return sum;
    if (dp[pos][sum] != -1 && !lim && !flg)
        return dp[pos][sum];
    int up = lim ? a[pos] : 9;
    for (int i = 0; i <= up; i++)
        ans += dfs(pos - 1, dig, flg && i == 0, lim && i == a[pos], sum + ((i || !flg) && i == dig));
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
    while(cin>>l>>r&&l&&r)
    {
    	if(l>r)
			swap(l,r);
        for (int i = 0; i <= 9; i++)
            printf("%llu ", solve(r, i) - solve(l - 1, i));
        printf("\n");
    }
    return 0;
}
