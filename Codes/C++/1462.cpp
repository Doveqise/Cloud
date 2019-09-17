#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
const int inf = 1e10 + 18;
int hd[maxn], to[maxn], nxt[maxn], blo[maxn], val[maxn], dis[maxn], vis[maxn];
int tot, L, R, MID, FLG, MAX, n, m, b, ans;
void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    blo[tot] = z;
}
bool spfa()
{
    // printf("####%lld\n", MID);
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    for (int i = 1; i <= n; i++)
        if (val[i] > MID)
            vis[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = hd[u]; i; i = nxt[i])
        {
            int v = to[i];
            // printf("######%lld\n", v);
            if (dis[v] > dis[u] + blo[i])
            {
                dis[v] = dis[u] + blo[i];
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return (dis[n] <= b) ? (FLG = 1) : 0;
}
void solve()
{
    R = inf;
    while (L <= R)
    {
        MID = L + R >> 1;
        if (MID < val[1] || MID < val[n])
        {
            L = MID + 1;
            continue;
        }
        if (!spfa())
            L = MID + 1;
        else
        {
            R = MID - 1;
            ans = MID;
        }
    }
    MID = L + R >> 1;
    FLG ? (ans > MAX ? puts("AFK") : printf("%lld\n", ans)) : (spfa() ? printf("%lld\n", ans) : puts("AFK"));
    return;
}
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &val[i]);
        MAX = R = max(R, val[i]);
    }
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    solve();
    return 0;
}