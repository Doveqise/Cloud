#include <bits/stdc++.h>
#define re register
#define il inline
using namespace std;
template <class T>
void read(T &x)
{
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
}
const int maxn = 1e5 + 5;
static const int maxm = 2e5 + 5;
int ver[maxm], head[maxn], next[maxm], edge[maxm], tot, ver1[maxm], head1[maxn], next1[maxm], edge1[maxm], tot1;
il void add(int x, int y, int z)
{
    ver[++tot] = y, edge[tot] = z;
    next[tot] = head[x], head[x] = tot;
}
il void add1(int x, int y, int z)
{
    ver1[++tot1] = y, edge1[tot1] = z;
    next1[tot1] = head1[x], head1[x] = tot;
}
int T, n, m, k, p, cnt;
int f[maxn][55], wd[maxn][55];
int dist[maxn];
bool vis[maxn];
il void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(n);
    vis[n] = 1, dist[n] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head1[x]; i != -1; i = next1[i])
        {
            int y = ver1[i];
            if (dist[y] > dist[x] + edge1[i])
            {
                dist[y] = dist[x] + edge1[i];
                if (!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    return;
}

bool flg;

il int dfs(int x, int know)
{
    if (wd[x][know])
    {
        flg = 1;
        return 0;
    }
    if (f[x][know] > 0)
        return f[x][know];
    wd[x][know] = 1;
    re int sum = 0;
    for (re int i = head[x]; i != -1; i = next[i])
    {
        re int y = ver[i];
        re int tmp = know - (dist[y] + edge[i] - dist[x]);
        if (tmp < 0 || tmp > k)
            continue;
        sum = (sum + dfs(y, tmp)) % p;
        if (flg)
            return 0;
    }
    if (x == n && know == 0)
        sum = 1;
    wd[x][know] = 0;
    return f[x][know] = sum;
}

signed main()
{
    read(T);
    int x, y, z;
    while (T--)
    {
        memset(f, 0, sizeof(f));
        read(n), read(m), read(k), read(p);
        memset(ver, -1, sizeof(ver));
        memset(head, -1, sizeof(head));
        memset(next, -1, sizeof(next));
        memset(edge, -1, sizeof(edge));
        tot = 0;
        memset(ver1, -1, sizeof(ver));
        memset(head1, -1, sizeof(head));
        memset(next1, -1, sizeof(next));
        memset(edge1, -1, sizeof(edge));
        tot1 = 0;
        flg = 0;
        for (re int i = 1; i <= m; i++)
        {
            read(x), read(y), read(z);
            add(x, y, z), add1(y, x, z);
        }
        spfa();
        int ans = 0;
        for (re int i = 0; i <= k; i++)
        {
            memset(wd, 0, sizeof(wd));
            ans = (ans + dfs(1, i)) % p;
        }
        if (flg)
        {
            puts("-1");
            continue;
        }
        else
        {
            printf("%d\n", ans);
            continue;
        }
    }
    return 0;
}