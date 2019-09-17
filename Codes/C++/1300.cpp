/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
const int inf = 1e9 + 7;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char s[maxn];
int n, m, sx, sy, sw;
int ans = inf, tot;
int dis[maxn][maxn][4], mp[maxn][maxn];
void dfs(int x, int y, int w, int c)
{
    if (dis[x][y][w] <= c || c >= ans)
        return;
    dis[x][y][w] = c;
    if (mp[x][y] == 2)
        ans = min(ans, dis[x][y][w]);
    bool flg = 0;
    if (mp[x + dx[w]][y + dy[w]])
    {
        flg = 1;
        dfs(x + dx[w], y + dy[w], w, c);
    }
    else if (mp[x + dx[(w + 1) % 4]][y + dy[(w + 1) % 4]])
    {
        flg = 1;
        dfs(x + dx[(w + 1) % 4], y + dy[(w + 1) % 4], (w + 1) % 4, c + 1);
    }
    else if (mp[x + dx[(w + 3) % 4]][y + dy[(w + 3) % 4]])
    {
        flg = 1;
        dfs(x + dx[(w + 3) % 4], y + dy[(w + 3) % 4], (w + 3) % 4, c + 5);
    }
    else if (mp[x + dx[(w + 2) % 4]][y + dy[(w + 2) % 4]] && !flg)
    {
        dfs(x + dx[(w + 2) % 4], y + dy[(w + 2) % 4], (w + 2) % 4, c + 10);
    }
}
signed main()
{
    memset(dis, inf, sizeof(dis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = 1;
            switch (s[j])
            {
            case '.':
                mp[i][j] = 0;
                break;
            case '#':
                break;
            case 'F':
                mp[i][j] = 2;
                break;
            case 'N':
                sx = i;
                sy = j;
                sw = 0;
                break;
            case 'W':
                sx = i;
                sy = j;
                sw = 1;
                break;
            case 'S':
                sx = i;
                sy = j;
                sw = 2;
                break;
            case 'E':
                sx = i;
                sy = j;
                sw = 3;
                break;
            }
        }
    }
    dfs(sx, sy, sw, 0);
    printf("%d\n", ans);
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35, p[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char s[maxn];
int n, m, sx, sy, sw, ans = 1 << 30, dis[maxn][maxn][4], tot;
short mp[maxn][maxn];
void DFS(int x, int y, int w, int c)
{
    if (dis[x][y][w] <= c || c >= ans)
        return;
    dis[x][y][w] = c;
    if (mp[x][y] == 2)
        ans = min(ans, dis[x][y][w]);
    bool flg = 0;
    int fx = x + p[w][0], fy = y + p[w][1];
    int lw = (w + 1) % 4, lx = x + p[lw][0], ly = y + p[lw][1];
    int bw = (w + 2) % 4, bx = x + p[bw][0], by = y + p[bw][1];
    int rw = (w + 3) % 4, rx = x + p[rw][0], ry = y + p[rw][1];
    if (mp[fx][fy])
        flg = 1, DFS(fx, fy, w, c);
    if (mp[lx][ly])
        flg = 1, DFS(lx, ly, lw, c + 1);
    if (mp[rx][ry])
        flg = 1, DFS(rx, ry, rw, c + 5);
    if (mp[bx][by] && !flg)
        DFS(bx, by, bw, c + 10);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            mp[i][j] = 1;
            switch (s[j])
            {
            case '.':
            {
                mp[i][j] = 0;
                break;
            }
            case '#':
            {
                break;
            }
            case 'F':
            {
                mp[i][j] = 2;
                break;
            }
            case 'N':
            {
                sx = i, sy = j, sw = 0;
                break;
            }
            case 'W':
            {
                sx = i, sy = j, sw = 1;
                break;
            }
            case 'S':
            {
                sx = i, sy = j, sw = 2;
                break;
            }
            case 'E':
            {
                sx = i, sy = j, sw = 3;
                break;
            }
            }
        }
    }
    memset(dis, 63, sizeof dis);
    DFS(sx, sy, sw, 0);
    printf("%d\n", ans);
    return 0;
}