#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
struct node
{
    ll st, ed;
    bool operator<(const node &b) const
    {
        return st < b.st;
    }
} e[maxn];
int n, tp;
ll t, q[maxn];
signed main()
{
    scanf("%d%lld", &n, &t);
    for (int i = 1, a, b; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        e[i].st = a;
        e[i].ed = a + b * t;
    }
    sort(e + 1, e + 1 + n);
    q[++tp] = -e[1].ed;
    for (int i = 2; i <= n; i++)
    {
        ll x = -e[i].ed;
        if (x >= q[tp])
            q[++tp] = x;
        else
            *upper_bound(q + 1, q + 1 + tp, x) = x;
    }
    printf("%d\n", tp);
    return 0;
}