#include <bits/stdc++.h>
#define R register
#define N 100005
#define ll long long
using namespace std;
const ll inf = 0x7ffffffffffff - 233;
int n, m, h[N], nxt[N << 1], to[N << 1], fath[N], fa[N][19], cnt = 1, rt, dep[N];
bool usd[N * 3];
ll maxn[N][19], minn[N][19], w[N], a, b, c, ans, delt = inf;
struct edge
{
    int fro, to;
    ll len;
} e[N * 3];
bool cmp(edge a, edge b)
{
    return a.len < b.len;
}
ll ret;
char ch;
inline ll read()
{
    ret = 0;
    ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}
inline void add(int u, int v, ll ww)
{
    cnt++;
    nxt[cnt] = h[u];
    h[u] = cnt;
    to[cnt] = v;
    w[cnt] = ww;
    cnt++;
    nxt[cnt] = h[v];
    h[v] = cnt;
    to[cnt] = u;
    w[cnt] = ww;
}
int find(int x) { return x == fath[x] ? x : fath[x] = find(fath[x]); }
inline void kruskal()
{
    for (R int i = 1; i <= m; i++)
    {
        int u = e[i].fro, v = e[i].to;
        int f1 = find(u), f2 = find(v);
        if (f1 ^ f2)
        {
            rt = u;
            fath[f1] = f2;
            usd[i] = 1;
            add(u, v, e[i].len);
            ans += e[i].len;
        }
    }
}
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    for (int i = h[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != f)
        {
            maxn[v][0] = w[i];
            fa[v][0] = u;
            dfs(v, u);
        }
    }
}
inline void predown()
{
    for (R int i = 1; (1 << i) <= n; i++)
    {
        for (R int j = 1; j <= n; j++)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            maxn[j][i] = max(maxn[j][i - 1], maxn[fa[j][i - 1]][i - 1]);
            minn[j][i] = max(minn[j][i - 1], minn[fa[j][i - 1]][i - 1]);
            if (maxn[j][i - 1] < maxn[fa[j][i - 1]][i - 1])
            {
                minn[j][i] = max(maxn[j][i - 1], minn[j][i]);
            }
            else if (maxn[j][i - 1] > maxn[fa[j][i - 1]][i - 1])
            {
                minn[j][i] = max(maxn[fa[j][i - 1]][i - 1], minn[j][i]);
            }
        }
    }
}
inline int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (R int i = 18; i >= 0; i--)
    {
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    }
    if (x == y)
        return x;
    for (R int i = 18; i >= 0; i--)
    {
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
inline ll get(int x, int goal, int lim)
{
    ll anss = -inf;
    for (R int i = 18; i >= 0; i--)
    {
        if (dep[fa[x][i]] >= dep[goal])
        {
            if (maxn[x][i] < lim)
                anss = max(anss, maxn[x][i]);
            else if (minn[x][i] < lim)
                anss = max(anss, minn[x][i]);
            x = fa[x][i];
        }
    }
    return anss;
}
int main()
{
    n = read(), m = read();
    for (R int i = 1; i <= n; i++)
        fath[i] = i;
    for (R int i = 1; i <= m; i++)
    {
        e[i].fro = read(), e[i].to = read(), e[i].len = read();
    }
    sort(e + 1, e + m + 1, cmp);
    kruskal();
    dfs(rt, 0);
    for (R int i = 1; i <= 20; i++)
    {
        for (R int j = 1; j <= n; j++)
        {
            minn[j][i] = -inf;
        }
    }
    predown();
    for (R int i = 1; i <= m; i++)
    {
        if (!usd[i])
        {
            int u = e[i].fro, v = e[i].to;
            int fff = lca(u, v);
            ll maxn = -inf;
            maxn = max(max(maxn, get(u, fff, e[i].len)), get(v, fff, e[i].len));
            delt = min(delt, e[i].len - maxn);
        }
    }
    printf("%lld", ans + delt);
    return 0;
}