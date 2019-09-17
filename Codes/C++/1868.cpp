#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 5;
struct node
{
    int l, r, val;
} nd[maxn];
struct edge
{
    int val, nxt;
} ed[maxn];
int f[maxn], hd[maxn];
int n, m, cnt = 0;
void add(int x, int y)
{
    ed[++cnt].val = y;
    ed[cnt].nxt = hd[x];
    hd[x] = cnt;
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &nd[i].l, &nd[i].r);
        nd[i].val = nd[i].r - nd[i].l + 1;
        add(nd[i].r, nd[i].val);
        m = max(m, nd[i].r);
    }
    for (int i = 1; i <= m; i++)
    {
        f[i] = f[i - 1];
        if (hd[i])
            for (int j = hd[i]; j; j = ed[j].nxt)
                f[i] = max(f[i], f[i - ed[j].val] + ed[j].val);
    }
    printf("%d", f[m]);
    return 0;
}