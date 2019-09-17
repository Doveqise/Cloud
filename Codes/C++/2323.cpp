#include <bits/stdc++.h>
using namespace std;
const int maxm = 2e4 + 5;
const int maxn = 1e4 + 5;
const int inf = 123456789;
int n, m, k;
int fa[maxn];
int ans = -inf;
pair<int, int> re[maxn];
struct edge
{
    int num, u, v, c1, c2;
} ed[maxn];
bool cmp1(edge a, edge b)
{
    return a.c1 == b.c1 ? a.c2 > b.c2 : a.c1 < b.c1;
}
bool cmp2(edge a, edge b)
{
    return a.c2 < b.c2;
}
bool cmp3(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}
int findfa(int x)
{
    return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}
void kruskal()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int t = 1;
    for (int i = 1; i <= k; i++)
    {
        while (findfa(ed[t].u) == findfa(ed[t].v))
            t++;
        ans = max(ans, ed[t].c1);
        fa[findfa(ed[t].v)] = findfa(ed[t].u);
        re[i].first = ed[t].num;
        re[i].second = 1;
        t++;
    }
    return;
}
signed main()
{
    scanf("%d%d%d", &n, &k, &m);
    m--;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &ed[i].u, &ed[i].v, &ed[i].c1, &ed[i].c2);
        ed[i].num = i;
        if (ed[i].u > ed[i].v)
            swap(ed[i].u, ed[i].v);
    }
    sort(ed + 1, ed + 1 + m, cmp1);
    kruskal();
    printf("%d\n", ans);
    sort(re + 1, re + n, cmp3);
    for (int i = 1; i < n; i++)
        printf("%d %d\n", re[i].first, re[i].second);
    return 0;
}