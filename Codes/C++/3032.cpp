#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int val[maxn][maxn] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
};
int mp[maxn][maxn], lie[maxn], hang[maxn], g[maxn];
int n, m, ans = 1e9;
char c;
void dfs(int x, int y, int sum)
{
    if (sum >= ans)
        return;
    if (y > 9)
    {
        if (++m == 1.5e6)
            return;
        x++;
        y = 1;
        if (lie[x - 1] & 1)
            return;
        if (x == 4)
            if ((g[1] & 1) || (g[2] & 1) || (g[3] & 1))
                return;
        if (x == 7)
            if ((g[4] & 1) || (g[5] & 1) || (g[6] & 1))
                return;
        if (x == 10)
        {
            if ((g[7] & 1) || (g[8] & 1) || (g[9] & 1))
                return;
            for (int i = 1; i <= 9; i++)
                if (hang[i] & 1)
                    return;
            ans = sum;
            return;
        }
    }
    dfs(x, y + 1, sum);
    lie[x]++;
    hang[y]++;
    g[val[x][y]]++;
    dfs(x, y + 1, sum + 1);
    lie[x]--;
    hang[y]--;
    g[val[x][y]]--;
}
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            cin >> c;
            if (c == '1')
                mp[i][j] = 1, lie[i]++, hang[j]++, g[val[i][j]]++;
        }
    dfs(1, 1, 0);
    printf("%d", ans);
    return 0;
}