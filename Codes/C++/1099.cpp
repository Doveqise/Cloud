#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int inf = 0x7fffffff;
typedef pair<int, int> pii;
vector<pii> e[maxn];
int dis[maxn], vis[maxn], fa[maxn];
int n, m, s, ans = inf;
void dfs(int u)
{
    int siz = e[u].size() - 1;
    for (int i = 0; i <= siz; i++)
    {
        int v = e[u][i].first;
        if (vis[v] || fa[u] == v)
            continue;
        fa[v] = u;
        dis[v] = dis[u] + e[u][i].second;
        dfs(v);
    }
    return;
}
signed main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1, u, v, w; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back((pii){v, w});
        e[v].push_back((pii){u, w});
    }
    int l = 1, ll = 1;
    dis[l] = 0;
    dfs(l);
    memset(fa, 0, sizeof(fa));
    for (int i = 1; i <= n; i++)
        if (dis[i] > dis[l])
            l = i;
    dis[l] = 0;
    dfs(l);
    for (int i = 1; i <= n; i++)
        if (dis[i] > dis[ll])
            ll = i;
    int t = ll;
    for (int i = ll; i; i = fa[i])
    {
        while (fa[t] && dis[i] <= dis[fa[t]] + s)
            t = fa[t];
        ans = min(ans, max(dis[t], dis[ll] - dis[i]));
    }
    for (int i = ll; i; i = fa[i])
        vis[i] = 1;
    for (int i = ll; i; i = fa[i])
    {
        dis[i] = 0;
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dis[i]);
    printf("%d\n", ans);
    return 0;
}
