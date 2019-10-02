#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 1e2;
const int inf = 0x3f3f3f3f;
multiset<int> det, a;
int st[maxn], ed[maxn];
int ans = inf;
int n, m;
char str[maxn];
inline void add(int x)
{
    multiset<int>::iterator it = a.lower_bound(x);
    int now = *it - x;
    --it;
    now = min(now, x - *it);
    ans = min(ans, now);
    a.insert(x);
}
inline void del(int pos, int x)
{
    det.insert(abs(x - ed[pos]));
    if (pos != n)
        det.erase(det.find(abs(st[pos + 1] - ed[pos]))),
            det.insert(abs(st[pos + 1] - x));
    ed[pos] = x;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &st[i]);
        ed[i] = st[i];
    }
    a.insert(inf), a.insert(-inf);
    for (int i = 1; i < n; i++)
        det.insert(abs(st[i + 1] - ed[i]));
    for (int i = 1; i <= n; i++)
        add(st[i]);
    for (int i = 1, pos, x; i <= m; i++)
    {
        scanf("%s", str);
        if (*str == 'I')
        {
            scanf("%d%d", &pos, &x);
            add(x);
            del(pos, x);
        }
        else if (str[4] == 'S')
            printf("%d\n", ans);
        else
            printf("%d\n", *det.begin());
    }
    return 0;
}