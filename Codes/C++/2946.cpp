#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int MOD = 1e8;
int f[maxn][maxn] = {1}, r[maxn];
signed main()
{
    int n, F;
    scanf("%d%d", &n, &F);
    for (int i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++)
        for (int v = 0; v <= F; v++)
        {
            f[i][v] = (f[i][v] + f[i - 1][v]) % MOD;
            f[i][v] = (f[i][v] + f[i - 1][(v + r[i]) % F]) % MOD;
        }
    printf("%d\n", f[n][F]);
    return 0;
}