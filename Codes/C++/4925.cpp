#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, l, p, s, w;
ll qpow(ll x, ll b)
{
    ll res = 1 % p;
    x %= p;
    while (b)
    {
        if (b & 1)
            res = (res * x) % p;
        x = (x * x) % p;
        b >>= 1;
    }
    return res % p;
}
signed main()
{
    scanf("%lld%lld%lld%lld%lld", &k, &l, &p, &s, &w);
    k %= p;
    if (!s)
    {
        if (l == 1)
            printf("%lld", k % p);
        else if (l == 2)
            printf("%lld", k * (k - 1) % p);
        else
            printf("%lld", k * (k - 1) % p * qpow(k - 2, l - 2) % p);
    }
    else
    {
        if (l == 1)
            printf("%lld", 1LL);
        else if (l == 2)
            printf("%lld", (k - 1) % p);
        else
            printf("%lld", (k - 1) % p * qpow(k - 2, l - 2) % p);
    }
    return 0;
}