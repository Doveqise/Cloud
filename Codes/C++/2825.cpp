#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int m, n, tot = 1, tag1[N][N], tag2[N][N], g[N * N][N * N], mat[N * N << 2];
char mp[N][N];
bool f[N * N];
bool match(int u)
{
    for (int i = 1; i <= g[u][0]; i++)
    {
        int v = g[u][i];
        if (!f[v])
        {
            f[v] = 1;
            if (!mat[v] || match(mat[v]))
            {
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= m)
        {
            if (mp[i][j] == '#')
            {
                if (j != 1)
                    tot++;
            }
            else
                tag1[i][j] = tot;
            j++;
        }
        tot++;
    }
    int ma = tot - 1;
    for (int j = 1; j <= m; j++)
    {
        int i = 1;
        while (i <= n)
        {
            if (mp[i][j] == '#')
            {
                if (i != -1)
                    tot++;
            }
            else
                tag2[i][j] = tot;
            i++;
        }
        tot++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '*')
                g[tag1[i][j]][++g[tag1[i][j]][0]] = tag2[i][j];
    int ans = 0;
    for (int i = 1; i <= ma; i++)
    {
        memset(f, 0, sizeof(f));
        if (match(i))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}