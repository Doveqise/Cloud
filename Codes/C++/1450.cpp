#include <bits/stdc++.h>
using namespace std;
int c[5], d[5];
const int maxs = 1e5 + 5;
long long ans = 0, f[maxs + 5];
void init()
{
    f[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = c[i]; j <= maxs; j++)
            f[j] += f[j - c[i]];
}
void dfs(int now, int sum, int flg)
{
    if (sum < 0)
        return;
    if (now > 4)
    {
        ans += f[sum] * flg;
        return;
    }
    dfs(now + 1, sum, flg);
    dfs(now + 1, sum - (d[now] + 1) * c[now], -flg);
}
signed main()
{
    for (int i = 1; i <= 4; i++)
        scanf("%d", &c[i]);
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int s;
        ans = 0;
        for (int i = 1; i <= 4; i++)
            scanf("%d", &d[i]);
        scanf("%d", &s);
        dfs(1, s, 1);
        printf("%lld\n", ans);
    }
    return 0;
}