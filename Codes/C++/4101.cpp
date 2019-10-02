#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        printf("%lld\n", !((n - (n / m + (bool)(n % m))) % 2));
    }
}