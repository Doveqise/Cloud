#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e2 + 5;
ll n, m, mod, ans, nxt[maxn];
char str[maxn];
struct Matrix
{
    int M[maxn][maxn];
    void clear()
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                M[i][j] = 0;
    }
    Matrix operator*(Matrix b)
    {
        Matrix f;
        f.clear();
        for (ll i = 0; i < m; i++)
            for (ll j = 0; j < m; j++)
                for (ll k = 0; k < m; k++)
                    f.M[i][j] = (f.M[i][j] + M[i][k] * b.M[k][j]) % mod;
        return f;
    }
    Matrix operator^(ll n)
    {
        Matrix t;
        for (ll i = 0; i < m; i++)
            t.M[i][i] = 1;
        for (ll i = n; i; i >>= 1, (*this) = (*this) * (*this))
            if (i & 1)
                t = t * (*this);
        return t;
    }
} f, b;
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &mod);
    scanf("%s", str + 1);
    nxt[1] = 0;
    for (ll i = 2, j = 0; i <= m; i++)
    {
        while (j && str[j + 1] != str[i])
            j = nxt[j];
        j += str[j + 1] == str[i];
        nxt[i] = j;
    }
    for (ll i = 0; i < m; i++)
        for (ll j = '0'; j <= '9'; j++)
        {
            ll p = i;
            while (p && str[p + 1] != j)
                p = nxt[p];
            p += str[p + 1] == j;
            if (p != m)
                b.M[i][p] = (b.M[i][p] + 1) % mod;
        }
    f = b ^ n;
    for (ll i = 0; i < m; i++)
        ans = (ans + f.M[0][i]) % mod;
    printf("%lld\n", ans);
    return 0;
}