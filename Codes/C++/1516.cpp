#include <bits/stdc++.h>
#define ll long long
ll xx, yy, gg;
void exgcd(ll a, ll b)
{
    ll tmp;
    if (!b)
    {
        xx = 1;
        gg = a;
        return;
    }
    exgcd(b, a % b);
    tmp = xx;
    xx = yy;
    yy = tmp - (a / b) * yy;
    return;
}
signed main()
{
    ll x, y, m, n, l;
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
    ll a = n - m, b = l, c = x - y;
    if (a < 0)
        a = -a, c = -c;
    exgcd(a, b);
    if (c % gg)
        puts("Impossible");
    else
        printf("%lld\n", (c / gg * xx % (b / gg) + b / gg) % (b / gg));
    return 0;
}