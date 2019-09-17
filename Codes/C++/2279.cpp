#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int s[maxn], fa[maxn], dep[maxn], o[maxn];
int ans = 0;
bool cmp(int x, int y) { return dep[x] > dep[y]; }
signed main()
{
    int n;
    scanf("%d", &n);
    s[1] = 1, o[1] = o[0] = maxn;
    for (int i = 2; i <= n; i++)
        scanf("%d", &fa[i]), dep[i] = dep[fa[i]] + 1, s[i] = i, o[i] = maxn;
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int v = s[i], w = fa[v], u = fa[fa[v]];
        o[v] = min(o[v], min(o[w] + 1, o[u] + 2));
        if (o[v] > 2)
        {
            o[u] = 0, ans++;
            o[fa[u]] = min(o[fa[u]], 1), o[fa[fa[u]]] = min(o[fa[fa[u]]], 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}