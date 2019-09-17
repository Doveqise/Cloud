#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, sx, sy, tx, ty;
struct Node
{
    int x, y, s;
};
deque<Node> q;
int dis[maxn][maxn];
char s[maxn][maxn];
void bfs()
{
    q.push_back((Node){sx, sy, 0});
    while (!q.empty())
    {
        Node p = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int wx = p.x + dx[i], wy = p.y + dy[i];
            int w = (s[wx][wy] != s[p.x][p.y]);
            if (dis[wx][wy] > dis[p.x][p.y] + w && (wx > 0 && wy > 0 && wx <= n && wy <= m))
                dis[wx][wy] = dis[p.x][p.y] + w,
                w == 1 ? q.push_back((Node){wx, wy, w}) : q.push_front((Node){wx, wy, w});
        }
    }
}
signed main()
{
    while (scanf("%d%d", &n, &m) && n && m)
    {
        memset(dis, 0xf, sizeof(dis));
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        sx++, sy++, tx++, ty++;
        dis[sx][sy] = 0;
        bfs();
        printf("%d\n", dis[tx][ty]);
    }
    return 0;
}