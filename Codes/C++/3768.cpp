#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 8e6 + 5;
map<ll, ll> Sf;
int tot, P[maxn + 1];
ll n, mod, phi[maxn + 1], rev4, rev6, ans;
bool flg[maxn + 1];
ll ppow(ll a, ll b)
{
    ll prod = 1;
    while (b)
    {
        if (b & 1)
            prod = prod * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return prod;
}
ll L(ll n)
{
    ll res;
    res = n % mod * (n + 1) % mod;
    res = res * res % mod * rev4 % mod;
    return res;
}
ll Sum(ll n)
{
    n %= mod;
    ll res = n * (n + 1) % mod * (n + n + 1) % mod * rev6 % mod;
    return res;
}
void shai()
{
    phi[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        if (!flg[i])
            P[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * P[j] <= maxn; j++)
        {
            flg[i * P[j]] = 1;
            if (i % P[j] == 0)
            {
                phi[i * P[j]] = 1LL * P[j] * phi[i] % mod;
                break;
            }
            phi[i * P[j]] = 1LL * phi[P[j]] * phi[i] % mod;
        }
    }
    for (int i = 1; i <= maxn; i++)
        phi[i] = (phi[i - 1] + 1LL * phi[i] * i % mod * i % mod) % mod;
}
ll ny(ll n)
{
    if (n <= maxn)
        return phi[n];
    if (Sf[n])
        return Sf[n];
    ll res = L(n);
    for (ll l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res -= ny(n / l) * ((Sum(r) - Sum(l - 1)) % mod) % mod;
        res %= mod;
    }
    return Sf[n] = (res + mod) % mod;
}
int main()
{
    scanf("%lld %lld", &mod, &n);
    shai();
    rev4 = ppow(4, mod - 2), rev6 = ppow(6, mod - 2);
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += (ny(r) - ny(l - 1)) % mod * L(n / l) % mod;
        ans %= mod;
    }
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}