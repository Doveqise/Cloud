#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4e4 + 5;
int n, m, N, a[maxn], p[maxn], f[maxn] = {0, 1}, s[maxn];
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; p[++N] = a[i++])
        while ((!(a[i] - a[i + 1])) && i < n)
            i++;
    for (int i = 1; i <= N; f[++i] = i)
    {
        int nm = 0, k = 1;
        for (int j = i; j; j--)
        {
            if (!s[p[j]])
                nm += s[p[j]] = 1;
            if (nm * nm >= f[i])
                { k = j; break;}
            f[i] = min(f[i], nm * nm + f[j - 1]);
        }
        for (int j = k; j <= i; j++)
            s[p[j]] = 0;
    }
    printf("%lld\n", f[N]);
    return 0;
}