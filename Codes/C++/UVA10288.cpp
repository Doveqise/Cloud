#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll N, z, m;
signed main()
{
    while (cin >> N)
    {
        // scanf("%lld", &N);
        z = N;
        m = 1;
        ll fm, fz;
        for (int i = 2; i <= N; i++)
        {
            fz = N;
            fm = i;
            ll t = gcd(fm, m);
            z = z * (fm / t) + fz * (m / t);
            m *= (fm / t);
            t = gcd(z, m);
            z /= t;
            m /= t;
        }
        if (m == 1)
        {
            printf("%lld\n", z);
            continue;
        }
        ll x = z / m;
        z %= m;
        ll tmp = x, num = 0;
        while (tmp)
            num++, tmp /= 10;
        for (int i = 1; i <= num; i++)
            printf(" ");
        printf(" %lld\n", z);
        if (x)
            printf("%lld ", x);
        tmp = m;
        while (tmp)
            printf("-"), tmp /= 10;
        puts("");
        for (int i = 1; i <= num; i++)
            printf(" ");
        printf(" %lld\n", m);
    }
    return 0;
}