#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n, m, ans, cnt = 0;
int c[maxn], son[maxn], t[maxn], l[maxn], r[maxn];
bool cmp(int a, int b)
{
    return son[a] + c[a] < son[b] + c[b];
}
void dfs(int x)
{
    if (!son[x])
        return;
    for (int i = l[x]; i <= r[x]; i++)
        dfs(t[i]);
    sort(t + l[x], t + r[x] + 1, cmp);
    for (int i = l[x]; i <= r[x]; i++)
        if (c[t[i]] + son[t[i]] + c[x] + son[x] <= m + 1)
        {
            ans++;
            c[x] += c[t[i]];
            son[x] += son[t[i]] - 1;
        }
        else
            break;
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &son[i]);
        l[i] = cnt + 1;
        r[i] = cnt + son[i];
        for (int j = 1, a; j <= son[i]; j++)
        {
            scanf("%d", &a);
            t[++cnt] = a + 1;
        }
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}