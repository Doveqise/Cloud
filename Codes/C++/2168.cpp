#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll w = 0, h = 1;
    bool operator<(const node b) const
    {
        return w == b.w ? h > b.h : w > b.w;
    }
} a;
ll ans;
priority_queue<node> q;
signed main()
{
    ll n, k;
    ans = 0;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a.w);
        q.push(a);
    }
    a.w = 0;
    while ((q.size() - 1) % (k - 1) != 0)
        q.push(a);
    while (q.size() >= k)
    {
        ll h = -1;
        ll w = 0;
        for (int i = 1; i <= k; ++i)
        {
            node t = q.top();
            q.pop();
            h = max(h, t.h);
            w += t.w;
        }
        ans += w;
        a.w = w;
        a.h = h + 1;
        q.push(a);
    }
    printf("%lld\n%lld\n", ans, q.top().h - 1);
    return 0;
}