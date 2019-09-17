#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
signed main()
{
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long s1 = 0, s2 = 0;
    for (long long i = 1, j; i <= l - 1; i = j + 1)
    {
        j = (l - 1) / ((l - 1) / i);
        s2 = (s2 + ((l - 1) / i) % mod * ((j - i + 1) % mod) % mod) % mod;
    }
    for (long long i = 1, j; i <= r; i = j + 1)
    {
        j = r / (r / i);
        s1 = (s1 + (r / i) % mod * ((j - i + 1) % mod) % mod) % mod;
    }
    printf("%lld\n", ((s1 - s2) % mod + mod) % mod);
    return 0;
}