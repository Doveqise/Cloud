#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e5 + 5;
typedef long long ll;
struct tree
{
    int dis, val, fa, ls, rs;
    vector<int> son;
} tr[maxn];
ll f[maxn], c[maxn], s[maxn];
int findfa(int x)
{
    return tr[x].fa == x ? x : tr[x].fa=findfa(tr[x].fa);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x ? x : y;
    if (tr[x].val < tr[y].val)
        swap(x, y);
    tr[x].rs = merge(tr[x].rs, y);
    int lc = tr[x].ls, rc = tr[x].rs;
    tr[rc].fa = x;
    if (tr[lc].dis < tr[rc].dis)
        swap(tr[x].ls, tr[x].rs);
    if (tr[x].rs)
        tr[x].dis = tr[tr[x].rs].dis + 1;
    else
        tr[x].dis = 0;
    return x;
}
int del(int x)
{
    int lc = tr[x].ls, rc = tr[x].rs;
    tr[lc].fa = lc;
    tr[rc].fa = rc;
    tr[x].ls = tr[x].rs = tr[x].dis = 0;
    return merge(lc, rc);
}
signed main()
{
    int n, m;
    while (cin >> n)
    {
        memset(tr, 0, sizeof(tr));
        for (int i = 1; i <= n; i++)
            scanf("%d", &tr[tr[i].fa = i].val);
        scanf("%d", &m);
        for (int i = 1, x, y; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            x = findfa(tr[x].fa), y = findfa(tr[y].fa);
            if (x == y)
                puts("-1");
            else
            {
                tr[x].val /= 2, tr[y].val /= 2;
                int L = del(x);
                int R = del(y);
                L = merge(L, x);
                R = merge(R, y);
                L = merge(L, R);
                printf("%d\n", tr[L].val);
            }
        }
    }
}