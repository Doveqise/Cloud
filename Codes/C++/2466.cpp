#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
ll f[2][maxn][maxn], sum[maxn];
struct node
{
    ll x, y, v;
    bool operator<(const node b) const
    {
        return x < b.x;
    }
} p[maxn];
signed main()
{
    ll n, sx;
    scanf("%lld%lld", &n, &sx);
    memset(f, -0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
        scanf("%lld", &p[i].x);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &p[i].y);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &p[i].v);
    p[++n] = (node){sx, 0, 0};
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + p[i].v;
        if (p[i].x == sx && p[i].v == 0)
            f[0][i][i] = f[1][i][i] = 0;
    }
    for (int len = 1; len < n; len++)
        for (int i = 1; i <= n - len; i++)
        {
            f[0][i][len + i] = p[i].y + max(f[0][i + 1][i + len] - (p[i + 1].x - p[i].x) * (sum[n] - (sum[i + len] - sum[i])), f[1][i + 1][i + len] - (p[i + len].x - p[i].x) * (sum[n] - (sum[i + len] - sum[i])));
            f[1][i][len + i] = p[i + len].y + max(f[1][i][i + len - 1] - (p[i + len].x - p[i + len - 1].x) * (sum[n] - (sum[i + len - 1] - sum[i - 1])), f[0][i][i + len - 1] - (p[i + len].x - p[i].x) * (sum[n] - (sum[i + len - 1] - sum[i - 1])));
        }
    printf("%.3lf", max(f[1][1][n], f[0][1][n]) / 1000.0);
    return 0;
}