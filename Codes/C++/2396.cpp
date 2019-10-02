#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x) & -(x)
const int maxn = 24;
const int mod = 1e9 + 7;
int num[2], f[1 << maxn] = {1}, dis[1 << maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &dis[1 << i]);
    int m;
    scanf("%d", &m);
    int cnt = 0;
    while (m)
    {
        scanf("%d", &num[cnt]);
        cnt++, m--;
    }
    for (int i = 1; i < (1 << n); i++)
    {
        int t = i, lbt = lowbit(t);
        dis[t] = dis[t ^ lbt] + dis[lbt];
        if (dis[t] == num[0] || dis[t] == num[1])
            continue;
        while (t)
        {
            lbt = lowbit(t);
            f[i] += f[i ^ lbt];
            f[i] %= mod;
            t ^= lbt;
        }
    }
    printf("%d\n", f[(1 << n) - 1]);
    return 0;
}