#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int maxm = 2e4 + 5;
int s, n, m;
int c[maxn][maxn], w[maxn][maxn], f[maxm];
int main()
{
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[j][i]);
    for (int i = 1; i <= n; ++i)
    {
        sort(c[i] + 1, c[i] + 1 + s);
        for (int j = 1; j <= s; j++)
            c[i][j] = c[i][j] * 2 + 1;
    }
    for (int k = 1; k <= n; k++)
        for (int v = m; v > 0; v--)
            for (int i = 1; i <= s; i++)
                if (v - c[k][i] >= 0 && f[v - c[k][i]] + k * i > f[v])
                    f[v] = f[v - c[k][i]] + k * i;
    printf("%d\n", f[m]);
    return 0;
}