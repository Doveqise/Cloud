#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e7+5;
int t, n, m;
ll mod;
ll f[maxn], f1[maxn], f2[maxn];
int p[maxn];
bool tong[maxn];

void init()
{
    int tot = 0;
    memset(tong, 1, sizeof(tong));
    tong[0] = tong[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (tong[i])
            p[++tot] = i;
        for (int j = 1; j <= tot && i * p[j] < maxn; j++)
        {
            tong[i * p[j]] = 0;
            if (!(i % p[j]))
                break;
        }
    }
}

ll power(ll x, ll y)
{
    if (y == 0)
        return 1ll;
    if (y == 1)
        return x % mod;
    ll tmp = power(x, y / 2) % mod;
    if (y % 2)
        return ((tmp * tmp) % mod) * x % mod;
    else
        return tmp * tmp % mod;
}

signed main()
{
    scanf("%lld%lld", &t, &mod);
    init();
    f[1] = f1[1] = f2[1] = 1ll;
    for (int i = 2; i < maxn; i++)
    {
        f[i] = f[i - 1] * i % mod;
        if (tong[i])
        {
            f1[i] = f1[i - 1] * (i - 1) % mod;
            f2[i] = f2[i - 1] * i % mod;
        }
        else
        {
            f1[i] = f1[i - 1];
            f2[i] = f2[i - 1];
        }
    }
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", ((f[n] * f1[m]) % mod) * power(f2[m], mod - 2) % mod);
    }
    return 0;
}