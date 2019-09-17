#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, m, i, j, a[N], d[N], ans, f[N], k, vi[N][N], c[N][N], l;
int dfs(int x)
{
    if (f[x])
        return f[x];
    for (int i = 1; i <= c[x][0]; i++)
        f[x] = max(f[x], dfs(c[x][i]));
    return ++f[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &a[0]);
        for (j = 1; j <= a[0]; j++)
            scanf("%d", &a[j]);
        l = 1;
        for (j = a[1]; j < a[a[0]]; j++)
            if (a[l] == j)
                l++;
            else
                for (k = 1; k <= a[0]; k++)
                    if (!vi[a[k]][j])
                        c[a[k]][++c[a[k]][0]] = j, vi[a[k]][j] = 1;
    }
    for (i = 1; i <= n; i++)
        ans = max(ans, dfs(i));
    printf("%d", ans);
    return 0;
}