#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;
int a[350], f[500005];
long long dp[500005];
int n, tot, sum;
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    tot = sum;
    sum /= 2;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= a[i]; j--)
            f[j] = max(f[j], f[j - a[i]] + a[i]);
    printf("%d\n", tot - 2 * f[sum]);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = tot; j >= a[i]; j--)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    printf("%lld", dp[f[sum]]);
    return 0;
}