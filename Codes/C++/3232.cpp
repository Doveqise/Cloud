#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
const int maxm = 5e5 + 5;
int hd[maxn], deg[maxn], to[maxm], nxt[maxm], sta[maxm], fin[maxm];
double a[maxn][maxn], b[maxn], x[maxn], f[maxm];
int n, m, cnt;
void add(int a, int b)
{
    to[++cnt] = b;
    nxt[cnt] = hd[a];
    hd[a] = cnt;
}
void Gauss(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int p = i;
        for (int k = i + 1; k <= n; k++)
            if (fabs(a[k][i] > fabs(a[p][i])))
                p = k;
        if (i != p)
        {
            swap(a[i], a[p]);
            swap(b[i], b[p]);
        }
        for (int k = i + 1; k <= n; k++)
        {
            double d = a[k][i] / a[i][i];
            b[k] -= d * b[i];
            for (int j = 1; j <= n; j++)
                a[k][j] -= d * a[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
            b[i] -= x[j] * a[i][j];
        x[i] = b[i] / a[i][i];
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &sta[i], &fin[i]);
        add(sta[i], fin[i]);
        add(fin[i], sta[i]);
        ++deg[sta[i]];
        ++deg[fin[i]];
    }
    for (int u = 1; u < n; u++)
    {
        a[u][u] = 1.0;
        for (int i = hd[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (v != n)
                a[u][v] = -1.0 / deg[v];
        }
    }
    b[1] = 1;
    Gauss(n - 1);
    for (int i = 1; i <= m; i++)
    {
        int a = sta[i], b = fin[i];
        if (a != n)
            f[i] += x[a] / deg[a];
        if (b != n)
            f[i] += x[b] / deg[b];
    }
    sort(f + 1, f + 1 + m);
    double ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (m - i + 1) * f[i];
    printf("%.3lf\n", ans);
    return 0;
}