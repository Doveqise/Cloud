#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[15], y[15], mod = 1, ans, a, b;
void exgcd(ll x, ll y)
{
    if (!y)
    {
        a = 1;
        b = 0;
        return;
    }
    exgcd(y, x % y);
    ll t = a;
    a = b;
    b = t - x / y * b;
}
ll mul(ll a, ll b)
{
    ll res = 0;
    if (a < b)
        swap(a, b);
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ll n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &y[i]);
        mod *= y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        exgcd(mod / y[i], y[i]);
        a = (a % y[i] + y[i]) % y[i];
        ans = (ans + mul(mod / y[i] * a, (x[i] % y[i] + y[i]) % y[i])) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}