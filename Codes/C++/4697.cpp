#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, s[maxn], tp;
double r[maxn], x[maxn];
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &x[i], &r[i]);
        while (tp > 0)
        {
            int tmp = s[tp];
            double now = (x[i] - x[tmp]) / 4.0 / r[tmp] * (x[i] - x[tmp]);
            r[i] = now < r[i] ? now : r[i];
            if (r[i] <= r[tmp])
                break;
            else
                --tp;
        }
        s[++tp] = i;
        printf("%.3f\n", r[i]);
    }
    return 0;
}