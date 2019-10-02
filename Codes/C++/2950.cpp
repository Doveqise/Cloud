#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
int n, num, c[maxn], vis[maxn];
ll ans, d;
struct node
{
    double k;
    int id;
} nd[maxn];
bool cmp(node x, node y)
{
    return x.k - y.k > eps;
}
int lowbit(int x) 
{ 
    return x & (-x); 
}
void add(int pos, int x)
{
    while (pos <= (n << 1))
        c[pos] += x, pos += lowbit(pos);
}
ll query(int pos)
{
    ll sum = 0;
    while (pos)
        sum += c[pos], pos -= lowbit(pos);
    return sum;
}
signed main()
{
    scanf("%d%lld", &n, &d);
    for (ll i = 1, a, b, c; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (c * c < d * d * (a * a + b * b))
        {
            double tmp = a * a + b * b, tmp2 = sqrt(d * d * tmp - c * c);
            double x1 = (a * c + b * tmp2) / tmp, x2 = (a * c - b * tmp2) / tmp, y1 = (b * c - a * tmp2) / tmp, y2 = (b * c + a * tmp2) / tmp;
            nd[++num] = (node){atan2(y1, x1), i};
            nd[++num] = (node){atan2(y2, x2), i};
        }
    }
    sort(nd + 1, nd + 1 + num, cmp);
    for (int i = 1; i <= num; i++)
        if (vis[nd[i].id])
            ans += query(i) - query(vis[nd[i].id]), add(vis[nd[i].id], -1);
        else
            vis[nd[i].id] = i, add(i, 1);
    printf("%lld", ans);
    return 0;
}