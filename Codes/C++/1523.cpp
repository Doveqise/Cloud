#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
struct node
{
    int x, y;
    bool operator<(const node b) const
    {
        return x < b.x;
    }
    double getdis(node b)
    {
        return hypot(x - b.x, y - b.y);
    }
} a[maxn];
double dis[maxn][maxn], f[maxn][maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = a[i].getdis(a[j]);
    for (int i = n - 1; i > 1; i--)
        for (int j = 1; j < i; j++)
            if (i == n - 1)
                f[i][j] = dis[i][n] + dis[j][n];
            else
                f[i][j] = min(f[i + 1][j] + dis[i][i + 1], f[i + 1][i] + dis[j][i + 1]);
    printf("%0.2f\n", f[2][1] + dis[1][2]);
    return 0;
}