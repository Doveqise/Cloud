#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
int dis[maxn][maxn];
int n, m;
bool g[maxn][maxn][maxn];
void init()
{
    for (int k = 1; k <= 64; k++)
        for (int i = 1; i <= n; i++)
            for (int t = 1; t <= n; t++)
                for (int j = 1; j <= n; j++)
                    if (g[i][t][k - 1] && g[t][j][k - 1])
                    {
                        g[i][j][k] = 1;
                        dis[i][j] = 1;
                    }
}
void solve()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
signed main()
{
    memset(g, 0, sizeof(g));
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        dis[x][y] = 1;
        g[x][y][0] = 1;
    }
    init();
    solve();
    printf("%d\n", dis[1][n]);
    return 0;
}