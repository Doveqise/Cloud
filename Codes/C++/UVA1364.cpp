#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m;
int num = 1;
struct node
{
    int to;
    int next;
} 
road[maxn*maxn<<1];
int nope[maxn][maxn];
int head[maxn];
int stk[maxn], dfn[maxn], low[maxn];
int cnt = 0, tot = 0 ,top = 0;
vector<int> v[maxn];
int from[maxn][maxn];
int col[maxn], ok[maxn], ans = 0;
void built(int from, int to)
{
    road[++num].next = head[from];
    road[num].to = to;
    head[from] = num;
}
void tarjan(int x)
{
    stk[++top] = x;
    low[x] = dfn[x] = ++cnt;
    for (int i = head[x]; i; i = road[i].next)
    {
        int y = road[i].to;
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (dfn[x] <= low[y])
            {
                v[++tot].push_back(y);
                from[y][tot] = 1;
                while (stk[top] != y)
                {
                    from[stk[top]][tot] = 1;
                    v[tot].push_back(stk[top]);
                    top--;
                }
                top--;
                from[x][tot] = 1;
                v[tot].push_back(x);
            }
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
}
bool dfs(int fr, int x, int fa)
{
    for (int i = head[x]; i; i = road[i].next)
    {
        int y = road[i].to;
        if (y == fa || !from[y][fr])
            continue;
        if (!col[y])
        {
            col[y] = 3 - col[x];
            if (dfs(fr, y, x))
                return 1;
        }
        else if (col[y] == col[x])
            return 1;
    }
    return 0;
}
int main()
{
    while (scanf("%d%d", &n, &m))
    {
        if (!n && !m)
            break;
        num = 1;
        memset(from,0,sizeof(from));
        memset(head, 0, sizeof(head));
        memset(nope, 0, sizeof(nope));
        memset(col, 0, sizeof(col));
        memset(head, 0, sizeof(head));
        memset(road, 0, sizeof(road));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        for (int i = 1; i <= tot; i++)
        {
            v[i].clear();
        }
        ans = 0, cnt = 0, tot = 0;
        memset(ok, 0, sizeof(ok));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            nope[x][y] = nope[y][x] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (!nope[i][j])
                {
                    built(i, j);
                    built(j, i);
                }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        for (int i = 1; i <= tot; i++)
        {
            memset(col, 0, sizeof(col));
            col[v[i][0]] = 1;
            if (dfs(i, v[i][0], 0))
                for (int j = 0; j < (int)v[i].size(); j++)
                    ok[v[i][j]] = 1;
        }
        for (int i = 1; i <= n; i++)
            if (!ok[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}