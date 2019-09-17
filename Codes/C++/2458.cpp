#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 1.5e3 + 5;
vector<int> g[maxm];
int a[maxm], dp[maxm][3];
void dfs(int u, int fa)
{
    dp[u][1] = a[u];
    dp[u][0] = dp[u][2] = 0;
    int cnt = 0, det = 0x3f3f3f3f;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][2] += min(dp[v][1], dp[v][0]);
        dp[u][1] += min(min(dp[v][0], dp[v][1]), dp[v][2]);
        if (dp[v][1] < dp[v][0])
            ++cnt;
        else
            det = min(det, dp[v][1] - dp[v][0]);
        dp[u][0] += min(dp[v][1], dp[v][0]);
    }
    if (!cnt)
        dp[u][0] += det;
}
signed main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int id, m;
        scanf("%d", &id);
        scanf("%d%d", &a[id], &m);
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            g[id].push_back(x);
            g[x].push_back(id);
        }
    }
    dfs(1, -1);
    printf("%d\n", min(dp[1][1], dp[1][0]));
    return 0;
}