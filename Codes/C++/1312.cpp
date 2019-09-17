#include <bits/stdc++.h>
using namespace std;
int vis[10][10], flg[11], mp[10][10], dep[10][5], cnt[11];
int n, N;
int calc()
{
    memset(vis, 1, sizeof(vis));
    int res = 0, fal = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (mp[i][j])
                if ((j >= 2 && mp[i][j - 1]) || j == 1)
                {
                    int l = i, r = i, u = j, d = j;
                    while (l >= 2 && mp[l - 1][j] == mp[i][j])
                        l--;
                    while (r < 4 && mp[r + 1][j] == mp[i][j])
                        r++;
                    while (d >= 2 && mp[i][d - 1] == mp[i][j])
                        d--;
                    while (u <= 6 && mp[i][u + 1] == mp[i][j])
                        u++;
                    if (r - l >= 2)
                        for (int k = l; k <= r; k++)
                            vis[k][j] = 0;
                    if (u - d >= 2)
                        for (int k = d; k <= u; k++)
                            vis[i][k] = 0;
                }
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (!vis[i][j])
                res++, mp[i][j] = 0;
    for (int i = 1, j; i <= 5; i++)
    {
        for (j = 1; j <= 7; j++)
            if (!mp[i][j])
                break;
        int x = j;
        for (; j <= 7; j++)
            if (mp[i][j])
                break;
        if (j == 8)
            continue;
        int y = j - 1, t = 0;
        for (j = x; j <= 7; j++)
        {
            t++;
            if (!mp[i][y + t] || mp[i][j])
                break;
            mp[i][j] = mp[i][y + t];
            mp[i][y + t] = 0;
            fal = 1;
        }
    }
    if (fal)
        res += calc();
    return res;
}
bool judge()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            cnt[mp[i][j]]++;
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 1 || cnt[i] == 2)
            return 0;
    return 1;
}
void dfs(int u, int tot)
{
    if (!judge())
        return;
    if (u >= n + 1)
    {
        if (!tot)
        {
            for (int i = 1; i <= n; i++)
                printf("%d %d %d\n", dep[i][1] - 1, dep[i][2] - 1, dep[i][3]);
            exit(0);
        }
        return;
    }
    int tmp[10][10], p, q, fal;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            tmp[i][j] = mp[i][j];
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (mp[i][j])
            {
                fal = 1;
                if (i <= 4 && mp[i][j] != mp[i + 1][j])
                {
                    swap(mp[i][j], mp[i + 1][j]);
                    dep[u][1] = i, dep[u][2] = j, dep[u][3] = 1;
                    p = tot - calc();
                    dfs(u + 1, p);
                    fal = 0;
                }
                if (!fal)
                    for (fal = 1, p = 1; p <= 5; p++)
                        for (q = 1; q <= 7; q++)
                            mp[p][q] = tmp[p][q];
                if (i >= 2 && !mp[i - 1][j])
                {
                    swap(mp[i][j], mp[i - 1][j]);
                    dep[u][1] = i, dep[u][2] = j, dep[u][3] = -1;
                    p = tot - calc();
                    dfs(u + 1, p);
                    fal = 0;
                }
                if (!fal)
                    for (p = 1; p <= 5; p++)
                        for (q = 1; q <= 7; q++)
                            mp[p][q] = tmp[p][q];
            }
}
signed main()
{
    int y = 0;
    scanf("%d", &n);
    for (int i = 1, x, j; i <= 5; i++)
    {
        j = 0;
        scanf("%d", &x);
        while (x)
        {
            mp[i][++j] = x;
            if (!flg[x])
            {
                flg[x] = 1;
                N++;
            }
            y++;
            scanf("%d", &x);
        }
    }
    dfs(1, y);
    puts("-1");
    return 0;
}