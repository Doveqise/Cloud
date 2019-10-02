#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e7 + 5;
int hd[maxn], to[maxn], nxt[maxn], tot;
int inq[maxn], f[maxn];
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    inq[y]++;
}
signed main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!inq[i])
        {
            f[i] = 1;
            q.push(i);
        }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = hd[u]; i; i = nxt[i])
        {
            int v = to[i];
            f[v] = max(f[v], f[u] + 1);
            if (!(--inq[v]))
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", f[i]);
    return 0;
}