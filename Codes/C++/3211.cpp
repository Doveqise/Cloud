#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int deg[maxn], hd[maxn], f[maxn][maxn];
double a[maxn][maxn], ans = 0;
int n, m, cnt;
struct edge
{
    int to, nxt, wei;
} ed[maxn * maxn << 1];
void add(int x, int y, int z)
{
    ed[++cnt].to = y;
    ed[cnt].nxt = hd[x];
    ed[cnt].wei = z;
    hd[x] = cnt;
}
int get(int x, int i)
{
    return (x & (1 << (i - 1))) >> (i - 1);
}
void Gauss(int t)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            a[i][j] = 0;
    for (int i = 1; i < n; i++)
    {
        a[i][i] = 1;
        for (int j = hd[i]; j; j = ed[j].nxt)
        {
            int v = ed[j].to;
            if (get(ed[j].wei, t) == 1)
                a[i][v] += (double)1 / deg[i], a[i][n + 1] += (double)1 / deg[i];
            else
                a[i][v] -= (double)1 / deg[i];
        }
    }
    a[n][n] = 1;
    for (int i = 1; i <= n; i++)
    {
        int p = i;
        while (!a[p][i])
            ++p;
        for (int j = 1; j <= n + 1; j++)
            swap(a[i][j], a[p][j]);
        for (int j = 1; j <= n; j++)
            if (j != i)
            {
                double r = a[j][i] / a[i][i];
                for (int k = 1; k <= n + 1; k++)
                    a[j][k] -= a[i][k] * r;
            }
    }
    ans += a[1][n + 1] / a[1][1] * (1 << (t - 1));
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        deg[u]++;
        if (u != v)
        {
            deg[v]++;
            add(v, u, w);
        }
    }
    for (int i = 1; i <= 31; i++)
        Gauss(i);
    printf("%.3lf\n", ans);
    return 0;
}