#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e3 + 5;
const int blo = 7e2 + 10;
typedef long long ll;
ll f[maxm][maxm], a[maxn];
signed main()
{
    ll q,n;
    scanf("%lld", &q);
    for (ll ti = 1, opt, x, y, ans = 0; ti <= q; ti++)
    {
        scanf("%lld%lld%lld", &opt, &x, &y);
        switch (opt)
        {
        case 1:
            a[x] += y;
            n = max(n, x);
            for (int i = 1; i <= blo; i++)
                f[i][x % i] += y;
            break;
        default:
            if (x <= blo)
            {
                printf("%lld\n", f[x][y]);
                break;
            }
            ans = 0;
            for (int i = y; i <= n; i += x)
                ans += a[i];
            printf("%lld\n", ans);
            break;
        }
    }
}