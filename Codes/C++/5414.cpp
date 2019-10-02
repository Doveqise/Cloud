#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn], f[maxn];
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(f, 0, sizeof(f));
        int sum = 0, n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
                if (a[j] <= a[i])
                    f[i] = max(f[i], f[j]);
            f[i] += a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i]);
        printf("%d\n", sum - ans);
    }
}