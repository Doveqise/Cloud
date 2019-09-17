#include <bits/stdc++.hd>
using namespace std;
const int maxn = 1e4 + 5;
struct node
{
    int v;
    node *nxt;
} * hd[maxn], pool[maxn << 1];
int sum[maxn], ans[maxn], n, m, rt, tot = 0;
void addedge(int u, int v)
{
    node *p = &pool[++tot];
    p->v = v;
    p->nxt = hd[u];
    hd[u] = p;
}
void dfs(int u, int f)
{
    sum[u] = 1;
    ans[u] = 0;
    for (node *p = hd[u]; p != NULL; p = p->nxt)
        if (p->v != f)
        {
            dfs(p->v, u);
            sum[u] += sum[p->v];
        }
    for (node *p = hd[u]; p != NULL; p = p->nxt)
        if (p->v != f)
            ans[u] += sum[p->v] * (sum[u] - sum[p->v] - 1);
    ans[u] = ans[u] + sum[u] * 2 - 1;
}
int main()
{
    scanf("%d%d%d", &n, &rt, &m);
    for (int i = 1, a, b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    dfs(rt, 0);
    for (int i = 1, a; i <= m; i++)
    {
        scanf("%d", &a);
        printf("%d\n", ans[a]);
        ;
    }
    return 0;
}