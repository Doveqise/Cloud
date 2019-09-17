#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int inf = 0xffffff;
int mx[4] = {1, 0, -1, 0}, my[4] = {0, 1, 0, -1};
int a[maxn * maxn][maxn * maxn], ans[maxn * maxn], b[maxn * maxn];
int n, m, r, minn;
void swap(int x, int y, int z)
{
    for (int i = z; i <= r; i++)
        swap(a[x][i], a[y][i]);
    return;
}
void Xor(int x, int y, int z)
{
    for (int i = z; i <= r; i++)
        a[x][i] ^= a[y][i];
    return;
}
void dfs(int ret, int cnt)
{
    if (cnt > minn)
        return;
    if (ret < 0)
    {
        for (int i = 0; i < r; i++)
            ans[i] = b[i];
        minn = min(minn, cnt);
        return;
    }
    if (!a[ret][ret] && a[ret][r])
        return;
    vector<int> vis;
    if (!a[ret][ret] && !a[ret][r])
    {
        b[ret] = a[ret][r] = 1;
        for (int j = ret - 1; j >= 0; j--)
        {
            if (a[j][ret])
            {
                a[j][r] ^= 1;
                vis.push_back(j);
            }
        }
        dfs(ret - 1, cnt + 1);
        for (int j = vis.size() - 1; j >= 0; j--)
            a[vis[j]][r] ^= 1;
        a[ret][r] = b[ret] = 0;
        dfs(ret - 1, cnt);
        return;
    }
    b[ret] = a[ret][r];
    if (b[ret])
    {
        for (int j = ret - 1; j >= 0; j--)
        {
            if (a[j][ret])
            {
                a[j][r] ^= 1;
                vis.push_back(j);
            }
        }
        dfs(ret - 1, cnt + b[ret]);
        for (int j = vis.size() - 1; j >= 0; j--)
            a[vis[j]][r] ^= 1;
    }
    else
        dfs(ret - 1, cnt);
}
signed main()
{
    scanf("%d%d", &n, &m);
    int t, p, tx, ty;
    r = m * n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            p = i * m + j;
            scanf("%d", &t);
            if (t)
                a[p][r] = 1;
            a[p][p] = 1;
            for (int k = 0; k <= 3; k++)
            {
                tx = i + mx[k];
                ty = j + my[k];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n)
                    continue;
                a[tx * m + ty][p] = 1;
            }
        }
    bool flg;
    for (int i = 0; i < r; i++)
    {
        flg = 0;
        for (int j = i; j < r; j++)
            if (a[j][i])
            {
                flg = 1;
                swap(j, i, i);
                break;
            }
        if (!flg)
            continue;
        for (int j = i + 1; j < r; j++)
        {
            if (a[j][i])
                Xor(j, i, i);
        }
    }
    minn = inf;
    dfs(r - 1, 0);
    if (minn == inf)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[i * m + j]);
        puts("");
    }
    return 0;
}