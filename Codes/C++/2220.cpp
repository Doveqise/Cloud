#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
struct node
{
    int x, y;
    bool operator<(const node b) const
    {
        return x == b.x ? y < b.y : x < b.x;
    }
} a[maxn];
long long b[maxn];
long long quick_pow(long long a, int k)
{
    long long ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return ans;
}
long long num = 0, ans = 1;
signed main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    num = (long long)n * (n + 1) / 2 % mod;
    for (int i = 1; i <= k; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + k);
    int tmp = 0;
    for (int i = 1; i <= k; i++)
    {
        if (a[i].x != a[i - 1].x)
            b[++tmp] = a[i].y;
        else if (a[i].y != a[i - 1].y)
            b[tmp] = (b[tmp] + a[i].y) % mod;
    }
    for (int i = 1; i <= tmp; i++)
        ans = ans * (num - b[i] + mod) % mod;
    m -= tmp;
    ans = ans * quick_pow(num, m) % mod;
    printf("%lld", ans);
    return 0;
}
