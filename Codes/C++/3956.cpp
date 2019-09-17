#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e3 + 5;
const int dx[] = {-1, 0, 1, 0},
          dy[] = {0, 1, 0, -1};
int f[maxm][maxm], col[maxm][maxm];
int n, m;
int solve(int x, int y, int i, int c)
{
    return f[x + dx[i]][y + dy[i]] - abs(c - col[x + dx[i]][y + dy[i]]);
}
void dfs(int px, int py, int nco, int flg, int res)
{
    if (px < 1 || px > m || py < 1 || py > m)
        return;
    f[px][py] = res;
    for (int i = 0; i < 4; i++)
        if (res < solve(px, py, i, nco) && col[px + dx[i]][py + dy[i]] != -1)
            dfs(px + dx[i], py + dy[i], col[px + dx[i]][py + dy[i]], 1, res + abs(nco - col[px + dx[i]][py + dy[i]]));
    if (flg)
        for (int i = 0; i < 4; i++)
            if (res + 2 < f[px + dx[i]][py + dy[i]] && col[px + dx[i]][py + dy[i]] == -1)
                dfs(px + dx[i], py + dy[i], nco, 0, res + 2);
    return;
}
signed main()
{
    memset(col, -1, sizeof(col));
    memset(f, 0x3f, sizeof(f));
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y, co;
        scanf("%d%d%d", &x, &y, &co);
        col[x][y] = co;
    }
    dfs(1, 1, col[1][1], 1, 0);
    if (f[1001][1001] == f[m][m])
        f[m][m] = -1;
    printf("%d\n", f[m][m]);
    return 0;
}