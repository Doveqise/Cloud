#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
ll n, s, a[210], ans = INF;
ll mp[110][110], f[110][8];
ll min(ll a, ll b) 
{ 
    return a < b ? a : b; 
}
int main()
{
    int i, j, k, t;
    scanf("%d %d", &n, &s);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }
    for (t = 1; t <= n; t++)
    {
        memset(f, 0, sizeof(f));
        memset(mp, 0, sizeof(mp));
        for (i = t; i <= n + t - 1; i++)
            for (j = i + 1; j <= n + t - 1; j++)
                mp[i - t + 1][j - t + 1] = mp[i - t + 1][j - t] + a[j] * (j - i);
        for (i = 1; i <= n; i++)
            f[i][1] = mp[1][i];
        for (i = 1; i <= n; i++)
            for (j = 2; j <= min(i, s); j++)
            {
                f[i][j] = INF;
                for (k = j; k < i; k++)
                    f[i][j] = min(f[i][j], f[k][j - 1] + mp[k + 1][i]);
            }
        ans = min(ans, f[n][s]);
    }
    printf("%d", ans);
    return 0;
}