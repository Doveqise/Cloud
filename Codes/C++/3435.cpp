#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
int nxt[maxn];
char str[maxn];
signed main()
{
    ll ans = 0, n;
    scanf("%lld%s", &n, str);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && str[i] != str[j])
            j = nxt[j];
        j += str[i] == str[j];
        nxt[i + 1] = j;
    }
    for (int i = 1, j; i <= n; i++)
    {
        j = i;
        while (nxt[j])
            j = nxt[j];
        nxt[i] = min(nxt[i], j);
        ans += i - j;
    }
    printf("%lld\n", ans);
}
