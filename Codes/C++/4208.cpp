#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int maxm = 1e3 + 5;
const int mod = 31011;
int n, m, cnt, sum;
int l[maxm], r[maxm], c[maxm], fa[maxn];
struct edge
{
    int frm, to, val;
    bool operator<(const edge b) const
    {
        return val < b.val;
    }
} ed[maxm];

int findfa(int x)
{
    return fa[x] == x ? x : findfa(fa[x]);
}
void dfs(int ti, int u, int num)
{
    if (ti > r[u])
    {
        sum += (num == c[u]);
        return;
    }
    int fau = findfa(ed[ti].frm), fav = findfa(ed[ti].to);
    if (fau != fav)
    {
        fa[fau] = fav;
        dfs(ti + 1, u, num + 1);
        fa[fau] = fau;
        fa[fav] = fav;
    }
    dfs(ti + 1, u, num);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &ed[i].frm, &ed[i].to, &ed[i].val);
    sort(ed + 1, ed + 1 + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        if (ed[i].val != ed[i - 1].val)
        {
            r[cnt] = i - 1;
            l[++cnt] = i;
        }
        int fau = findfa(ed[i].frm), fav = findfa(ed[i].to);
        if (fau != fav)
        {
            ++c[cnt];
            fa[fau] = fav;
            ++tot;
        }
    }
    r[cnt] = m;
    if (tot != n - 1)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int ans = 1;
    for (int i = 1; i <= cnt; i++)
    {
        sum = 0;
        dfs(l[i], i, 0);
        ans = ans * sum % mod;
        for (int j = l[i]; j <= r[i]; ++j)
            fa[findfa(ed[j].frm)] = findfa(ed[j].to);
    }
    printf("%d\n", ans);
    return 0;
}