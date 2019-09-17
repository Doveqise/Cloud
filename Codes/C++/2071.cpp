#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
int link[maxn], cnt[maxn], w[maxn][maxn];
bool used[maxn];
int ans, n, x, y;
bool find(int x)
{
    for (int i = 1; i <= cnt[x]; i++)
    {
        if (!used[w[x][i]])
        {
            used[w[x][i]] = 1;
            if (!link[w[x][i]] || find(link[w[x][i]]))
            {
                link[w[x][i]] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    for (int i = 1; i <= (n << 1); i++)
    {
        memset(used, 0, sizeof(used));
        if (find(i))
            ans++;
    }
    printf("%d\n", ans);
}
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= (n << 1); i++)
    {
        scanf("%d%d", &x, &y);
        w[i][++cnt[i]] = x;
        w[i][++cnt[i]] = x + n;
        w[i][++cnt[i]] = y;
        w[i][++cnt[i]] = y + n;
    }
}
int main()
{
    init();
    solve();
    return 0;
}