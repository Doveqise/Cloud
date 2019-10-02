#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e3 + 5;
int val[maxn], w[maxn], mp[maxm][maxm], f[maxn], tot;
int main()
{
    int n, m, TI, A;
    scanf("%d%d%d%d", &n, &m, &TI, &A);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &mp[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1, opt; j <= m; j++)
        {
            scanf("%d", &opt);
            int t = 1, wei = 2 * (i + j);
            if (mp[i][j])
            {
                while (opt >= t)
                {
                    w[++tot] = t * wei, val[tot] = t * mp[i][j];
                    opt -= t, t <<= 1;
                }
                w[++tot] = wei * opt, val[tot] = opt * mp[i][j];
            }
        }
    int lim = min(TI, A - 1);
    for (int i = 1; i <= tot; i++)
        for (int j = lim; j >= 0; j--)
            if (j >= w[i])
                f[j] = max(f[j], f[j - w[i]] + val[i]);
    printf("%d\n", f[lim]);
    return 0;
}