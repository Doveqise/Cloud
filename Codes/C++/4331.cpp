#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
struct tree
{
    int siz, dis, val, l, r, fa, ls, rs;
} tr[maxn], ss[maxn];
int tot = 0;
ll f[maxn];
int findfa(int x)
{
    return tr[x].fa == x ? x : tr[x].fa = findfa(tr[x].fa);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x ? x : y;
    if (tr[x].val < tr[y].val)
        swap(x, y);
    tr[x].rs = merge(tr[x].rs, y);
    tr[tr[x].rs].fa = x;
    if (tr[tr[x].ls].dis < tr[tr[x].rs].dis)
        swap(tr[x].ls, tr[x].rs);
    tr[x].dis = tr[tr[x].rs].dis + 1;
    return x;
}
signed main()
{
    tr[0].dis = -1;
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tr[i].val);
        tr[i].val -= i;
    }
    for (int i = 1; i <= n; i++)
    {
        ss[++tot] = (tree){1, 0, tr[i].val, i, i, i, 0, 0};
        while (tot > 1 && ss[tot].val < ss[tot - 1].val)
        {
            tot--;
            ss[tot].fa = merge(ss[tot].fa, ss[tot + 1].fa);
            ss[tot].siz += ss[tot + 1].siz;
            ss[tot].r = ss[tot + 1].r;
            while (ss[tot].siz > (ss[tot].r - ss[tot].l + 3) >> 1)
            {
                ss[tot].siz--;
                ss[tot].fa = merge(tr[ss[tot].fa].ls, tr[ss[tot].fa].rs);
            }
            ss[tot].val = tr[ss[tot].fa].val;
        }
    }
    for (int i = 1; i <= tot; i++)
        for (int j = ss[i].l; j <= ss[i].r; j++)
            f[j] = ss[i].val, ans += abs(tr[j].val - f[j]);
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%lld ", f[i] + i);
    return 0;
}