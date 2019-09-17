#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 3e4 + 5;
const int maxm = 2e2 + 5;
int n, m, s, l;
char str[maxm];
ull tmp[maxn], pre[maxn][maxm], suf[maxn][maxm];
void solve(int n)
{
    for (int i = 1; i <= l; i++)
        pre[n][i] = pre[n][i - 1] * 149 + str[i];
    for (int i = l; i >= 1; i--)
        suf[n][i] = suf[n][i + 1] * 137 + str[i];
}
signed main()
{
    scanf("%d%d%d", &n, &l, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        solve(i);
    }
    for (int j = 1; j <= l; j++)
    {
        for (int i = 1; i <= n; i++)
            tmp[i] = pre[i][j - 1] * 233 + suf[i][j + 1] * 213;
        sort(tmp + 1, tmp + 1 + n);
        int t = 1;
        for (int i = 2; i <= n; i++)
            if (tmp[i] == tmp[i - 1])
            {
                s += t;
                t++;
            }
            else
                t = 1;
    }
    printf("%d\n", s);
    return 0;
}
