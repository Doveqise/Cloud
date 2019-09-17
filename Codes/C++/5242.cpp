#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
double t1 = 1, t2 = 0, ans = 0, p[maxn];
signed main()
{
    int n, t, i;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%lf", &p[i]);
        p[i] /= (1e6 * 1.0);
        ans = max(ans, p[i]);
    }
    t = 1;
    for (i = 1; i <= n; ++i)
    {
        while (t <= n && t1 * t2 < t1 * (1 - p[t]) * (t2 + p[t] / (1 - p[t])))
        {
            t1 *= (1 - p[t]);
            t2 += p[t] / (1 - p[t]);
            ++t;
        }
        ans = max(ans, t1 * t2);
        t1 /= (1 - p[i]);
        t2 -= p[i] / (1 - p[i]);
    }
    printf("%d\n", (int)(ans * 1e6));
    return 0;
}