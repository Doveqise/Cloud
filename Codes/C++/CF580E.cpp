#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
char s[maxn];
signed main()
{
    int n, m, k;
    scanf("%d%d%d%s", &n, &m, &k, s + 1);
    m += k;
    for (int i = 0, f, l, r, c; i < m; i++)
    {
        scanf("%d%d%d%d", &f, &l, &r, &c);
        if (f == 1)
            memset(s + l, c + '0', r - l + 1);
        else
            puts(memcmp(s + l, s + l + c, r - l - c + 1) ? "NO" : "YES");
    }
    return 0;
}