#include <bits/stdc++.h>
const long long maxn = 1e5 + 5;
using namespace std;
long long n;
double p[maxn], x1[maxn], x2[maxn], ans[maxn];
signed main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
        scanf("%lf", &p[i]);
    for (long long i = 1; i <= n; i++)
    {
        x1[i] = (x1[i - 1] + 1) * p[i];
        x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
        ans[i] = ans[i - 1] + (3 * (x1[i - 1] + x2[i - 1]) + 1) * p[i];
    }
    printf("%.1lf", ans[n]);
    return 0;
}