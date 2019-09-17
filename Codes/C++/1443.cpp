#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int maxn = 4e2 + 5;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2},
          dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int f[maxn][maxn], n, m, posx, posy;
void dfs(int posx, int posy)
{
    memset(f, -1, sizeof(f));
    f[posx][posy] = 0;
    queue<pii> q;
    q.push(make_pair(posx, posy));
    while (!q.empty())
    {
        pii t = q.front();
        q.pop();
        for (int ti = 0; ti < 8; ti++)
        {
            if (t.first + dx[ti] < 1 || t.first + dx[ti] > n || t.second + dy[ti] < 1 || t.second + dy[ti] > m)
                continue;
            if (f[t.first + dx[ti]][t.second + dy[ti]] == -1)
            {
                q.push(make_pair(t.first + dx[ti], t.second + dy[ti]));
                f[t.first + dx[ti]][t.second + dy[ti]] = f[t.first][t.second] + 1;
                continue;
            }
            f[t.first + dx[ti]][t.second + dy[ti]] = min(f[t.first + dx[ti]][t.second + dy[ti]], f[t.first][t.second] + 1);
        }
    }
}
signed main()
{
    scanf("%d%d%d%d", &n, &m, &posx, &posy);
    dfs(posx, posy);
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            printf("%-5d", f[i][j]);
    return 0;
}
