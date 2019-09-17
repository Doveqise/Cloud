#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int n, b[maxn], cnt = 0, s1[maxn], s2[maxn];
bool vis[maxn];
struct node
{
    int a, b;
} a[maxn];
bool judge(int x)
{
    b[++cnt] = x;
    vis[x] = 1;
    if (cnt == n)
        return 1;
    if (!vis[a[x].a])
        return judge(a[x].a);
    if (!vis[a[x].b])
        return judge(a[x].b);
    return 0;
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].a, &a[i].b);
    if (!judge(1))
        return puts("-1"), 0;
    int ans = 0x7FFFFFFF;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int pos = b[i], len = (i + n - pos) % n;
        s1[len]++;
        ans1 = max(ans1, s1[len]);
        pos = (n - b[i]) % n + 1;
        len = (i + n - pos) % n;
        s2[len]++;
        ans2 = max(ans2, s2[len]);
    }
    ans = min(ans, min(n - ans1, n - ans2));
    printf("%d", ans);
    return 0;
}