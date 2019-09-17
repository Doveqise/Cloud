#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
signed main()
{
    int m, n, ans = 0;
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += (n - i + 1) * (m - j + 1) * (6 * i * j - 2 * gcd(i, j));
    printf("%lld", ans);
    return 0;
}