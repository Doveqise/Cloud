#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int val, id;
    bool operator<(const node b) const
    {
        return val < b.val;
    }
} a[maxn];
int vis[maxn];
int ans = -1, cnt = 0;
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i].id = i;
        scanf("%d", &a[i].val);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (i < a[i].id)
            cnt++;
        if (vis[i])
            cnt--;
        vis[a[i].id] = 1;
        ans = max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}