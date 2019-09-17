#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e9+7;
deque<int> q; //优化spfa
bool vis[maxn];
int n, m1, m2, s, dis[maxn];
int cnt = 0, p[maxn << 1], c[maxn << 1], nxt[maxn << 1], hd[maxn << 1];
void addedge(int x, int y, int val)
{
    p[++cnt] = y;
    c[cnt] = val;
    nxt[cnt] = hd[x];
    hd[x] = cnt;
}
void spfa(int x)
{
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    memset(vis, 0, sizeof(vis));
    dis[x] = 0;
    vis[x] = 1;
    q.push_back(x);
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        for (int i = hd[now]; i; i = nxt[i])
            if (dis[p[i]] > dis[now] + c[i])
            {
                dis[p[i]] = dis[now] + c[i];
                if (!vis[p[i]])
                {
                    if (!q.empty() && dis[p[i]] >= dis[q.front()])
                        q.push_back(p[i]);
                    else
                        q.push_front(p[i]);
                    vis[p[i]] = 1;
                }
            }
        vis[now] = 0;
    }
}
signed main()
{
    scanf("%d%d%d%d", &n, &m1, &m2, &s);
    for (int i = 1,x,y,val; i <= m1; i++)
    {
        scanf("%d%d%d", &x, &y, &val);
        addedge(x, y, val);
        addedge(y, x, val);
    }
    for (int i = 1,x,y,val; i <= m2; i++)
    {
        scanf("%d%d%d", &x, &y, &val);
        addedge(x, y, val);
    }
    spfa(s);
    for (int i = 1; i <= n; i++)
        if (dis[i] < inf)
            printf("%d\n", dis[i]);
        else
            puts("NO PATH");
    return 0;
}