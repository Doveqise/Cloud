#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int num[maxn], vis[maxn][maxn], f[maxn][maxn];
signed main()
{
    memset(f, 0x7f, sizeof(f));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (int i = 0, cnt; i <= n; i++)
    {
        cnt = 0;
        for (int j = i; j <= n; j++)
        {
            if (num[j] + i != j)
                cnt++;
            vis[i][j] = cnt;
        }
    }
    f[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = i + 1; k <= n; k++)
                if (f[k][j] > f[i][j - 1] + vis[i + 1][k])
                    f[k][j] = f[i][j - 1] + vis[i + 1][k];
    for (int i = 1; i <= n; i++)
        printf("%d\n", f[n][i]);
    return 0;
}