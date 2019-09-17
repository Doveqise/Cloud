#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int pos[maxn], spd[maxn];
long long n, t;
signed main()
{
    scanf("%lld%lld", &n, &t);
    long long ans = n;
    for (long long i = 1; i <= n; i++)
        scanf("%d%d", &pos[i], &spd[i]);
    long long now = n;
    for (long long i = n - 1; i >= 1; i--)
        if ((spd[i] - spd[now]) * t >= pos[now] - pos[i])
            ans--;
        else
            now = i;
    printf("%lld", ans);
    return 0;
}