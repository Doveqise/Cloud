#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int dx[] = {0, 0, 1, -1},
          dy[] = {1, -1, 0, 0};
struct node
{
    int x, y, s;
};
queue<node> q;
int n, m, t, sx, sy, tx, ty, dp[maxn][maxn][20];
string s[maxn];
signed main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    dp[sx][sy][0] = 1;
    q.push((node){sx, sy, 0});
    while (!q.empty())
    {
        node frm = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            node to;
            to.x = frm.x + dx[i];
            to.y = frm.y + dy[i];
            to.s = frm.s + 1;
            if (dp[to.x][to.y][to.s])
            {
                dp[to.x][to.y][to.s] += dp[frm.x][frm.y][frm.s];
                continue;
            }
            if (to.x < 1 || to.x > n || to.y < 1 || to.y > m || s[to.x][to.y - 1] == '*' || to.s > t)
                continue;
            dp[to.x][to.y][to.s] += dp[frm.x][frm.y][frm.s];
            q.push(to);
        }
    }
    printf("%d\n", dp[tx][ty][t]);
    return 0;
}