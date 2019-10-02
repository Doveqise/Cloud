#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
uint n, m, a, b, c, tot, vis[maxn];
ull ans = 0x3f3f3f3f3f3f3f;
struct edge
{
    int hd, to, nxt, beg, end;
} ed[maxn << 1];
void dfs(int pos, ull res, ull dep)
{
    if (dep + res >= ans)
        return;
    if (pos == n)
    {
        ans = min(dep + res, ans);
        return;
    }
    vis[pos]++;
    for (int i = ed[pos].hd; i; i = ed[i].nxt)
        if (ed[i].beg >= res && vis[ed[i].to] < 2)
        {
            int k = ed[i].beg - res;
            dfs(ed[i].to, ed[i].end, dep + a * k * k + b * k + c);
        }
    vis[pos]--;
}
signed main()
{
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    for (uint i = 1, u, v, p, q; i <= m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &p, &q);
        ed[++tot] = (edge){0, v, ed[u].hd, p, q};
        ed[u].hd = tot;
    }
    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}