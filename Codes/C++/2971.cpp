#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k;
int rt;
int col[N];
vector<int> xxl[N];
struct node
{
    int v, nxt;
} a[N];
int head[N], cnt = 0;
void add(int u, int v)
{
    a[++cnt].v = v;
    a[cnt].nxt = head[u];
    head[u] = cnt;
}

int size[N], dep[N], fa[N], son[N], top[N];
int maxn[N], maxid;
void dfs(int u, int f, int d)
{
    int maxson = -1;
    size[u] = 1;
    dep[u] = d;
    fa[u] = f;
    for (int i = head[u]; i; i = a[i].nxt)
    {
        int v = a[i].v;
        if (v == f)
            continue;
        dfs(v, u, d + 1);
        size[u] += size[v];
        if (size[v] > maxson)
            maxson = size[v], son[u] = v;
    }
}
void dfs(int u, int topu)
{
    top[u] = topu;
    if (son[u])
        dfs(son[u], topu);
    for (int i = head[u]; i; i = a[i].nxt)
    {
        int v = a[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs(v, v);
    }
}

int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    return x;
}
int findis(int x, int y)
{
    return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}

int main()
{
    cin >> n >> k;
    for (int i = 1, fa, col; i <= n; i++)
    {
        scanf("%d%d", &col, &fa);
        if (fa)
            add(fa, i);
        else
            rt = i;
        xxl[col].push_back(i);
    }
    dfs(rt, 0, 0);
    dfs(rt, rt);
    for (int i = 1; i <= k; i++)
    {
        int x = 0;
        for (int j = 1; j < (int)xxl[i].size(); j++)
            if (dep[xxl[i][j]] > dep[xxl[i][x]])
                x = j;
        int ans = 0;
        for (int j = 0; j < (int)xxl[i].size(); j++)
            if (j != x)
                ans = max(ans, findis(xxl[i][x], xxl[i][j]));
        printf("%d\n", ans);
    }
    return 0;
}