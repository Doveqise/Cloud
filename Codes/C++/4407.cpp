#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int ch[maxn][26], sta[maxn], star[maxn] /*wd_*/, vis[maxn], tot, stot;
char str[25];
int n, m, len, has;
void insert()
{
    int u = 0;
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int c = str[i] - 'a';
        if (!ch[u][c])
            ch[u][c] = ++tot;
        u = ch[u][c];
    }
    sta[u] = 1;
}
void dfs(int u, int dep, int flg)
{
    if (sta[u] && dep == len && !flg)
    {
        has = 1;
        return;
    }
    if (sta[u] && dep == len && flg)
    {
        if (!vis[u])
            vis[star[++stot] = u] = 1;
        return;
    }
    int c = str[dep] - 'a';
    if (!flg)
    {
        if (dep < len)
            dfs(u, dep + 1, !flg); //#1
        for (int i = 0; i < 26; i++)
            if (ch[u][i])
            {
                if (i != c)
                    dfs(ch[u][i], dep + 1, !flg); //#2
                dfs(ch[u][i], dep, !flg);         //#3
            }
    }
    if (dep >= len)
        return;
    if (ch[u][c])
        dfs(ch[u][c], dep + 1, flg);
}
signed main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        insert();
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", str);
        len = strlen(str);
        dfs(0, 0, 0);
        if (has)
            puts("-1");
        else
            printf("%d\n", stot);
        while (stot)
            vis[star[stot--]] = 0;
        has = 0;
    }
    return 0;
}