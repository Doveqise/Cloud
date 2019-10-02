#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
const int maxn = 1e3 + 5;
const int bsx = 37;
const int bsy = 59;
uint pw[maxn][maxn], hs[maxn][maxn], hsr[maxn][maxn], hsd[maxn][maxn];
int mp[maxn][maxn], r[maxn][maxn], d[maxn][maxn];
int n, m, ans;
uint read()
{
    uint x;
    scanf("%u", &x);
    return x;
}
int readch()
{
    char ch;
    cin >> ch;
    return ch - '0';
}
void init()
{
    pw[0][0] = 1;
    for (int i = 1; i <= m; i++)
        pw[0][i] = bsx * pw[0][i - 1];
    for (int i = 1; i <= n; i++)
    {
        pw[i][0] = bsy * pw[i - 1][0];
        for (int j = 1; j <= m; j++)
            pw[i][j] = bsx * pw[i][j - 1];
    }
}
void hash(int mp[maxn][maxn], uint hs[maxn][maxn])
{
    for (int i = n; i; i--)
        for (int j = m; j; j--)
            hs[i][j] = mp[i][j] + hs[i + 1][j] * bsy + hs[i][j + 1] * bsx - hs[i + 1][j + 1] * bsx * bsy;
}
uint query(uint hs[maxn][maxn], int tx, int ty, int bx, int by)
{
    return hs[tx][ty] - hs[tx][by + 1] * pw[0][by - ty + 1] - hs[bx + 1][ty] * pw[bx - tx + 1][0] + hs[bx + 1][by + 1] * pw[bx - tx + 1][by - ty + 1];
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (int)ch - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            r[n - i + 1][m - j + 1] = mp[i][j];
    init();
    hash(mp, hs);
    hash(r, hsr);
    int l, r;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            l = 1, r = min(min(i, n - i + 1), min(j, m - j + 1)) + 1;
            while (l < r)
            {
                uint hs1 = query(hs, i - r + 1, j - r + 1, i + r - 1, j + r - 1),
                     hs2 = query(hsr, n - i - r + 2, m - j - r + 2, n - i + r, m - j + r);
                if (hs1 == hs2)
                    break;
                else
                    r--;
            }
            ans = max(r, ans);
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            l = 1, r = min(min(i, n - i), min(j, m - j)) + 1;
            while (l < r)
            {
                uint hs1 = query(hs, i - r + 1, j - r + 1, i + r, j + r),
                     hs2 = query(hsr, n - i - r + 1, m - j - r + 1, n - i + r, m - j + r);
                if (hs1 == hs2)
                    break;
                else
                    r--;
            }
            ans = max(r, ans);
        }
    printf("%d\n", ans > 1 ? ans : -1);
    return 0;
}