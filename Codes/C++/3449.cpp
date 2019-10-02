#include <bits/stdc++.h>
#define ll long long
#define uint unsigned int
using namespace std;
const uint base = 233;
const int maxn = 2e6 + 5;
int n, m;
uint hsh[maxn], now, pw[maxn];
char str[maxn];
void init()
{
    pw[0] = 1;
    for (int i = 1; i <= 2e6; i++)
        pw[i] = pw[i - 1] * base;
}
uint hash(int l, int r)
{
    return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}
bool jud(int x)
{
    for (register int i = 1; i <= m; i += x)
        if (hash(i, i + x - 1) != now)
            return 0;
    return 1;
}
signed main()
{
    scanf("%d", &n);
    multiset<uint> s;
    init();
    for (int ti = 1; ti <= n; ti++)
    {
        scanf("%d", &m);
        scanf("%s", str + 1);
        for (int i = 1; i <= m; i++)
            hsh[i] = hsh[i - 1] * base + str[i];
        for (int i = 1; i <= m; i++)
        {
            if (m % i)
                continue;
            now = hash(1, i);
            if (jud(i))
            {
                s.insert(now);
                break;
            }
        }
    }
    ll ans = 0;
    while (!s.empty())
    {
        int stri = *s.lower_bound(0), nown = s.count(stri);
        ans += (ll)nown * nown;
        s.erase(stri);
    }
    printf("%lld\n", ans);
}