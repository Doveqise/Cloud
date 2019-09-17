#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int inf = 1e9 + 7;
struct node
{
    int x, w, f, c;
    bool operator<(node b) const
    {
        return x < b.x;
    }
} a[maxn];
int dp[maxn], m[maxn];
signed main()
{
    int l, n, b;
    scanf("%d%d%d", &l, &n, &b);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i].x, &a[i].w, &a[i].f, &a[i].c);
    sort(a + 1, a + 1 + n);
    fill(m + 1, m + 1 + l, inf);
    for (int i = 1; i <= n; i++)
    {
        if (dp[a[i].x + a[i].w] < dp[a[i].x] + a[i].f && m[a[i].x] + a[i].c <= b)
        {
            dp[a[i].x + a[i].w] = dp[a[i].x] + a[i].f;
            m[a[i].x + a[i].w] = m[a[i].x] + a[i].c;
        }
        if (dp[a[i].x + a[i].w] == dp[a[i].x] + a[i].f && m[a[i].x] + a[i].c < m[a[i].x + a[i].w])
            m[a[i].x + a[i].w] = m[a[i].x] + a[i].c;
    }
    if (!dp[l])
        puts("-1");
    else
        printf("%d\n", dp[l]);
    return 0;
}