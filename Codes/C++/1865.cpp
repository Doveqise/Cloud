#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, l, r, t, a[1000005];
bool judge(ll x)
{
    if (x == 1)
        return 0;
    for (ll i = 2; i <= sqrt(x); i++)
        if (!x % i)
            return 0;
    return 1;
}
int main()
{
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; i++)
    {
        if (judge(i))
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &l, &r);
        if (l > m || r > m || l < 1 || r < 1)
        {
            printf("Crossing the line\n");
        }
        else
            printf("%lld\n", a[r] - a[l - 1]);
    }
    return 0;
}