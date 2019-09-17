#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
const int maxm = 2e7 + 5;
int n, m, A, B, cnt;
double dis[maxn], val[maxn];
int vis[maxn], hd[maxn], to[maxn], nxt[maxn];
void add(int x, int y, double z)
{
    nxt[++cnt] = hd[x];
    to[cnt] = y;
    val[cnt] = 1 - z;
    hd[x] = cnt;
}
void spfa()
{
    queue<int> q;
    q.push(A);
    dis[A] = vis[A] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (dis[v] < dis[u] * val[i])
            {
                dis[v] = dis[u] * val[i];
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    memset(dis, 0, sizeof(dis));
    for (int x, y, z, i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, (double)z / 100);
        add(y, x, (double)z / 100);
    }
    scanf("%d%d", &A, &B);
    spfa();
    printf("%.8lf", 100 / dis[B]);
    return 0;
}