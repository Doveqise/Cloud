#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
long long ans = 0, n, v[maxn], x[maxn];
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &v[i], &x[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += abs(x[i] - x[j]) * max(v[i], v[j]);
    printf("%lld\n", ans);
    return 0;
}