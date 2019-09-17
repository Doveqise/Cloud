#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const long double EPS = 1e-6;
struct data
{
    long double mat[N];
    int val;
    inline long double &operator[](const int &x) { return mat[x]; }
    bool operator<(const data &B) const
    {
        return val < B.val;
    }
} a[N];
int n, m, p[N], ans1, ans2;
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%Lf", &a[i][j]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].val);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (fabs(a[i][j]) < EPS)
                continue;
            if (!p[j])
            {
                p[j] = i;
                ++ans1;
                ans2 += a[i].val;
                break;
            }
            double dv = 1.0 * a[i][j] / a[p[j]][j];
            for (int k = j; k <= m; ++k)
                a[i][k] -= dv * a[p[j]][k];
        }
    printf("%d %d", ans1, ans2);
    return 0;
}
