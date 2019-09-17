#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5 + 5;
int en[maxn], fa[maxn];
struct edge
{
    int frm, to, val;
    bool operator<(const edge b) const
    {
        return val > b.val;
    }
} ed[maxn];
int findfa(int x)
{
    return x == fa[x] ? x : fa[x] = findfa(fa[x]);
}
signed main()
{
    int n, k, ans = 0;
    scanf("%lld%lld", &n, &k);
    for (int i = 1, t; i <= k; i++)
    {
        scanf("%lld", &t);
        en[t] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld%lld", &ed[i].frm, &ed[i].to, &ed[i].val);
        ans += ed[fa[i] = i].val;
    }
    sort(ed + 1, ed + (fa[n] = n));
    for (int i = 1, fa1, fa2; i < n; i++)
    {
        fa1 = findfa(ed[i].frm), fa2 = findfa(ed[i].to);
        if ((!(en[fa1] && en[fa2])) && (ans -= ed[i].val))
            if (en[(fa[fa2] = fa1)] || en[fa2])
                en[fa1] = en[fa2] = 1;
    }
    printf("%lld\n", ans);
    return 0;
}