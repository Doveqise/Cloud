#include <bits/stdc++.h>
const int maxn = 2e2 + 5;
int n, minn = maxn;
int d[maxn], ans[maxn];
void dfs(int x, int p, int step)
{
    if (step >= minn)
        return;
    if (x == (1 << n) - 1 && p == n + 1)
    {
        minn = step;
        memcpy(ans, d, sizeof ans);
        return;
    }
    for (int i = p - 2 > 1 ? p - 2 : 1; i <= p + 2 && i <= (n << 1 | 1); i++)
        if (i < p && x & 1 << (n << 1 | 1) - i || i > p && !(x & 1 << (n << 1 | 1) - i))
            d[step] = i, dfs((x | ((x & 1 << (n << 1 | 1) - i) >> p - i)) & ~(1 << (n << 1 | 1) - i), i, step + 1);
}
int main()
{
    scanf("%d", &n);
    dfs((1 << (n << 1 | 1)) - 1 ^ (1 << n + 1) - 1, n + 1, 0);
    for (int i = 0; i < minn; i++)
    {
        printf("%d ", ans[i]);
        if (i % 20 == 19)
            printf("\n");
    }
    return 0;
}