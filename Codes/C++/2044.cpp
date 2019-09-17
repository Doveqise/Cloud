#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull mod;
ull ksc(ull a, ull b, ull mod)
{
    return (a * b - (long long)((long double)a * b / mod) * mod + mod) % mod;
}
ull pow(ull a, ull b, ull mod)
{
    ull ret = 1, base = a;
    while (b)
    {
        if (b & 1)
            ret = ksc(ret, base, mod);
        base = ksc(base, base, mod);
        b >>= 1;
    }
    return ret;
}
ull sum(ull n, ull t, ull m, ull mod)
{
    if (n == 1)
        return t;
    ull ret = sum(n >> 1, t, m, mod);
    ret = (ret + ksc(ret, pow(m, n >> 1, mod), mod)) % mod;
    if (n & 1)
        ret = (ret + ksc(pow(m, n - 1, mod), t, mod)) % mod;
    return ret;
}
signed main()
{
    ull a, c, x0, n, g;
    scanf("%llu%llu%llu%llu%llu%llu", &mod, &a, &c, &x0, &n, &g);
    ull ans = pow(a, n, mod);
    ans = ksc(ans, x0, mod);
    ans = (ans + sum(n, c, a, mod)) % mod;
    printf("%llu\n", ans % g);
    return 0;
}