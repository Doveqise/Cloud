#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m, ti;
int dp[maxn][maxn], val[maxn], t[maxn];
signed main()
{
    scanf("%d%d%d", &n, &m, &ti);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &val[i], &t[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= val[i]; j--)
            for (int k = ti; k >= t[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j - val[i]][k - t[i]] + 1);
    printf("%d\n", dp[m][ti]);
    return 0;
}