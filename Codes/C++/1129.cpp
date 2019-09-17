#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
int T, n, mat[maxn][maxn], p[maxn];
bool vis[maxn];
bool match(int x)
{
    for (int j = 1; j <= mat[x][0]; j++)
        if (!vis[mat[x][j]])
        {
            vis[mat[x][j]] = 1;
            if (!p[mat[x][j]] || match(p[mat[x][j]]))
            {
                p[mat[x][j]] = x;
                return 1;
            }
        }
    return 0;
}
signed main()
{
    scanf("%d", &T);
    bool flg;
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            p[i] = mat[i][0] = 0;
            for (int j = 1; j <= n; j++)
            {
                int t;
                scanf("%d", &t);
                if (t)
                    mat[i][++mat[i][0]] = j;
            }
        }
        flg = 1;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (!match(i))
            {
                puts("No");
                flg = 0;
                break;
            }
        }
        if (flg)
            puts("Yes");
    }
    return 0;
}