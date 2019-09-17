#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int f[maxn * maxn * maxn];
int a[maxn];
signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(f, 0, sizeof(f));
        int n;
        scanf("%d", &n);
        int ans = n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (f[a[i]])
            {
                ans--;
                continue;
            }
            for (int j = a[i]; j <= a[n]; j++)
                f[j] = f[j] | f[j - a[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}