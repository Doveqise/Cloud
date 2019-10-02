#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5.1e5 + 5;
int ch[maxn][26], cnt, sta[maxn], sum[maxn];
ll n, m, ans, stp;
void insert()
{
    int u = 0, len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        int c;
        scanf("%d", &c);
        if (!ch[u][c])
            ch[u][c] = ++cnt;
        u = ch[u][c];
        sum[u]++;
    }
    sta[u]++;
}
int query()
{
    int k, nans = 0, flg = 0;
    scanf("%d", &k);
    int u = 0, res = 0;
    for (int i = 0; i < k; i++)
    {
        int c;
        scanf("%d", &c);
        if (flg)
            continue;
        if (!ch[u][c])
        {
            nans = res;
            flg = 1;
        }
        u = ch[u][c];
        res += sta[u];
    }
    return flg ? nans : (res - sta[u] + sum[u]);
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    while (n--)
        insert();
    while (m--)
        printf("%d\n", query());
    return 0;
}