#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 5;
struct edge
{
    int to, val, nxt;
} ed[maxn << 1];
int hd[maxn], maxp[maxn], siz[maxn], dis[maxn], cnt;
int vis[maxn], tst[maxn], jud[maxn], q[maxn], re[maxn];
int query[maxn];
int sum, root, n, m, sz, ans, mx;
void add(int x, int y, int z)
{
    ed[++cnt].val = z;
    ed[cnt].to = y;
    ed[cnt].nxt = hd[x];
    hd[x] = cnt;
}
void findroot(int id, int fa)
{
    siz[id] = 1;
    int num = 0;
    for (int i = hd[id]; i; i = ed[i].nxt)
    {
        if (ed[i].to == fa || vis[ed[i].to])
            continue;
        findroot(ed[i].to, id);
        siz[id] += siz[ed[i].to];
        num = max(num, siz[ed[i].to]);
    }
    num = max(num, sz - siz[id]);
    if (num < mx)
    {
        root = id;
        mx = num;
    }
}
void findis(int id, int fa)
{
    re[++re[0]] = dis[id];
    for (int i = hd[id]; i; i = ed[i].nxt)
    {
        if (ed[i].to == fa || vis[ed[i].to])
            continue;
        dis[ed[i].to] = dis[id] + ed[i].val;
        findis(ed[i].to, id);
    }
}
int cal(int x, int v)
{
    re[0] = 0;
    int l = 1, sum = 0;
    dis[x] = v;
    findis(x, 0);
    sort(re + 1, re + 1 + re[0]);
    while (l < re[0])
    {
        if (re[l] + re[re[0]] <= m)
        {
            sum += re[0] - l;
            l++;
        }
        else
            re[0]--;
    }
    return sum;
}
void solve(int id)
{
    vis[id] = jud[0] = 1;
    ans += cal(id, 0);
    for (int i = hd[id]; i; i = ed[i].nxt)
    {
        if (vis[ed[i].to])
            continue;
        ans -= cal(ed[i].to, ed[i].val);
        sz = siz[ed[i].to];
        mx = 0x3f3f3f3f;
        findroot(ed[i].to, 0);
        solve(root);
    }
}
signed main()
{
    scanf("%d", &n);
    for (int i = 1, x, y, z; i <= n - 1; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    scanf("%d", &m);
    sz = n;
    mx = 0x3f3f3f3f;
    findroot(1, 0);
    solve(root);
    printf("%d", ans);
    return 0;
}