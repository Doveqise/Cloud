#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int a, w[N], n;
ll dp[N];
vector<int> G[N];
inline void add(int u, int v) { G[u].push_back(v); }
inline ll max(ll a, ll b) { return a > b ? a : b; }
bool cmp(int a, int b) { return w[a] - dp[a] < w[b] - dp[b]; }
void dfs(int u)
{
    dp[u] = w[u];
    ll tot = 0;
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        dfs(v);
    }
    sort(G[u].begin(), G[u].end(), cmp);
    int v;
    for (int i = 0; i < G[u].size(); ++i)
    {
        v = G[u][i];
        dp[u] = max(dp[u], dp[v] + tot);
        tot += w[v];
    }
    dp[u] = max(dp[u], tot + w[u]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &a);
        add(a, i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);
    dfs(1);
    for (int i = 1; i <= n; ++i)
        printf("%d ", dp[i]);
    return 0;
}