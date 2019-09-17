#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, maxm = 1e3 + 5;
const int mod = 31011;
int n, m, tot, fa[maxn], a[maxn][maxn], bel[maxn], val[maxn];
struct Edge
{
    int u, v, w;
    bool operator<(const Edge &b) const
    {
        return w < b.w;
    }
} e[maxm], tr[maxn];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void init()
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
void add(int u, int v)
{
    --a[u][v], --a[v][u], ++a[u][u], ++a[v][v];
}
void merge(int x, int y)
{
    fa[find(x)] = find(y);
}
int Gauss(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = i + 1; k <= n; ++k)
        {
            while (a[k][i])
            {
                int d = a[i][i] / a[k][i];
                for (int j = i; j <= n; ++j)
                    a[i][j] = (a[i][j] - 1LL * d * a[k][j] % mod + mod) % mod;
                swap(a[i], a[k]), ans = -ans;
            }
        }
        ans = 1LL * ans * a[i][i] % mod, ans = (ans + mod) % mod;
    }
    return ans;
}
bool kruskal()
{
    sort(e + 1, e + m + 1);
    init();
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu == fv)
            continue;
        fa[fu] = fv, tr[++cnt] = e[i];
        if (e[i].w != val[tot])
            val[++tot] = e[i].w;
    }
    return cnt == n - 1;
}
void addedge(int v)
{
    for (int i = 1; i < n && tr[i].w != v; ++i)
        merge(tr[i].u, tr[i].v);
    for (int i = n - 1; i && tr[i].w != v; --i)
        merge(tr[i].u, tr[i].v);
}
int getblock()
{
    int blo = 0;
    for (int i = 1; i <= n; ++i)
        if (find(i) == i)
            bel[i] = ++blo;
    for (int i = 1; i <= n; ++i)
        bel[i] = bel[find(i)];
    return blo;
}
void rebuild(int v)
{
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; ++i)
        if (e[i].w == v)
            add(bel[e[i].u], bel[e[i].v]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    if (!kruskal())
    {
        puts("0");
        return 0;
    }
        return puts("0"), 0;
    int ans = 1;
    for (int i = 1; i <= tot; ++i)
    {
        init();
        addedge(val[i]);
        int blo = getblock();
        rebuild(val[i]);
        ans = 1LL * ans * Gauss(blo - 1) % mod;
    }
    printf("%d\n", ans);
    return 0;
}