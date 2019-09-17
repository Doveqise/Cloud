#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int p[maxn], dp[maxn][maxn][2];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    sort(p + 1, p + n + 1);
    memset(dp, 63, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i][0] = dp[i][i][1] = abs(p[i]) * n;
    for (int k = 2; k <= n; k++)
        for (int l = 1; l + k - 1 <= n; l++)
        {
            int r = l + k - 1;
            dp[l][r][0] = min(dp[l + 1][r][0] + (n - r + l) * (p[l + 1] - p[l]), dp[l + 1][r][1] + (n - r + l) * (p[r] - p[l]));
            dp[l][r][1] = min(dp[l][r - 1][1] + (n - r + l) * (p[r] - p[r - 1]), dp[l][r - 1][0] + (n - r + l) * (p[r] - p[l]));
        }
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    return 0;
}