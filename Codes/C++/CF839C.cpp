#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int vis[maxn], siz[maxn];
double f[maxn];
vector<int> ed[maxn];
void dp(int rt)
{
    vis[rt] = 1;
    f[rt] = 0;
    for (int i = 0; i < ed[rt].size(); i++)
    {
        int v = ed[rt][i];
        if (vis[v])
            continue;
        dp(v);
        siz[rt]++;
        f[rt] += f[v] + 1;
    }
    f[rt] /= siz[rt] ? siz[rt] : 1;
}
signed main()
{
    int n, rt = 1;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    dp(rt);
    printf("%.15f", f[1]);
    return 0;
}
