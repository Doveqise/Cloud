#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int n, m, tp = 0, now = 0, a1 = 0, a2 = 0;
int stk[maxn], mp[maxn][maxn], h[maxn];
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &mp[i][j]);
    for (int j = 1; j <= n; ++j)
    {
        for (int i = 1; i <= m; ++i)
            if (j > 1 && mp[j][i] != mp[j - 1][i])
                ++h[i];
            else
                h[i] = 1;
        now = 1;
        while (now <= m)
        {
            stk[0] = now - 1;
            stk[tp = 1] = now++;
            while (now <= m && (mp[j][now] != mp[j][now - 1]))
            {
                while (tp && h[stk[tp]] > h[now])
                {
                    a1 = max(a1, min(h[stk[tp]], now - stk[tp - 1] - 1) * min(h[stk[tp]], now - stk[tp - 1] - 1));
                    a2 = max(a2, h[stk[tp]] * (now - stk[tp - 1] - 1));
                    --tp;
                }
                stk[++tp] = now++;
            }
            while (tp)
            {
                a1 = max(a1, min(h[stk[tp]], now - stk[tp - 1] - 1) * min(h[stk[tp]], now - stk[tp - 1] - 1));
                a2 = max(a2, h[stk[tp]] * (now - stk[tp - 1] - 1));
                --tp;
            }
        }
    }
    printf("%d\n%d\n", a1, a2);
    return 0;
}