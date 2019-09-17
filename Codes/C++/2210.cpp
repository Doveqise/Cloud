#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int INF = 1e9 + 7;
int n, f[MAXN][4], min1;
int b[MAXN], pos[MAXN], vis[MAXN];
inline void generate()
{
    memset(vis, 0, sizeof(vis));
    int a = rand() % n + 1;
    for (int i = 1; i <= n; i++)
    {
        while (vis[a])
            a = rand() % n + 1;
        b[i] = a;
        vis[a] = 1;
        pos[a] = i;
    }
}
inline void check()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++)
            ans += abs(pos[f[b[i]][j]] - i);
    min1 = min(min1, ans);
}
signed main()
{
    srand(time(0));
    min1 = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &f[i][1], &f[i][2], &f[i][3]);
    int clc = clock();
    while (clock() - clc <= 0.9 * CLOCKS_PER_SEC)
    {
        generate();
        check();
    }
    printf("%d\n", min1 / 2);
    return 0;
}