#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
bool f[maxn][maxn];
int ans = 0;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        f[x][y] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (f[i][k] & f[k][j])
                    f[i][j] = 1;
    for (int i = 1; i <= n; i++)
        if (f[i][i])
        {
            printf("-1");
            exit(0);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!f[i][j] && !f[j][i])
                ans++;
    printf("%d", ans - n >> 1);
}