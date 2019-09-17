#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
queue<int> q;
int hd[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], f[maxn], dep[maxn], fa[maxn];
bool vis[maxn];
int tot = 1, maxm, cnt = 0, s = 1, t = 1;
void addedge(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = 1;
    nxt[++tot] = hd[y];
    hd[y] = tot;
    to[tot] = x;
    val[tot] = 1;
}
int find(int u)
{
    memset(vis, 0, sizeof(vis));
    fa[u] = 0;
    vis[u] = 1;
    dep[u] = 0;
    int ans = u;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int tmp = hd[u]; tmp; tmp = nxt[tmp])
        {
            int v = to[tmp];
            if (!vis[v])
            {
                fa[v] = u;
                dep[v] = dep[u] + 1;
                if (dep[v] > dep[ans])
                    ans = v;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return ans;
}
void del(int u)
{
    for (int tmp = hd[u]; tmp; tmp = nxt[tmp])
    {
        int v = to[tmp];
        if (v != fa[u])
        {
            if (vis[u] && vis[v])
                val[tmp] = val[tmp ^ 1] = -1;
            del(v);
        }
    }
}
void dfs(int u)
{
    int maxx = 0;
    for (int tmp = hd[u]; tmp; tmp = nxt[tmp])
    {
        int v = to[tmp];
        if (v != fa[u])
        {
            dfs(v);
            maxm = max(maxm, maxx + f[v] + val[tmp]);
            maxx = max(maxx, f[v] + val[tmp]);
        }
    }
    maxm = max(maxm, maxx);
    f[u] = maxx;
}
signed main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    s = find(1);
    t = find(s);
    find(1);
    memset(vis, 0, sizeof(vis));
    if (dep[s] < dep[t])
        swap(s, t);
    vis[s] = vis[t] = 1;
    while (dep[s] > dep[t])
    {
        s = fa[s];
        vis[s] = 1;
        cnt++;
    }
    while (s != t)
    {
        s = fa[s];
        t = fa[t];
        vis[s] = vis[t] = 1;
        cnt += 2;
    }
    if (k == 1)
    {
        printf("%d\n", n * 2 - 1 - cnt);
        return 0;
    }
    if (cnt + 1 == n)
    {
        printf("%d\n", n + 1);
        return 0;
    }
    sign(1);
    dfs(1);
    printf("%d\n", n * 2 - cnt - maxm);
    return 0;
}