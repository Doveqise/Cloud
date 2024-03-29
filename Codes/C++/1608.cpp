#include <bits/stdc++.h>
#define Ll long long
using namespace std;
const int maxn = 2e3 + 5;
int mp[maxn][maxn], d[maxn], cnt[maxn], in[maxn];
int n, m, x, y, z;
void SPFA(int S, int E)
{
    memset(d, 63, sizeof(d));
    queue<int> Q;
    Q.push(S);
    d[S] = 0;
    cnt[S] = 1;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        in[x] = 0;
        if (x == E)
            continue;
        for (int k = 1; k <= n; k++)
        {
            if (d[x] + mp[x][k] == d[k])
                cnt[k] += cnt[x];
            if (d[x] + mp[x][k] < d[k])
            {
                d[k] = d[x] + mp[x][k];
                cnt[k] = cnt[x];
            }
            if (cnt[k] && !in[k])
                in[k] = 1, Q.push(k);
        }
        cnt[x] = 0;
    }
}
signed main()
{
    memset(mp, 63, sizeof(mp));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        mp[x][y] = min(mp[x][y], z);
    }
    SPFA(1, n);
    if (d[n] == mp[0][0])
        puts("No answer");
    else
        printf("%d %d", d[n], cnt[n]);
}