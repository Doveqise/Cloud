#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const int inf = 2e9;
bool flg;
int n, m, cnt = 0;
int to[maxm << 2], nxt[maxm << 2], wei[maxm << 2];
int hd[maxn], dis[maxn], vis[maxn];
long long ans = 0;
void add(int a, int b, int c)
{
    to[++cnt] = b;
    nxt[cnt] = hd[a];
    wei[cnt] = c;
    hd[a] = cnt;
}
void spfa(int u)
{
    vis[u] = 1;
    for (int i = hd[u]; i; i = nxt[i])
        if (dis[to[i]] < dis[u] + wei[i])
        {
            if (vis[to[i]] || flg)
            {
                flg = 1;
                break;
            }
            dis[to[i]] = dis[u] + wei[i];
            spfa(to[i]);
        }
    vis[u] = 0;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, opt, a, b; i <= m; i++)
    {
        scanf("%d%d%d", &opt, &a, &b);
        switch (opt)
        {
        case 1:
            add(a, b, 0);
            add(b, a, 0);
            break;
        case 2:
            if (a == b)
            {
                puts("-1");
                return 0;
            }
            add(a, b, 1);
            break;
        case 3:
            add(b, a, 0);
            break;
        case 4:
            if (a == b)
            {
                puts("-1");
                return 0;
            }
            add(b, a, 1);
            break;
        case 5:
            add(a, b, 0);
            break;
        }
    }
    for (int i = n; i >= 1; i--)
        add(0, i, 1);
    for (int i = 1; i <= n; i++)
        dis[i] = -inf;
    spfa(0);
    for (int i = 1; i <= n; i++)
        ans += dis[i];
    flg ? puts("-1") : printf("%lld", ans);
    return 0;
}