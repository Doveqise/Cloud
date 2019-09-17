#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 2e5 + 5, inf = 1e9 + 7;
int n, m, s, t, ans, d[N];
int head[N], edge[M], len[M], nxt[M], tot = 1;
void add_edge(int x, int y, int z)
{
    edge[++tot] = y;
    len[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}
bool bfs()
{
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = edge[i], z = len[i];
            if (d[y] || !z)
                continue;
            q.push(y);
            d[y] = d[x] + 1;
            if (y == t)
                return 1;
        }
    }
    return 0;
}
int dinic(int x, int flow)
{
    if (x == t)
        return flow;
    int rest = flow;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = edge[i], z = len[i];
        if (d[y] != d[x] + 1 || !z)
            continue;
        int k = dinic(y, min(rest, z));
        if (!k)
            d[y] = 0;
        else
        {
            len[i] -= k;
            len[i ^ 1] += k;
            rest -= k;
        }
    }
    return flow - rest;
}
signed main()
{
    scanf("%d%d", &m, &n);
    s = 1, t = n;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z);
        add_edge(y, x, 0);
    }
    int now = 0;
    while (bfs())
        while (now = dinic(s, inf))
            ans += now;
    printf("%d\n", ans);
    return 0;
}