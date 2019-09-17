#include <bits/stdc++.h>
using namespace std;
const int sqt = 22;
const int maxn = 5e5 + 5;
int n, p[maxn], siz, dd[maxn], st[maxn], upd[maxn];
long long P, dp[(1 << 8) + 11][(1 << 8) + 11], dp1[(1 << 8) + 11][(1 << 8) + 11], dp2[(1 << 8) + 11][(1 << 8) + 11], ans;
bool cmp(int x, int y)
{
    return dd[x] < dd[y];
}
signed main()
{
    for (int i = 2; i <= 500; i++)
    {
        if (!p[i])
            p[++siz] = i;
        dd[i] = siz;
        for (int j = siz; j > 8 && i % p[j]; j--, dd[i] = j)
            ;
        if (dd[i] < 9)
            dd[i] = 0;
        for (int j = 1; j <= siz && j <= 8; j++)
            st[i] |= (i % p[j] == 0) << j - 1;
        for (int j = 1; j <= siz && i * p[j] <= 500; j++)
        {
            p[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    scanf("%d%lld", &n, &P);
    for (int i = 1; i < n; i++)
        upd[i] = i + 1;
    sort(upd + 1, upd + n, cmp);
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (!dd[upd[i]] || dd[upd[i]] != dd[upd[i - 1]])
            memcpy(dp1, dp, sizeof(dp1)), memcpy(dp2, dp, sizeof(dp2));
        for (int j = (1 << 8) - 1; j >= 0; j--)
            for (int k = (1 << 8) - 1; k >= 0; k--)
            {
                if ((j & k) || (dp1[j][k] | dp2[j][k]) == 0)
                    continue;
                if ((st[upd[i]] & k) == 0)
                    dp1[st[upd[i]] | j][k] = (dp1[st[upd[i]] | j][k] + dp1[j][k]) % P;
                if ((st[upd[i]] & j) == 0)
                    dp2[j][st[upd[i]] | k] = (dp2[j][st[upd[i]] | k] + dp2[j][k]) % P;
            }
        if (!dd[upd[i]] || dd[upd[i]] != dd[upd[i + 1]] || i == n - 1)
            for (int j = 0; j < (1 << 8); j++)
                for (int k = 0; k < (1 << 8); k++)
                    dp[j][k] = (dp1[j][k] + dp2[j][k] - dp[j][k] + P + P) % P;
    }
    for (int i = 0; i < (1 << 8); i++)
        for (int j = 0; j < (1 << 8); j++)
            ans = (ans + dp[i][j]) % P;
    printf("%lld\n", ans);
    return 0;
}