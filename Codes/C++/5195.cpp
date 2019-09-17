#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int inf = 1e9 + 7;
const int way[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
struct node
{
    int x, y;
};
int dis1[maxn][maxn], dis2[maxn][maxn];
int a[maxn][maxn];
int n, m, sx, sy, tx, ty;
void bfs1(int x, int y)
{
    memset(dis1, 0x3f, sizeof(dis1));
    queue<node> q;
    q.push((node){x, y});
    dis1[x][y] = 0;
    while (!q.empty())
    {
        node v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = v.x + way[i][0], ny = v.y + way[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 1)
                continue;
            if (dis1[v.x][v.y] + 1 < dis1[nx][ny])
            {
                dis1[nx][ny] = dis1[v.x][v.y] + 1;
                q.push((node){nx, ny});
            }
        }
    }
}
void bfs2(int x, int y)
{
    memset(dis2, 0x3f, sizeof(dis2));
    queue<node> q;
    q.push((node){x, y});
    dis2[x][y] = 0;
    while (!q.empty())
    {
        node v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = v.x + way[i][0], ny = v.y + way[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 1)
                continue;
            if (dis2[v.x][v.y] + 1 < dis2[nx][ny])
            {
                dis2[nx][ny] = dis2[v.x][v.y] + 1;
                q.push((node){nx, ny});
            }
        }
    }
}
signed main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
                sx = i, sy = j;
            if (a[i][j] == 3)
                tx = i, ty = j;
        }
    bfs1(sx, sy);
    bfs2(tx, ty);
    int ans = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 4)
                ans = min(ans, dis1[i][j] + dis2[i][j]);
    printf("%d\n", ans);
    return 0;
}