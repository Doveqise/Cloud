#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
int a, b[maxn], c[maxn], d[maxn], ans[maxn], cnt;
void dfs(int m)
{
    if (m > a)
    {
        cnt++;
        if (cnt <= 3)
        {
            for (int i = 1; i <= a; i++)
                printf("%d ", ans[i]);
            puts("");
            m--;
        }
    }
    for (int i = 1; i <= a; i++)
        if (b[i] != 1 && c[i + m] != 1 && d[i - m + a] != 1)
        {
            b[ans[m] = i] = c[i + m] = 1 = d[i - m + a] = 1;
            dfs(m + 1);
            b[i] = c[i + m] = d[i - m + a] = 0;
        }
}
signed main()
{
    scanf("%d", &a);
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}