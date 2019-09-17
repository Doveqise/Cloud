#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e2 + 5;
const int maxm = 4e1 + 5;
long long dp[maxm][maxm][maxm];
int a[maxn], b[5];
signed main()
{
    memset(dp, -0x3f, sizeof(dp));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1, t; i <= m; i++)
    {
        scanf("%d", &t);
        b[t]++;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i <= b[1]; i++)
        for (int j = 0; j <= b[2]; j++)
            for (int k = 0; k <= b[3]; k++)
                for (int l = 0; l <= b[4]; l++)
                {
                    int t = a[i + 2 * j + 3 * k + 4 * l + 1];
                    if (j)
                        dp[j][k][l] = max(dp[j - 1][k][l], dp[j][k][l]);
                    if (k)
                        dp[j][k][l] = max(dp[j][k - 1][l], dp[j][k][l]);
                    if (l)
                        dp[j][k][l] = max(dp[j][k][l - 1], dp[j][k][l]);
                    dp[j][k][l] += t;
                }
    printf("%lld\n", dp[b[2]][b[3]][b[4]]);
    return 0;
}