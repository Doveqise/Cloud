#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef pair<int, int> pii;
int hd[maxn], to[maxn << 1], nxt[maxn << 1], val[maxn], fa[maxn], tot;
int nd[maxn], ask[maxn], L[maxn], R[maxn];
pii pt[maxn];
int n;
void add(int x, int y)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
}
void dfs(int u)
{
    L[u] = ++tot;
    pt[tot] = make_pair(val[u], u);
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa[u])
            dfs(v);
    }
    R[u] = tot;
}
#define lowbit(x) ((x) & -(x))
void add(int i)
{
    while (i <= n)
    {
        nd[i]++;
        i += lowbit(i);
    }
}
int query(int i)
{
    int res = 0;
    while (i)
    {
        res += nd[i];
        i -= lowbit(i);
    }
    return res;
}
bool cmp(pii x, pii y)
{
    return x.first > y.first;
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 2, t; i <= n; i++)
    {
        scanf("%d", &t);
        fa[i] = t;
        add(t, i), add(i, t);
    }
    tot = 0;
    dfs(1);
    sort(pt + 1, pt + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        ask[pt[i].second] = query(R[pt[i].second]) - query(L[pt[i].second] - 1);
        add(L[pt[i].second]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ask[i]);
    return 0;
}