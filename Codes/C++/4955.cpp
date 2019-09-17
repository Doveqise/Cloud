#include <bits/stdc++.h>
using namespace std;
#define pair <int, int> pii
const int maxn = 505;
int a[maxn][maxn], b[maxn][maxn];
int vis[maxn][maxn];
int x, y;
int n, m;
int nx[] = {0, 0, 1, -1};
int ny[] = {1, -1, 0, 0};
queue<pii> q;
inline bool check(int mid)
{
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        int px = p.first, py = p.second;
        for (int i = 0; i < 4; i++)
        {
            int tx = px + nx[i], ty = py + ny[i];
            if (tx < 1 || ty < 1 || tx > n || ty > m)
                continue;
            if (!vis[tx][ty] && abs(a[tx][ty] - a[px][py]) <= mid)
            {
                vis[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j] && !vis[i][j])
                return 0;
    return 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &b[i][j]);
            if (b[i][j])
                x = i, y = j;
        }
    int l = 0, r = 1e9 + 1, mid, ans;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}