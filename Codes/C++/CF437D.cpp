#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
typedef long long ll;
ll n, m, ans;
int val[maxn], s[maxn], fa[maxn], siz[maxn];
int hd[maxn], tot, vis[maxn];
struct edge
{
    int nxt, to;
} ed[maxm << 1];
int findfa(int x)
{
    return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}
bool cmp(int a, int b)
{
    return val[a] > val[b];
}
void addedge(int x, int y)
{
    ed[++tot] = (edge){hd[x], y};
    hd[x] = tot;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; siz[i] = 1, i++)
        scanf("%d", &val[s[i] = fa[i] = i]);
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1, a, b; i <= m; i++)
    {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    for (int u = 1; u <= n; u++)
    {
        ll res = 0;
        for (int i = hd[s[u]]; i; i = ed[i].nxt)
        {
            int v = ed[i].to;
            if (!vis[v])
                continue;
            int p = findfa(s[u]), q = findfa(v);
            if (p == q)
                continue;
            res += 1ll * siz[p] * siz[q];
            fa[p] = q;
            siz[q] += siz[p];
        }
        ans += 1ll * res * val[s[u]];
        vis[s[u]] = 1;
    }
    printf("%lf\n", ans * 2.0 / (n * (n - 1)));
    return 0;
}