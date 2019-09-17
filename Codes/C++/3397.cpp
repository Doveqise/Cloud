#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int a[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x1, x2, y1, y2; i < m; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = x1; j <= x2; j++)
            for (int k = y1; k <= y2; k++)
                a[j][k]++;
    }
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
}