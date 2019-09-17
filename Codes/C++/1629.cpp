#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
int dis[maxn], vis[maxn], ans[maxn];
int n, m, s, x, anss;
struct form
{
    vector<int> ed, wei;
    int num;
} F[maxm];
struct cmp
{
    bool operator()(int a, int b)
    {
        return dis[a] > dis[b];
    }
};
priority_queue<int, vector<int>, cmp> q;
void solve(int s)
{
    q.push(s);
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 0;
        for (int i = 1; i <= F[u].num; i++)
        {
            int v = F[u].ed[i];
            if (dis[v] > dis[u] + F[u].wei[i])
            {
                dis[v] = dis[u] + F[u].wei[i];
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return;
}
signed main()
{
    scanf("%d%d", &n, &m);
    x = 1;
    for (int i = 1; i <= m; i++)
        F[i].ed.push_back(0), F[i].wei.push_back(0);
    for (int i = 1, a, b, c; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        F[a].num++;
        F[a].ed.push_back(b);
        F[a].wei.push_back(c);
    }
    for (int i = 1; i <= n; i++)
        if (i != x)
            dis[i] = 2147483647;
    solve(x);
    for (int i = 1; i <= n; i++)
        ans[i] = dis[i];
    for (s = 1; s <= n; s++)
    {
        if (s == x)
            continue;
        dis[s] = 0;
        for (int i = 1; i <= n; i++)
            if (i != s)
                dis[i] = 2147483647;
        solve(s);
        ans[s] += dis[x];
    }
    for (int i = 1; i <= n; i++)
        anss+=ans[i];
    printf("%d", anss);
    return 0;
}