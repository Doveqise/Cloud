#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
const int maxm = 1e2 + 5;
int n, m, rt, query[maxm];
int hd[maxn], to[maxn << 1], nxt[maxn << 1], val[maxn << 1], tot, rd[maxn], tmp[10], sum, ans = 0;
int sonv[maxn], siz[maxn], fa[maxn], cnt, dep[maxn], top[maxn], id[maxn], vis[maxn], jud[maxn];
void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
void dfs1(int u)
{
    siz[u] = 1;
    sonv[u] = 0;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u] || vis[v])
            continue;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        sonv[u] = max(sonv[u], siz[v]);
    }
    sonv[u] = max(sonv[u], sum - siz[u]);
    if (sonv[u] < sonv[rt])
        rt = u;
}
void dfs2(int u)
{
    tmp[rd[u]]++;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa[u] || vis[v])
            continue;
        fa[v] = u;
        rd[v] = (rd[u] + val[i]) % 3;
        dfs2(v);
    }
}
int calc(int u, int res)
{
    rd[u] = res;
    tmp[0] = tmp[1] = tmp[2] = fa[u] = 0;
    dfs2(u);
    return tmp[1] * tmp[2] * 2 + tmp[0] * tmp[0];
}
void solve(int u)
{
    vis[u] = 1;
    ans += calc(u, 0);
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v])
            continue;
        ans -= calc(v, val[i]);
        rt = 0;
        sum = siz[v];
        dfs1(v);
        solve(rt);
    }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1, a, b, c; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c % 3);
        add(b, a, c % 3);
    }
    sum = n;
    sonv[0] = n;
    dfs1(1);
    solve(rt);
    int k = gcd(n * n, ans);
    printf("%d/%d\n", ans / k, n * n / k);
    return 0;
}