#include <bits/stdc++.h>
#define k m + l - r
#define bll __int128
using namespace std;
const int maxn = 8e2 + 5;
int n, m;
int num[maxn];
bll ans, p[maxn], f[maxn][maxn];
bll dp(int l, int r)
{
    if (f[l][r] != -1)
        return f[l][r];
    if (r - l >= 1)
        f[l][r] = max(num[l] * p[k] + dp(l + 1, r), dp(l, r - 1) + num[r] * p[k]);
    else
        f[l][r] = num[l] * p[k];
    return f[l][r];
}
void print(bll x)
{
    if (!x)
        return;
    if (x)
        print(x / 10);
    putchar(x % 10 + '0');
}
signed main()
{
    scanf("%d%d", &n, &m);
    p[0] = 1;
    for (int i = 1; i <= m; i++)
        p[i] = p[i - 1] * 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%d", &num[j]);
        memset(f, -1, sizeof(f));
        ans += dp(1, m);
    }
    if (!ans)
        puts("0");
    else
        print(ans);
    return 0;
}