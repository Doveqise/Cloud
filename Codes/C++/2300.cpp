#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], k[maxn], f[maxn], s[maxn];
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1, j; i <= n; i++)
    {
        for (j = i - 1; j >= 0; j--)
            if (s[i] - s[j] >= k[j])
                break;
        f[i] = f[j] + i - j - 1;
        k[i] = s[i] - s[j];
    }
    printf("%lld\n", f[n]);
}