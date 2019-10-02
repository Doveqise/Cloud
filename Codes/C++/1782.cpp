#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
long long f[maxn];
signed main()
{
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1, v, w, d; i <= n; i++)
    {
        scanf("%d%d%d", &v, &w, &d);
        if (d * v > c)
            for (int j = v; j <= c; j++)
                f[j] = max(f[j], f[j - v] + w);
        else
        {
            for (int k = 1; k <= d; d -= k, k <<= 1)
                for (int j = c; j >= v * k; j--)
                    f[j] = max(f[j], f[j - v * k] + w * k);
            if (d > 0)
                for (int j = c; j >= v * d; j--)
                    f[j] = max(f[j], f[j - v * d] + w * d);
        }
    }
    for (int i = 1, v, w, d; i <= m; i++)
    {
        scanf("%d%d%d", &v, &w, &d);
        for (int j = c; j >= 0; j--)
            for (int k = 0; k <= j; k++)
                f[j] = max(f[j], f[j - k] + v * k * k * 1ll + w * k * 1ll + d);
    }
    printf("%lld\n", f[c]);
    return 0;
}