#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
struct edge
{
    int frm, to;
    double leng;
    bool operator<(const edge b) const
    {
        return leng < b.leng;
    }
} ed[maxn * maxn];
int fa[maxn], x[maxn], y[maxn], tot;
double a[maxn];
int n, k;
double dis(int x1, int y1, int x2, int y2)
{
    return (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int findfa(int x)
{
    return fa[x] == x ? x : fa[x] = findfa(fa[x]);
}
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[fa[i] = i], &y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            ed[++tot] = (edge){i, j, dis(x[i], y[i], x[j], y[j])};
    sort(ed + 1, ed + 1 + tot);
    int i = 1, j = 0;
    while (j < n - 1)
    {
        int u = findfa(ed[i].frm), v = findfa(ed[i].to);
        double dis = ed[i].leng;
        if (u != v)
        {
            fa[u] = v;
            j++;
            a[j] = dis;
        }
        i++;
    }
    printf("%.2lf", a[n - k + 1]);
    return 0;
}