#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
char s[maxn];
int sum[maxn][maxn], g[maxn][maxn][maxn], f[maxn][3000];
signed main()
{
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
    {
        sum[i][0] = 0;
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + (s[j] - '0');
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= m; k++)
                for (int q = j - 1; q < k; q++)
                    g[i][j][k] = max(g[i][j][k], g[i][j - 1][q] + max(sum[i][k] - sum[i][q], k - q - sum[i][k] + sum[i][q]));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++)
            for (int k = 1; k <= min(j, m); k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k] + g[i][k][m]);
    int ans = 0;
    for (int i = 1; i <= t; i++)
        ans = max(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}