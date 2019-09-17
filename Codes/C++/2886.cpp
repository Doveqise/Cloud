#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int num[maxn];
int n, t, s, c, tot;
struct mp
{
    int a[505][505];
    mp operator*(const mp &x) const
    {
        mp c;
        memset(c.a, 0x3f3f3f3f, sizeof(c.a));
        for (int k = 1; k <= tot; k++)
            for (int i = 1; i <= tot; i++)
                for (int j = 1; j <= tot; j++)
                    c.a[i][j] = min(c.a[i][j], a[i][k] + x.a[k][j]);
        return c;
    }
} dis, ans;
signed main()
{
    memset(dis.a, 0x3f3f3f3f, sizeof(dis.a));
    scanf("%d%d%d%d", &n, &t, &s, &c);
    for (int i = 1, x, y, z; i <= t; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if (!num[y])
            num[y] = ++tot;
        if (!num[z])
            num[z] = ++tot;
        dis.a[num[y]][num[z]] = dis.a[num[z]][num[y]] = x;
    }
    ans = dis;
    n--;
    while (n)
    {
        if (n & 1)
            ans = ans * dis;
        dis = dis * dis;
        n >>= 1;
    }
    printf("%d", ans.a[num[s]][num[c]]);
}