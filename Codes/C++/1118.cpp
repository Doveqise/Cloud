#include <bits/stdc++.h>
const int PT[][13] =
    {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1},
        {1, 5, 10, 10, 5, 1},
        {1, 6, 15, 20, 15, 6, 1},
        {1, 7, 21, 35, 35, 21, 7, 1},
        {1, 8, 28, 56, 70, 56, 28, 8, 1},
        {1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
        {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1},
        {1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1}};
int a[15];
int n, sum;
bool flg, vis[15];
int dfs(int res, int pos)
{
    if (pos == n)
    {
        if (res == sum)
            flg = 1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        a[pos] = i;
        if (res + PT[n - 1][pos] * a[pos] <= sum)
            dfs(res + PT[n - 1][pos] * a[pos], pos + 1);
        if (flg)
            return 0;
        vis[i] = 0;
    }
}
int main()
{
    scanf("%d%d", &n, &sum);
    dfs(0, 0);
    if (flg)
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
}