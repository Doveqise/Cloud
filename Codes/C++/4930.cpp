#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int maxm = 1e5;
#define f(a, b) ff[a + maxm][b]
#define g(a, b) gg[a + maxm][b]
#define t(a) tt[a + maxm]
using namespace std;
struct edge
{
    int v, nxt, w;
} ed[maxn];
int hd[maxn], maxs[maxn], siz[maxn], vis[maxn];
long long gg[maxn][2], ff[maxn][2], tt[maxn], ans;
int n, rt, maxx, sum, tot;
void add(int u, int v, int w)
{
    ed[++tot].nxt = hd[u];
    hd[u] = tot;
    ed[tot].v = v;
    ed[tot].w = w;
}
void root(int u, int f)
{
    siz[u] = 1, maxs[u] = 0;
    for (int i = hd[u]; i; i = ed[i].nxt)
    {
        int v = ed[i].v;
        if (v == f || vis[v])
            continue;
        root(v, u);
        siz[u] += siz[v];
        maxs[u] = max(maxs[u], siz[u]);
    }
    maxs[u] = max(maxs[u], sum - siz[u]);
    if (maxs[u] < maxs[rt])
        rt = u;
}
void solve(int u, int dis, int f)
{
    if (t(dis))
        f(dis, 0)++;
    else
        f(dis, 1)++;
    maxx = max(maxx, abs(dis));
    t(dis)++;
    for (int i = hd[u]; i; i = ed[i].nxt)
    {
        int v = ed[i].v;
        if (vis[v] || v == f)
            continue;
        solve(v, dis + ed[i].w, u);
    }
    t(dis)--;
}
void split(int u)
{
    vis[u] = 1;
    int maxw = 0;
    for (int i = hd[u]; i; i = ed[i].nxt)
    {
        int v = ed[i].v;
        if (vis[v])
            continue;
        maxx = 0;
        solve(v, ed[i].w, u);
        maxw = max(maxw, maxx);
        ans += f(0, 0);
        for (int j = -maxx; j <= maxx; j++)
        {
            if (!j)
                ans += f(j, 1) * g(j, 1);
            ans += f(j, 0) * g(-j, 0);
            ans += f(j, 0) * g(-j, 1);
            ans += f(j, 1) * g(-j, 0);
        }
        for (int j = -maxx; j <= maxx; j++)
        {
            g(j, 1) += f(j, 1);
            g(j, 0) += f(j, 0);
            f(j, 0) = f(j, 1) = 0;
        }
    }
    for (int j = -maxw; j <= maxw; j++)
        g(j, 0) = g(j, 1) = 0;
    for (int i = hd[u]; i; i = ed[i].nxt)
    {
        int v = ed[i].v;
        if (vis[v])
            continue;
        sum = siz[v];
        rt = 0;
        maxs[0] = maxn;
        root(v, u);
        split(rt);
    }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1, x, y, z; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (!z)
            z--;
        add(x, y, z);
        add(y, x, z);
    }
    sum = n;
    maxs[0] = maxn;
    root(1, 0);
    split(rt);
    printf("%d\n", ans);
    return 0;
}