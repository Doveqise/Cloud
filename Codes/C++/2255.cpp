#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e2 + 5;
struct node
{
    int l, r;
    bool operator<(const node b) const
    {
        return r == b.r ? l > b.l : r < b.r;
    }
} a[maxn];
signed main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1);
    for (int i = 1, cam1 = 0, cam2 = 0; i <= n; i++)
        if (cam1 <= a[i].l && (++ans))
            cam1 = a[i].r;
        else if (cam2 <= a[i].l && (++ans))
            cam1 ^= cam2 ^= cam1 ^= cam2 = a[i].r;
    printf("%d\n", ans);
    return 0;
}