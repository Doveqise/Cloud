#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e5 + 5;
const int maxm = 5e2 + 5;
const int blo = 2e2 + 5;
typedef long long ll;
ll f[maxn][maxm], a[maxn];
signed main()
{
    cin.tie(0);
    ll q, n, maxx;
    cin >> n >> q;
    maxx = n;
    for (ll ti = 1, tt; ti <= n; ti++)
    {
        cin >> tt;
        a[ti] += tt;
        for (int i = 1; i <= blo; i++)
            f[i][ti % i] += tt;
    }
    for (ll ti = 1, x, y, ans = 0; ti <= q; ti++)
    {
        char opt;
        cin >> opt >> x >> y;
        switch (opt)
        {
        case 'C':
            y = y - a[x];
            a[x] += y;
            maxx = max(maxx, x);
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
            for (int i = y; i <= maxx; i += x)
                ans += a[i];
            printf("%lld\n", ans);
            break;
        }
    }
}