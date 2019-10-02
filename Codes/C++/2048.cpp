#include <bits/stdc++.h>
#define mp(A, B, C, D) make_pair(make_pair(A, B), make_pair(C, D))
using namespace std;
const int maxn = 5e5 + 5;
typedef pair<int, int> pii;
priority_queue<pair<pii, pii> > q;
int n, m, L, R;
long long ans;
int st[maxn][20], v[maxn], s[maxn], fac[maxn];
int mn(int a, int b)
{
    return s[a] < s[b] ? a : b;
}
int query(int a, int b)
{
    if (a > b)
        return -1;
    int k = fac[b - a + 1];
    return mn(st[a][k], st[b - (1 << k) + 1][k]);
}
signed main()
{
    scanf("%d%d%d%d", &n, &m, &L, &R);
    for (int i = 2; i <= n; i++)
        fac[i] = fac[i >> 1] + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = i, scanf("%d", &v[i]), s[i] = v[i] + s[i - 1];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 <= n; i++)
            st[i][j] = mn(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    for (int i = L; i <= n; i++)
        q.push(mp(s[i] - s[query(max(i - R, 0), i - L)], i, max(i - R, 0), i - L));
    for (int i = 1, a, b, c, d, x, y; i <= m; i++)
    {
        pii t1 = q.top().first, t2 = q.top().second;
        ans += t1.first, x = t1.second, a = t2.first, b = t2.second, y = query(a, b), q.pop();
        c = query(a, y - 1), d = query(y + 1, b);
        if (c != -1)
            q.push(mp(s[x] - s[c], x, a, y - 1));
        if (d != -1)
            q.push(mp(s[x] - s[d], x, y + 1, b));
    }
    printf("%lld\n", ans);
    return 0;
}