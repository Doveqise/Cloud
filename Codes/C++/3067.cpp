#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int w[35], hd[maxn], val[maxn];
bool vis[maxn >> 2];
struct edge
{
    int nxt, val;
    // bool operator<(const edge b) const
    // {
    //     return val < b.val;
    // }
} ed[maxn >> 1], e[maxn >> 4];
bool cmp(edge a, edge b)
{
    return a.val < b.val;
}
int n, mid, tot1, tot2, ans, lim;
void dfs1(int dep, int sum, int pos)
{
    if (dep > mid)
    {
        ed[++tot1].nxt = hd[pos];
        ed[tot1].val = sum;
        hd[pos] = tot1;
        return;
    }
    dfs1(dep + 1, sum, pos);
    dfs1(dep + 1, sum + w[dep], pos | (1 << (dep - 1)));
    dfs1(dep + 1, sum - w[dep], pos | (1 << (dep - 1)));
    return;
}
void dfs2(int dep, int sum, int pos)
{
    if (dep > n)
    {
        e[++tot2].nxt = pos;
        e[tot2].val = sum;
        return;
    }
    dfs2(dep + 1, sum, pos);
    dfs2(dep + 1, sum + w[dep], pos | (1 << (dep - 1)));
    dfs2(dep + 1, sum - w[dep], pos | (1 << (dep - 1)));
    return;
}
signed main()
{
    scanf("%d", &n);
    mid = (1 + n) >> 1, lim = (1 << n) - 1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    dfs1(1, 0, 0);
    dfs2(mid + 1, 0, 0);
    sort(e + 1, e + tot2 + 1, cmp);
    for (int i = 0; i <= (1 << mid); i++)
    {
        int cnt = 0;
        for (int j = hd[i]; j; j = ed[j].nxt)
            val[++cnt] = ed[j].val;
        sort(val + 1, val + 1 + cnt);
        int pos = 1;
        if (val[1] > e[tot2].val)
            break;
        for (int j = 1; j <= tot2; j++)
        {
            while (pos <= cnt && val[pos] < e[j].val)
                pos++;
            if (pos > cnt)
                break;
            if (val[pos] == e[j].val)
                vis[i | e[j].nxt] = 1;
        }
    }
    for (int i = 1; i <= lim; i++)
        if (vis[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}