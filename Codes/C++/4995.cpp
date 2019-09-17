#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 5;
#define int long long
int a[maxn], ans;
signed main()
{
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    int l = 0, r = n;
    while (l < r)
    {
        ans += (a[r] - a[l]) * (a[r] - a[l]);
        l++;
        ans += (a[l] - a[r]) * (a[l] - a[r]);
        r--;
    }
    printf("%lld\n", ans);
    return 0;
}