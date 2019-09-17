#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
signed main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++)
    {
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(max(max(max(ans, a[i] & a[i + 1]), a[i] & a[i + 2]), a[i] & a[i + 3]), a[i] & a[i + 4]);
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}