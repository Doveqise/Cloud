#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};
int n, m;
int a[maxn][maxn], bar[maxn][maxn], vis[maxn][maxn][4];
struct node
{
    int x, y, fx, step;
} st, ed;
queue<node> q;
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= m + 1; j++)
            if (a[i - 1][j - 1] || a[i - 1][j] || a[i][j - 1] || a[i][j] || i == 1 || j == 1 || i == n + 1 || j == m + 1)
                bar[i][j] = 1;
    scanf("%d%d%d%d", &st.x, &st.y, &ed.x, &ed.y);
    st.x++, st.y++, ed.x++, ed.y++;
    char s[2];
    scanf("%s", s);
    switch (s[0])
    {
    case 'E':
        st.fx = 0;
        break;
    case 'S':
        st.fx = 1;
        break;
    case 'W':
        st.fx = 2;
        break;
    case 'N':
        st.fx = 3;
        break;
    default:
        break;
    }
    vis[st.x][st.y][st.fx] = 1;
    st.step = 0;
    q.push(st);
    while (!q.empty())
    {
        node k = q.front();
        q.pop();
        if (k.x == ed.x && k.y == ed.y)
        {
            printf("%d\n", k.step);
            return 0;
        }
        int nowx = k.x, nowy = k.y, nowstep = k.step, nowface = k.fx;
        node to;
        to.step = nowstep + 1;
        for (int i = -1; i <= 1; i++)
        {
            to.x = nowx, to.y = nowy, to.fx = (nowface + i + 4) % 4;
            if (vis[nowx][nowy][to.fx])
                continue;
            vis[nowx][nowy][to.fx] = 1;
            q.push(to);
        }
        for (int i = 1; i <= 3; i++)
        {
            int j = i, tox = nowx, toy = nowy, flg = 0;
            while (j--)
            {
                tox += dx[nowface];
                toy += dy[nowface];
                if (tox > n + 1 || toy > m + 1 || tox < 1 || toy < 1 || bar[tox][toy])
                {
                    flg = 1;
                    break;
                }
            }
            if (flg)
                continue;
            if (vis[tox][toy][nowface])
                continue;
            vis[tox][toy][nowface] = 1;
            to.x = tox, to.y = toy, to.fx = nowface;
            q.push(to);
        }
    }
    puts("-1");
    return 0;
}