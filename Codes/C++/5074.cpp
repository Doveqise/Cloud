#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, pw[20], mp[13][13];
ll f[13][13][(1 << 12) + 10];
void solve(int x, int y)
{
    int pl1 = pw[y - 1], pl2 = pw[y];
    for (int i = 0; i < pw[m + 1]; i++)
    {
        if (mp[x][y])
        {
            f[x][y][i] += f[x][y - 1][i ^ pl1 ^ pl2];
            if (((i >> (y - 1)) & 1) == ((i >> y) & 1))
                continue;
            f[x][y][i] += f[x][y - 1][i];
        }
        else
        {
            if (!(i & pl1) && !(i & pl2))
                f[x][y][i] = f[x][y - 1][i];
            else
                f[x][y][i] = 0;
        }
    }
}
signed main()
{
    int t;
    scanf("%d", &t);
    pw[0] = 1;
    for (int i = 1; i <= 15; i++)
        pw[i] = pw[i - 1] << 1;
    for (int u = 1; u <= t; u++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &mp[i][j]);
        memset(f, 0, sizeof(f));
        f[1][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                solve(i, j);
            if (i != n)
                for (int j = 0; j < pw[m]; j++)
                    f[i + 1][0][j << 1] = f[i][m][j];
        }
        printf("%lld\n", f[n][m][0]);
    }
}