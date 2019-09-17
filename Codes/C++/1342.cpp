#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define re register
#define il inline
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
__gnu_pbds::priority_queue<int, greater<int>, thin_heap_tag> q;
__gnu_pbds::priority_queue<int, greater<int>, thin_heap_tag> q1;
int hd[maxn], to[maxn], nxt[maxn], val[maxn], dis[maxn], vis[maxn], hd1[maxn], to1[maxn], nxt1[maxn], val1[maxn], dis1[maxn], vis1[maxn];
int tot, tot1, n, m, ans = 0, ans1;
il int read()
{
    re int x = 0, t = 1;
    re char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * t;
}
il void add(int x, int y, int z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
    nxt1[++tot1] = hd1[y];
    hd1[y] = tot1;
    to1[tot1] = x;
    val1[tot1] = z;
}
il void spfa()
{
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while (q.size())
    {
        re int u = q.top();
        q.pop();
        vis[u] = 0;
        for (re int i = hd[u]; i; i = nxt[i])
        {
            re int v = to[i];
            (dis[v] > dis[u] + val[i]) ? (dis[v] = dis[u] + val[i], vis[v] ? (v = v) : (q.push(v), vis[v] = 1)) : (dis[v] = dis[v]);
        }
    }
    dis1[1] = 0;
    vis1[1] = 1;
    q1.push(1);
    while (q1.size())
    {
        re int u = q1.top();
        q1.pop();
        vis1[u] = 0;
        for (re int i = hd1[u]; i; i = nxt1[i])
        {
            re int v = to1[i];
            (dis1[v] > dis1[u] + val1[i]) ? (dis1[v] = dis1[u] + val1[i], vis1[v] ? (v = v) : (q1.push(v), vis1[v] = 1)) : (dis1[v] = dis1[v]);
        }
    }
}
signed main()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(dis1, 0x3f, sizeof(dis1));
    n = read(), m = read();
    for (re int i = 1, u, v, w; i <= m; i++)
    {
        u = read(), v = read(), w = read();
        add(u, v, w);
    }
    spfa();
    for (re int i = 1; i <= n; i++)
        ans1 += dis[i] + dis1[i];
    printf("%lld\n", ans1);
    return 0;
}