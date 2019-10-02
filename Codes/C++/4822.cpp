#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 5e6 + 5;
typedef pair<int, int> pii;
struct edge
{
    int to, nxt, val;
} ed[maxn << 2];
int cnt, hd[maxn], dis[maxn], vis[maxn];
void add(int x, int y, int z = 0)
{
    ed[++cnt] = (edge){y, hd[x], z};
    hd[x] = cnt;
}
void dijistra(int u)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0, u));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (!vis[u])
        {
            vis[u] = 1;
            for (int i = hd[u]; i; i = ed[i].nxt)
            {
                int to = ed[i].to;
                if (dis[to] > dis[u] + ed[i].val)
                {
                    dis[to] = dis[u] + ed[i].val;
                    q.push(make_pair(dis[to], to));
                }
            }
        }
    }
}
signed main()
{
    int n, m, k, s, t;
    scanf("%d%d%d", &n, &m, &k);
    s = 1, t = n;
    for (int i = 1, u, v, c; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
        add(v, u, c);
        for (int j = 1; j <= k; j++)
        {
            add(u + (j - 1) * n, v + j * n, c / 2);
            add(v + (j - 1) * n, u + j * n, c / 2);
            add(u + j * n, v + j * n, c);
            add(v + j * n, u + j * n, c);
        }
    }
    for (int i = 1; i <= k; i++)
        add(t + (i - 1) * n, t + i * n);
    dijistra(s);
    printf("%d\n", dis[t + k * n]);
    return 0;
}