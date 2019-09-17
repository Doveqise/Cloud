#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int cnt, n, m, p;
int hd[maxn], dis[maxn], vis[maxn], in[maxn];
struct node
{
    int to, wei, nxt;
} ed[maxm];
void add(int x, int y, int z)
{
    ed[++cnt].to = y;
    ed[cnt].wei = z;
    ed[cnt].nxt = hd[x];
    hd[x] = cnt;
}
void spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    queue<int> q;
    q.push(s);
    vis[s] = in[s] = 1;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd[u]; i; i = ed[i].nxt)
        {
            int v = ed[i].to;
            if (dis[v] > dis[u] + ed[i].wei)
            {
                dis[v] = dis[u] + ed[i].wei;
                if (!vis[v])
                {
                    vis[v] = 1;
                    in[v]++;
                    if (in[v] > n)
                    {
                        puts("-1");
                        exit(0);
                    }
                    q.push(v);
                }
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1, a, b, c; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    for (int i = 1, a, b, c; i <= p; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(b, a, -c);
    }
    for (int i = 1; i <= n; i++)
        add(0, i, 0);
    spfa(0);
    spfa(1);
    if (dis[n] == inf)
        puts("-2");
    else
        printf("%d\n", dis[n]);
    return 0;
}
