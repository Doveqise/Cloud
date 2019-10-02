#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 8e2 + 5;
const int mod = 1e9 + 7;
int a[maxn][maxn], dp[maxn][maxn][20][2];
signed main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            dp[i][j][a[i][j] % k][0] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int h = 0; h <= k; h++)
            {
                dp[i][j][h][0] = (dp[i][j][h][0] + dp[i - 1][j][(h - a[i][j] + k) % k][1] + dp[i][j - 1][(h - a[i][j] + k) % k][1]) % mod;
                dp[i][j][h][1] = (dp[i][j][h][1] + dp[i - 1][j][(h + a[i][j]) % k][0] + dp[i][j - 1][(h + a[i][j]) % k][0]) % mod;
            }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = (ans + dp[i][j][0][1]) % mod;
    printf("%lld\n", ans);
    return 0;
}