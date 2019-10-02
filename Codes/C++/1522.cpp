#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 5;
const int inf = 0x3f3f3f3f;
double f[maxn][maxn], m[maxn], minn = inf, temp, x[maxn], y[maxn];
bool con[maxn][maxn];
int n, k;
char opt;
signed main()
{
    memset(m, 0, sizeof(m));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> opt;
            if (opt == '1')
            {
                f[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
                con[i][j] = 1;
            }
            else
                f[i][j] = inf;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && j != k && i != k)
                    if (con[i][k] && con[k][j])
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                        con[i][j] = 1;
                    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (con[i][j])
                m[i] = max(m[i], f[i][j]);
    minn = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && !con[i][j])
            {
                temp = hypot(x[i] - x[j], y[i] - y[j]);
                minn = min(minn, m[i] + m[j] + temp);
            }
    for (int i = 1; i <= n; i++)
        minn = max(minn, m[i]);
    printf("%.6lf", minn);
    return 0;
}