#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 19930726;
typedef long long ll;
char str[maxn], s[maxn];
int p[maxn], cnt[maxn];
ll n, k, sum;
ll ans = 1;
void init()
{
    str[0] = '@', str[1] = '#';
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        str[++cnt] = s[i];
        str[++cnt] = '#';
    }
    str[++cnt] = '\0';
    n = (n + 1) << 1;
}

void solve()
{
    int mx = 0, id;
    for (int i = 1; i <= n; i++)
    {
        if (i < mx)
            p[i] = min(p[(id << 1) - i], mx - i);
        else
            p[i] = 1;
        while (str[i + p[i]] == str[i - p[i]])
            ++p[i];
        if (p[i] + i > mx)
            mx = p[i] + i, id = i;
        if (!(p[i] % 2))
            cnt[p[i] - 1]++;
    }
}

ll qpow(int x, int b)
{
    if (x == 1)
        return 1;
    ll res = 1, base = x;
    while (b)
    {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld", &n, &k);
    cin >> s + 1;
    init();
    solve();
    for (int i = n; i; i--)
    {
        if (!(i % 2))
            continue;
        sum += cnt[i];
        if (k >= sum)
        {
            ans = ans * qpow(i, sum) % mod;
            k -= sum;
        }
        else
        {
            ans = ans * qpow(i, k) % mod;
            k -= sum;
            break;
        }
    }
    if (k > 0)
        ans = -1;
    printf("%lld\n", ans);
    return 0;
}