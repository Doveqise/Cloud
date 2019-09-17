#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m, ans, cnt = 1;
int f[maxn], w[maxn], v[maxn];
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b, c; i <= n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        for (int j = 1; j <= c; j <<= 1)
        {
            v[++cnt] = j * a;
            w[cnt] = j * b;
            c -= j;
        }
        if (c > 0)
        {
            v[++cnt] = a * c;
            w[cnt] = b * c;
        }
    }
    for (int i = 1; i <= cnt; ++i)
        for (int j = m; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    printf("%d\n", f[m]);
    return 0;
}