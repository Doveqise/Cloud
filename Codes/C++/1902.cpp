#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct node
{
    int x, y;
};
int n, m, p[maxn][maxn], vis[maxn][maxn];
int l, r, mid;
bool jud(int x, int y)
{
    return (x <= 0 || y <= 0 || x > n || y > m || p[x][y] > mid || vis[x][y]) ? 1 : 0;
}
bool chk()
{
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push((node){1, 1});
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        int x, y;
        for (int i = 0; i <= 3; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (jud(x, y))
                continue;
            vis[x][y] = 1;
            q.push((node){x, y});
            if (x == n)
                return 1;
        }
    }
    return 0;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &p[i][j]);
    l = 0, r = 1024;
    while (l < r)
    {
        mid = l + r >> 1;
        if (chk())
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}