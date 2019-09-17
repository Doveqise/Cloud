#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int nxt[maxn], ans[maxn], dep[maxn], vis[maxn];
void dfs(int u, int dpt)
{
    vis[u] = 1;
    dep[u] = dpt;
    if (ans[nxt[u]])
        ans[u] = ans[nxt[u]] + 1;
    else if (dep[nxt[u]])
    {
        ans[u] = (dep[u] - dep[nxt[u]] + 1);
        int v = u;
        while (u != (v = nxt[v]))
            ans[v] = ans[u];
    }
    else
    {
        dfs(nxt[u], dpt + 1);
        if (!ans[u])
            ans[u] = ans[nxt[u]] + 1;
    }
    return;
}
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nxt[i]);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}