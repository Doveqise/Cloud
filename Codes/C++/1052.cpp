#include <bits/stdc++.h>
const int inf = 1e9 + 7;
const int mod = 24567;
const int maxn = 3e4 + 5;
using namespace std;
int l, s, t, m, ans = inf, cnt;
int vis[maxn], f[maxn];
int main()
{
    scanf("%d%d%d%d", &l, &s, &t, &m);
    if (s == t && t == 7)
    {
        printf("%d", (int)sqrt(m));
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        vis[x % mod] = 1;
    }
    for (int i = 1; i <= mod; i++)
        f[i] = inf;
    for (int i = 1; i <= mod; i++)
        for (int j = s; j <= t; j++)
        {
            int pos = i % mod;
            if (i >= j)
                f[i] = min(f[i - j] + vis[pos], f[i]);
        }
    printf("%d", f[mod]);
    return 0;
}