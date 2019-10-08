#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.5e5 + 5;
#define ls(x) tr[x].son[0]
#define rs(x) tr[x].son[1]
struct tree
{
    int dis, val, fa;
    int son[2];
} tr[maxn];
int findfa(int x)
{
    return tr[x].fa == x ? x : tr[x].fa = findfa(tr[x].fa);
}
int merge(int x, int y)
{
    if (!x || !y)
        return x ? x : y;
    if ((tr[x].val == tr[y].val) ? (x > y) : (tr[x].val > tr[y].val))
        swap(x, y);
    rs(x) = merge(rs(x), y);
    if (tr[ls(x)].dis < tr[rs(x)].dis)
        swap(ls(x), rs(x));
    tr[ls(x)].fa = tr[rs(x)].fa = tr[x].fa = x;
    tr[x].dis = tr[rs(x)].dis + 1;
    return x;
}
void del(int x)
{
    tr[x].val = -1;
    tr[ls(x)].fa = ls(x);
    tr[rs(x)].fa = rs(x);
    tr[x].fa = merge(ls(x), rs(x));
}
signed main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tr[tr[i].fa = i].val);
    for (int i = 1, opt, fax, fay, x, y; i <= m; i++)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            scanf("%d%d", &x, &y);
            if (tr[x].val == -1 || tr[y].val == -1)
                continue;
            fax = findfa(x), fay = findfa(y);
            if (fax != fay)
                tr[fax].fa = tr[fay].fa = merge(fax, fay);
            break;
        case 2:
            scanf("%d", &x);
            if (tr[x].val == -1)
                puts("-1");
            else
            {
                fax = findfa(x);
                printf("%d\n", tr[fax].val);
                del(fax);
            }
        }
    }
}