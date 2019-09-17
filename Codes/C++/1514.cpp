#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};
int n, m, ans;
int a[maxn][maxn], col[maxn], vis[maxn][maxn];
struct node
{
    int l, r;
} nd[maxn];
void dfs(int x, int y, int h)
{
    if (vis[x][y] || x > n || y > m)
        return;
    vis[x][y] = 1;
    if (x == n && h)
        nd[h].l = min(nd[h].l, y), nd[h].r = max(nd[h].r, y);
    for (int i = 0; i < 4; i++)
        if (a[x + dx[i]][y + dy[i]] < a[x][y])
            dfs(x + dx[i], y + dy[i], h);
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= m; i++)
        dfs(1, i, 0);
    int flg = 0;
    for (int i = 1; i <= m; i++)
        if (!vis[n][i])
            flg++;
    if (flg)
    {
        printf("0\n%d\n", flg);
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        memset(vis, 0, sizeof(vis));
        nd[i].l = maxn;
        dfs(1, i, i);
        if (nd[i].l != maxn && nd[i].r)
            ans++;
        for (int pt = nd[i].l; pt <= nd[i].r; pt++)
            col[pt]++;
    }
    for (int i = 1; i <= m; i++)
        for (int pt = nd[i].l; pt <= nd[i].r; pt++)
        {
            if (col[pt] == 1)
                break;
            if (pt == nd[i].r)
            {
                for (int pt2 = nd[i].l; pt2 <= nd[i].r; pt2++)
                    col[pt2]--;
                ans--;
            }
        }
    printf("1\n%d\n", ans);
    return 0;
}