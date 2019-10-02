#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int hd[maxn], to[maxn], nxt[maxn], tot;
int a[maxn], num, ans;
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void dfs(int s, int fa, int dis)
{
    if (dis > ans)
    {
        ans = dis;
        num = s;
    }
    for (int i = hd[s]; i; i = nxt[i])
        if (to[i] != fa)
            dfs(to[i], s, dis + a[s]);
}
signed main()
{
    memset(a, -1, sizeof(a));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
        a[x]++, a[y]++;
    }
    dfs(1, 0, a[1]);
    ans = 0;
    dfs(num, 0, a[num]);
    printf("%d", ans + 2);
    return 0;
}