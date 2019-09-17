#include <bits/stdc++.h>
using namespace std;
const double dis_max = 1e17;
const int maxn = 2e5 + 5;
int n, s, e;
int l[maxn], r[maxn];
double ans = 0;
double getdis(double a, double b)
{
    return sqrt(a * a + b * b);
}
void solve()
{
    l[n] = r[n] = e;
    int nowy = 0;
    double nowx = s;
    while (nowy < n)
    {
        double zuoarc = -dis_max, youarc = dis_max;
        int ly = nowy, ry = nowy;
        for (int y = nowy + 1; y <= n; y++)
        {
            double larc = (l[y] - nowx) / (y - nowy), rarc = (r[y] - nowx) / (y - nowy);
            if (larc > zuoarc)
            {
                zuoarc = larc;
                ly = y;
            }
            if (rarc < youarc)
            {
                youarc = rarc;
                ry = y;
            }
            if (zuoarc >= youarc)
            {
                if (ly < ry)
                {
                    ans += hypot(l[ly] - nowx, ly - nowy);
                    nowy = ly;
                    nowx = l[ly];
                }
                else
                {
                    ans += hypot(r[ry] - nowx, ry - nowy);
                    nowy = ry;
                    nowx = r[ry];
                }
                break;
            }
        }
    }
    return;
}

signed main()
{
    scanf("%d%d%d", &n, &s, &e);
    for (int i = 0; i <= n; i++)
        scanf("%d%d", &l[i], &r[i]);
    solve();
    printf("%0.14lf", ans);
    return 0;
}
