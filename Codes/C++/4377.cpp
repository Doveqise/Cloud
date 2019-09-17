#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 5;
const int maxw = 1e6 + 5;
int n, lim;
int w[maxn], t[maxn];
long long f[maxw];
bool judge(int x)
{
    memset(f, 0x80, sizeof(f));
    f[0] = 0;
    long long tmp = f[lim];
    for (int i = 1; i <= n; i++)
    {
        for (int j = lim; j >= 0; j--)
            if (f[j] != tmp)
            {
                int k = j + w[i];
                k = min(k, lim);
                f[k] = max(f[k], f[j] + t[i] - (long long)w[i] * x);
            }
    }
    return f[lim] >= 0;
}
int solve()
{
    int l = 0, r = maxw;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (judge(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}
int main()
{
    scanf("%d%d", &n, &lim);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &w[i], &t[i]);
        t[i] *= 1000;
    }
    printf("%d", solve());
    return 0;
}