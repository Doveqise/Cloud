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
    return tr[x].fa == x ? x : tr[x].fa = findfa(tr[x].fa);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x ? x : y;
    if ((tr[x].val == tr[y].val) ? (x < y) : (tr[x].val < tr[y].val))
        swap(x, y);
    tr[x].rs = merge(tr[x].rs, y);
    if (tr[tr[x].ls].dis < tr[tr[x].rs].dis)
        swap(tr[x].ls, tr[x].rs);
    tr[tr[x].ls].fa = tr[tr[x].rs].fa = tr[x].fa = x;
    tr[x].dis = tr[tr[x].rs].dis + 1;
    return x;
}
signed main()
{
    int n, m;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        tr[u].son.push_back(i);
        tr[i].fa = i;
        s[i] = tr[i].val = v;
        c[i] = 1;
        f[i] = w;
    }
    for (int i = n, t; i >= 1; i--)
    {
        t = tr[i].son.size();
        for (int k = 0, j; k < t; k++)
        {
            j = tr[i].son[k];
            tr[i].fa = merge(tr[i].fa, tr[j].fa);
            s[i] += s[j];
            c[i] += c[j];
        }
        while (s[i] > m)
        {
            s[i] -= tr[tr[i].fa].val;
            c[i]--;
            tr[i].fa = merge(tr[tr[i].fa].ls, tr[tr[i].fa].rs);
        }
        ans = max(ans, f[i] * c[i]);
    }
    printf("%lld\n", ans);
}