#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const int maxn = 1e3 + 5;
int a[maxn], b[maxn], f[12][maxn][maxn];
int n, m, p;
int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[0][i][j] = 1;
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                if (a[j] > b[k])
                    f[i][j][k] = f[i - 1][j - 1][k - 1];
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                f[i][j][k] = (f[i][j][k] + f[i][j][k - 1]) % mod;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                f[i][j][k] = (f[i][j][k] + f[i][j - 1][k]) % mod;
    }
    printf("%d", f[p][n][m]);
}