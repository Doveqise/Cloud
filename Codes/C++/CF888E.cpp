#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a1[50], a2[50], p1, p2;
int h1[maxn], h2[maxn], n1, n2;
int solve()
{
    scanf("%d%d", &n, &m);
    p1 = n / 2, p2 = n - p1;
    for (int i = 1; i <= p1; i++)
        scanf("%d", &a1[i]);
    for (int i = 1; i <= p2; i++)
        scanf("%d", &a2[i]);
    for (int i = 0; i < (1 << p1); i++)
    {
        int t = 0;
        for (int j = 1; j <= p1; j++)
            if (i >> (j - 1) & 1)
                t = (t + a1[j]) % m;
        h1[++n1] = t;
    }
    for (int i = 0; i < (1 << p2); i++)
    {
        int t = 0;
        for (int j = 1; j <= p2; j++)
            if (i >> (j - 1) & 1)
                t = (t + a2[j]) % m;
        h2[++n2] = t;
    }
    sort(h1 + 1, h1 + n1 + 1);
    sort(h2 + 1, h2 + n2 + 1);
    int j = n2, ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        while (h1[i] + h2[j] >= m && j > 0)
            j--;
        if (j <= 0)
            break;
        ans = max(h1[i] + h2[j], ans);
    }
    ans = max(ans, h1[p1] + h2[p2]);
    printf("%d\n", ans);
    return 0;
}
int ans = solve();
signed main()
{
}