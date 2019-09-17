#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n, m;
int mp[maxn][maxn];
int sol(int x, int y)
{
    int flg = 0;
    if (mp[x - 1][y])
        flg |= (1 << mp[x - 1][y]);
    if (mp[x][y - 1])
        flg |= (1 << mp[x][y - 1]);
    if (mp[x][y + 1])
        flg |= (1 << mp[x][y + 1]);
    int ret, i = 0;
    while (++i)
        if (!(flg & (1 << i)))
        {
            ret = i;
            break;
        }
    return ret;
}
bool jud(int i, int j, int x, int y)
{
    return mp[i][y] || mp[x][j] || x > n || y > m || sol(i, y) != sol(i, j);
}
void out()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            putchar(mp[i][j] + 'A' - 1);
        putchar('\n');
    }
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
                continue;
            int x = i + 1, y = j + 1;
            int mc = sol(i, j);
            while (!jud(i, j, x, y))
                x++, y++;
            x--, y--;
            for (int a = i; a <= x; a++)
                for (int b = j; b <= y; b++)
                    mp[a][b] = mc;
        }
    out();
    return 0;
}