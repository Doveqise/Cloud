#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int v[maxn], h[maxn], h1[maxn], f[maxn], f1[maxn];
signed main()
{
    int n, t, k;
    scanf("%d%d%d", &n, &t, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &h[i]);
    for (int i = 1; i <= n; i++)
        h1[i] = h[i] * 4 / 5;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= t; j++)
            if (j + h[i] <= t)
                f[j + h[i]] = max(f[j + h[i]], f[j] + v[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= t; j++)
            if (j + h1[i] <= t)
                f1[j + h1[i]] = max(f1[j + h1[i]], f1[j] + v[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (h[i] >= k)
            for (int j = t; j; j--)
                if (j >= h[i])
                    ans = max(ans, f1[j - h[i]] + v[i]);
    printf("%d\n", max(ans, f[t]));
    return 0;
}