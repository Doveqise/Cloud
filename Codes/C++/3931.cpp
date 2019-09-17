#include <bits/stdc++.h>
const int inf = 0x7f7f7f7f;
const int maxn = 1e5 + 5;
using namespace std;
struct node
{
    int to, w, nxt;
} b[maxn << 1];
int n, t, r;
int hd[maxn];
void add(int x, int y, int w)
{
    b[++t] = (node){y, w, 0};
    b[t].nxt = hd[x];
    hd[x] = t;
    b[++t] = (node){x, w, 0};
    b[t].nxt = hd[y];
    hd[y] = t;
    return;
}
int query(int k, int opt)
{
    int i;
    int ret = 0;
    for (i = hd[k]; i; i = b[i].nxt)
        if (i != (opt ^ 1))
            ret += query(b[i].to, i);
    if (!b[hd[k]].nxt && k != r)
        ret = b[opt].w;
    else
        ret = min(ret, b[opt].w);
    return ret;
}
int main()
{
    scanf("%d%d", &n, &r);
    t = 1;
    for (int i = 1, x, y, w; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }
    b[0].w = inf;
    printf("%d", query(r, 0));
    return 0;
}