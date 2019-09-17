#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2.5e4 + 5;
int a[maxn], b[maxn];
signed main()
{
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] > b[i] ? (a[i] - b[i]) * y : (b[i] - a[i]) * x;
    printf("%lld\n", ans);
    return 0;
}