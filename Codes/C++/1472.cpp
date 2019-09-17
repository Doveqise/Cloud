#include <bits/stdc++.h>
using namespace std;
const int mod = 9901;
int dp[210][110], n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
        dp[1][i] = 1;
    for (int tk = 1; tk <= k; tk++)
        for (int i = 3; i <= n; i += 2)
            for (int j = 1; j < i; j += 2)
                (dp[i][tk] += dp[j][tk - 1] * dp[i - j - 1][tk - 1]) %= mod;
    printf("%d", (dp[n][k] - dp[n][k - 1] + mod) % mod);
    return 0;
}