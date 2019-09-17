#include <bits/stdc++.h>
using namespace std;
const int mod = 10;
const int maxn = 2e2 + 5;
int v[maxn], g[maxn], f[maxn] = {1}, n, m;
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = (f[j] + f[j - v[i]]) % mod;
    for (int t = 1; t <= n; t++)
    {
        for (int i = 0; i < maxn; i++)
            g[i] = f[i];
        for (int i = v[t]; i <= m; i++)
            g[i] = ((g[i] - g[i - v[t]]) % mod + mod) % mod;
        for (int j = 1; j <= m; j++)
            printf("%d", g[j]);
        printf("\n");
    }
}