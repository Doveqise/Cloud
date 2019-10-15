#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int inf = 1e9 + 9;
int dis[maxn][maxn];
signed main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                scanf("%d", &dis[i][j]);
        int ans = dis[1][2];
        for (int i = 3; i <= n; i++)
        {
            int t = inf;
            for (int j = 2; j < i; j++)
                t = min(t, dis[1][i] - dis[1][j] + dis[j][i] >> 1);
            ans += t;
        }
        printf("%d\n", ans);
    }
    return 0;
}