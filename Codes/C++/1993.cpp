#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e4 + 5;
const int inf = 2e9;
bool flg;
int n, m, cnt = 0;
int to[maxm << 2], nxt[maxm << 2], wei[maxm << 2];
int hd[maxn], dis[maxn], vis[maxn];
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
    for (int i = 1, opt, a, b, c; i <= m; i++)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            scanf("%d%d%d", &a, &b, &c);
            add(b, a, c);
            break;
        case 2:
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, -c);
            break;
        case 3:
            scanf("%d%d", &a, &b);
            add(a, b, 0);
            add(b, a, 0);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        add(0, i, 0);
    for (int i = 1; i <= n; i++)
        dis[i] = -inf;
    spfa(0);
    puts(flg ? "No" : "Yes");
    return 0;
}