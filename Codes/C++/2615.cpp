#include <bits/stdc++.h>
using namespace std;
int n, a[40][40], x, y, lim;
signed main()
{
    scanf("%d", &n);
    x = 1, y = (n + 1) / 2, lim = n * n;
    for (int i = 1; i <= lim; i++)
    {
        a[x][y] = i;
        if (!a[(x - 2 + n) % n + 1][y % n + 1])
            x = (x - 2 + n) % n + 1, y = y % n + 1;
        else
            x = x % n + 1;
    }

    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
}