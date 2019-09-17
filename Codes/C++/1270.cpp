#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
#define ls(u) u << 1
#define rs(u) u << 1 | 1
int res;
int dp[maxn][maxn];
struct node
{
    int c, v;
} nd[maxn << 2];
void init(int u)
{
    scanf("%d%d", &nd[u].c, &nd[u].v);
    nd[u].c <<= 1;
    if (!nd[u].v)
        init(ls(u)), init(rs(u));
}
int dfs(int u, int res)
{
    if (dp[u][res] > 0 || !res)
        return dp[u][res];
    if (nd[u].v)
        return dp[u][res] = min(nd[u].v, (res - nd[u].c) / 5);
    for (int k = 0; k <= res - nd[u].c; k++)
        dp[u][res] = max(dp[u][res], dfs(ls(u), k) + dfs(rs(u), res - nd[u].c - k));
    return dp[u][res];
}
signed main()
{
    scanf("%d", &res);
    res--;
    init(1);
    printf("%d", dfs(1, res));
    return 0;
}