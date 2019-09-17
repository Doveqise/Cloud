#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 4e6 + 5;
ull a[maxn];
signed main()
{
    int c, n, a1, b1, d1, a2, b2, d2, i = 1, f1 = 1, f2 = 1;
    scanf("%d%d%d%d%d%d%d%d", &c, &n, &a1, &b1, &d1, &a2, &b2, &d2);
    a[i++] = c;
    while (i < maxn)
    {
        ull x = min(a1 * a[f1] / d1 + b1, a2 * a[f2] / d2 + b2);
        a[i++] = x;
        if (x == a1 * a[f1] / d1 + b1)
            f1++;
        if (x == a2 * a[f2] / d2 + b2)
            f2++;
    }
    printf("%llu\n", a[n]);
    return 0;
}