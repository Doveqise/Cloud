#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
ll n, m, l, c, q[maxn], maxx, h, ans, sz[maxn << 4];
typedef struct
{
    ll s, t;
} P;
bool cmp(P aa, P bb)
{
    return aa.s == bb.s ? aa.t < bb.t : aa.s < bb.s;
}
P p[maxn];
ll query(ll x)
{
    int ans = 0;
    for (; x >= 1; x -= x & -x)
        ans += sz[x];
    return ans;
}
void pushup(ll x)
{
    for (; x <= m; x += x & -x)
        sz[x]++;
}
int main()
{
    scanf("%lld%lld%lld", &n, &l, &c);
    m = 1e6;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &q[i]);
        maxx = max(maxx, q[i]);
    }
    for (int i = 0; i < n; i++)
    {
        p[i].s = q[i] * l / maxx;
        p[i].t = q[i] * l % maxx;
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        ans += i * p[i].s - h - (query(m) - query(p[i].t));
        h += p[i].s;
        if (p[i].t)
            pushup(p[i].t);
    }
    printf("%lld", ans);
    return 0;
}