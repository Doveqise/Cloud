#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e6 + 5;
int f[maxn], vis[maxn];
signed main()
{
    int n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 1, x, y, a, b; i <= k; i++)
    {
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        for (int j = 1; j <= y; j++)
            f[(a * j + b) % n] += x;
    }
    int nowcow = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        nowcow += f[i % n];
        f[i % n] = 0;
        if (!vis[i % n])
            if (nowcow)
            {
                nowcow--;
                vis[i % n]++;
            }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            printf("%lld\n", i);
            return 0;
        }
}