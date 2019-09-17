#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int f[maxn][maxn], l[maxn];
int n, m, x, y, ans = maxn * maxn;
bool gauss()
{
    bool flg = 1;
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        while (k <= n && !f[k][i])
            k++;
        if (k > n)
        {
            flg = 0;
            continue;
        }
        swap(f[i], f[k]);
        for (int j = 1; j <= n; j++)
        {
            if (i == j || !f[j][i])
                continue;
            for (int k = i + 1; k <= n + 1; k++)
                f[j][k] ^= f[i][k];
            f[j][i] = 0;
        }
    }
    return flg;
}
void dfs(int u, int sum)
{
    if (sum >= ans)
        return;
    if (!u)
    {
        ans = sum;
        return;
    }
    if (f[u][u])
    {
        bool v = f[u][n + 1];
        for (int i = u + 1; i <= n; i++)
            if (f[u][i])
                v ^= l[i];
        dfs(u - 1, sum + v);
    }
    else
    {
        dfs(u - 1, sum);
        l[u] = 1;
        dfs(u - 1, sum + 1);
        l[u] = 0;
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i][i] = f[i][n + 1] = 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        f[x][y] = f[y][x] = 1;
    }
    if (gauss())
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += f[i][n + 1];
        printf("%d", ans);
    }
    else
    {
        dfs(n, 0);
        printf("%d\n", ans);
    }
    return 0;
}