#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
typedef long long ll;
ll f[maxn][maxn], siz[maxn], k;
int hd[maxn], to[maxn],nxt[maxn],val[maxn],tot, n;
inline void add(int x, int y, ll z)
{
    nxt[++tot] = hd[x];
    hd[x] = tot;
    to[tot] = y;
    val[tot] = z;
}
void dp(int now, int fa)
{
    siz[now] = 1;
    f[now][0] = f[now][1] = 0;
    for (int i = hd[now]; i; i = nxt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dp(v, now);
        siz[now] += siz[v];
        for (int j = min(k, siz[now]); j >= 0; j--)
        {
            if (f[now][j] != -1)
                f[now][j] += f[v][0] + siz[v] * (n - k - siz[v]) * val[i];
            for (int k = min(1ll * j, siz[v]); k; k--)
            {
                if (f[now][j - k] == -1)
                    continue;
                ll vl = val[i] * k * (k - k) + val[i] * (siz[v] - k) * (n - k + k - siz[v]);
                f[now][j] = max(f[now][j], f[now][j - k] + f[v][k] + vl);
            }
        }
    }
}
int x, y;
ll z;
int main()
{
    memset(f, -1, sizeof(f));
    scanf("%d%lld", &n, &k);
    if (n - k < k)
        k = n - k;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%lld", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    dp(1, 0);
    printf("%lld\n", f[1][k]);
    return 0;
}