#include <bits/stdc++.h>
using namespace std;
const int maxp = 1e1 + 5;
const double eps = 1e-7;
int n, a, b, c, d, upp, dwn, lft, rht;
double ans = 0, res;
struct Point
{
    int x, y;
};
struct Circle
{
    Point c;
    double r;
} cir[maxp];
double equ(double a, double b)
{
    return a + eps > b && a - eps < b;
}
double dis(int a, int b)
{
    return hypot(abs(cir[a].c.x - cir[b].c.x), abs(cir[a].c.y - cir[b].c.y));
}
double dise(int a)
{
    return min(min(abs(cir[a].c.x - lft), abs(cir[a].c.x - rht)), min(abs(cir[a].c.y - upp), abs(cir[a].c.y - dwn)));
}
double getr(int u)
{
    for (int i = 1; i <= n; i++)
        if (i != u && !equ(cir[i].r, -1))
            if (cir[i].r > dis(u, i))
                return 0;
    double ret = dise(u);
    for (int i = 1; i <= n; i++)
        if (i != u && (!equ(cir[i].r, -1)))
            ret = min(ret, dis(u, i) - cir[i].r);
    return ret;
}
void dfs(int pos, double res)
{
    if (pos == n)
    {
        ans = max(ans, res);
        return;
    }
    for (int i = 1; i <= n; i++)
        if (equ(cir[i].r, -1))
        {
            cir[i].r = getr(i);
            dfs(pos + 1, res + M_PI * pow(cir[i].r, 2));
            cir[i].r = -1;
        }
    return;
}
signed main()
{
    scanf("%d%d%d%d%d", &n, &a, &c, &b, &d);
    lft = min(a, b), rht = max(a, b), upp = max(c, d), dwn = min(c, d);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &cir[i].c.x, &cir[i].c.y);
    for (int i = 1; i <= n; i++)
        cir[i].r = -1;
    dfs(0, 0);
    printf("%d\n", int(abs(upp - dwn) * abs(rht - lft) - ans + 0.5));
    return 0;
}