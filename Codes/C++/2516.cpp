#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 1e8;
char s1[maxn], s2[maxn];
int f[2][maxn], g[2][maxn];
signed main()
{
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1) - 1, m = strlen(s2 + 1) - 1;
    for (int i = 0; i <= m; i++)
        g[0][i] = 1;
    g[1][0] = 1;
    int now = 1, pre = 0;
    for (int i = 1; i <= n; i++, now ^= 1, pre ^= 1)
        for (int j = 1; j <= m; j++)
        {
            f[now][j] = max(f[pre][j], f[now][j - 1]);
            g[now][j] = 0;
            if (s1[i] == s2[j])
                f[now][j] = max(f[now][j], f[pre][j - 1] + 1);
            if (s1[i] == s2[j] && f[now][j] == f[pre][j - 1] + 1)
                g[now][j] += g[pre][j - 1];
            if (f[pre][j] == f[now][j])
                g[now][j] += g[pre][j];
            if (f[now][j - 1] == f[now][j])
                g[now][j] += g[now][j - 1];
            if (f[pre][j - 1] == f[now][j])
                g[now][j] -= g[pre][j - 1];
            g[now][j] = (g[now][j] + mod) % mod;
        }
    printf("%d\n%d\n", f[pre][m], g[pre][m]);
}