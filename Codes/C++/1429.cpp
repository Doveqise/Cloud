#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 7;
struct node
{
    double x1, y1, x2, y2;
    bool operator<(const node b) const
    {
        return x2 < b.x2;
    }
} p[maxn];
double ans = inf;
signed main()
{
    int n;
    scanf("%d", &n);
    srand(time(0));
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x1, &p[i].y1);
    for (int Ti = 1; Ti <= 1231; Ti++)
    {
        int t = rand() % 1231;
        for (int i = 1; i <= n; i++)
            p[i].x2 = cos(t) * p[i].x1 + p[i].y1 * sin(t), p[i].y2 = cos(t) * p[i].y1 - sin(t) * p[i].x1;
        sort(p + 1, p + n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = max(1, i - 10); j <= min(n, i + 10); j++)
                i == j ? j += 0 : ans = min(ans, hypot((p[i].x1 - p[j].x1), (p[i].y1 - p[j].y1)));
    }
    printf("%.4lf\n", ans);
    return 0;
}