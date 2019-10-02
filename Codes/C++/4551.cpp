#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int height = 30;
int hd[maxn], to[maxn], nxt[maxn], val[maxn], tot;
int a[maxn], ch[maxn][2];
int cnt = 0;
void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
void dfs(int u, int fa)
{
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        a[v] = a[u] ^ val[i];
        dfs(v, u);
    }
}
void change(int rt, int res)
{
    for (int i = height; i >= 0; i--)
    {
        bool s = res & (1 << i);
        if (!ch[rt][s])
            ch[rt][s] = ++cnt;
        rt = ch[rt][s];
    }
}
int query(int rt, int res)
{
    int ret = 0;
    for (int i = height; i >= 0; i--)
    {
        bool s = !(res & (1 << i));
        if (ch[rt][s])
        {
            ret += (1 << i);
            rt = ch[rt][s];
        }
        else
            rt = ch[rt][!s];
    }
    return ret;
}
signed main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1, x, y, z; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z), add(y, x, z);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        change(0, a[i]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, query(0, a[i]));
    printf("%d\n", ans);
    return 0;
}