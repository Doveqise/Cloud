#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int dx[] = {-1, 0, 1, 0},
          dy[] = {0, 1, 0, -1};
int f[maxn][maxn], h[maxn][maxn], n, m, minh = 1234567890, ans = 0;
void dfs(int posx, int posy, int res)
{
    if (h[posx][posy] - minh + f[posx][posy] + 1 <= ans)
        return;
    if (res < f[posx][posy] || posx < 1 || posx > n || posy < 1 || posy > m)
        return;
    f[posx][posy] = max(f[posx][posy], res);
    ans = max(ans, res);
    for (int i = 0; i < 4; i++)
    {
        if (h[posx][posy] > h[posx + dx[i]][posy + dy[i]])
            dfs(posx + dx[i], posy + dy[i], f[posx][posy] + 1);
    }
    return;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &h[i][j]), f[i][j] = 1, minh = min(minh, h[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (h[i][j] - minh + 1 > ans)
                dfs(i, j, f[i][j]);
    printf("%d\n", ans);
    return 0;
}