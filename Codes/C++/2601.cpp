#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
const int maxn = 1e3 + 5;
const int bsx = 87;
const int bsy = 79;
uint pw[maxn][maxn], hs[maxn][maxn], hsr[maxn][maxn], hsd[maxn][maxn];
int mp[maxn][maxn], r[maxn][maxn], d[maxn][maxn];
int n, m, ans;
uint read()
{
    uint x;
    scanf("%u", &x);
    return x;
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
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = r[i][m - j + 1] = d[n - i + 1][j] = read();
    init();
    hash(mp, hs);
    hash(r, hsr);
    hash(d, hsd);
    int l, r, mid;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            l = 1, r = min(min(i, n - i + 1), min(j, m - j + 1)) + 1;
            while (l < r)
            {
                mid = l + r >> 1;
                uint hs1 = query(hs, i - mid + 1, j - mid + 1, i + mid - 1, j + mid - 1),
                     hs2 = query(hsr, i - mid + 1, m - j - mid + 2, i + mid - 1, m - j + mid),
                     hs3 = query(hsd, n - i - mid + 2, j - mid + 1, n - i + mid, j + mid - 1);
                if (hs1 == hs2 && hs2 == hs3)
                    l = mid + 1;
                else
                    r = mid;
            }
            ans += l - 1;
        }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            l = 1, r = min(min(i, n - i), min(j, m - j)) + 1;
            while (l < r)
            {
                mid = l + r >> 1;
                uint hs1 = query(hs, i - mid + 1, j - mid + 1, i + mid, j + mid),
                     hs2 = query(hsr, i - mid + 1, m - j - mid + 1, i + mid, m - j + mid),
                     hs3 = query(hsd, n - i - mid + 1, j - mid + 1, n - i + mid, j + mid);
                if (hs1 == hs2 && hs2 == hs3)
                    l = mid + 1;
                else
                    r = mid;
            }
            ans += l - 1;
        }
    printf("%d\n", ans);
    return 0;
}