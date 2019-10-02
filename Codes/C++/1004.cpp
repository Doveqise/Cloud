#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e1 + 5;
int f[maxn][maxn][maxn][maxn], mp[maxn][maxn];
int n;
signed main()
{
    scanf("%d", &n);
    int x, y, pos;
    while (scanf("%d%d%d", &x, &y, &pos) && (x || y || pos))
        mp[x][y] = pos;
    for (int i1 = 1; i1 <= n; i1++)
        for (int i2 = 1; i2 <= n; i2++)
            for (int j1 = 1; j1 <= n; j1++)
                for (int j2 = 1; j2 <= n; j2++)
                {
                    f[i1][j1][i2][j2] = max(f[i1 - 1][j1][i2 - 1][j2], max(f[i1 - 1][j1][i2][j2 - 1], max(f[i1][j1 - 1][i2 - 1][j2], f[i1][j1 - 1][i2][j2 - 1]))) + mp[i1][j1] + mp[i2][j2];
                    if (i1 == i2 && j1 == j2)
                        f[i1][j1][i2][j2] -= mp[i1][j1];
                }
    printf("%d\n", f[n][n][n][n]);
    return 0;
}