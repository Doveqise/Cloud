#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int f[maxn], a[maxn];
signed main()
{
    memset(f, -0x3f, sizeof(f));
    f[0] = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] - a[j] <= i - j && a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}