#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int f[maxn][maxn], a[maxn][maxn];
signed main()
{
    int r;
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= r; i++)
        f[r][i] = a[r][i];
    for (int i = r - 1; i; i--)
        for (int j = 1; j <= i; j++)
            f[i][j] = a[i][j] + max(f[i + 1][j], f[i + 1][j + 1]);
    printf("%d\r", f[1][1]);
    return 0;
}