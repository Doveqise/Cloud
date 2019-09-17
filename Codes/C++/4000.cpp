#include <bits/stdc++.h>
#define ll long long

using namespace std;

    const ll maxn = 1e5+5;
    ll dp[maxn * 10] = {}, prime[maxn] = {}, s = 0;
    bool vis[maxn] = {};
    char ch[30000005] = {};
    int len = 0;
inline void init_prime(void)
{
    for(ll i = 2; i < maxn; ++i)
    {
        if(!vis[i]) 
        {
            prime[s]=i;
            ++s;
        }
        for (ll j=0; j < s && i * prime[j] < maxn; ++j)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) 
            {
                break;
            }
        }
    }
    return;
}
inline ll pow_mod(ll a1,ll b1)
{
    ll ans=1;
    while(b1)
    {
        if(b1 & 1) 
        {
            ans = ans * a1;
        }
        b1 >>= 1;
        a1 *= a1;
    }
    return ans;
}
ll pow_mod2(ll a,ll b,ll p)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1) 
        {
            ans = ans * a % p;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
inline ll gcd(ll a,ll b)
{
    return b ? gcd(b, a % b) : a;
}
inline bool f(ll n,ll p)
{
    return pow_mod2(n, (p - 1) >> 1, p) == 1;
}
struct matrix
{
    ll x1,x2,x3,x4;
};
    matrix matrix_a,matrix_b,matrix_c;
inline matrix M2(matrix aa,matrix bb,ll mod)
{
    matrix tmp;
    tmp.x1 = (aa.x1 * bb.x1 % mod + aa.x2 * bb.x3 % mod) % mod;
    tmp.x2 = (aa.x1 * bb.x2 % mod + aa.x2 * bb.x4 % mod) % mod;
    tmp.x3 = (aa.x3 * bb.x1 % mod + aa.x4 * bb.x3 % mod) % mod;
    tmp.x4 = (aa.x3 * bb.x2 % mod + aa.x4 * bb.x4 % mod) % mod;
    return tmp;
}
inline matrix M(ll n,ll mod)
{
    matrix a,b;
    a = matrix_a;
    b = matrix_b;
    while(n)
    {
        if(n&1)
        {
            b = M2(b, a, mod);
        }
        n >>= 1;
        a = M2(a, a, mod);
    }
    return b;
}
    ll fac[100][2], l, x, fs[1000];
void dfs(ll count,ll step)
{
    if(step == l)
    {
        fs[x] = count;
        ++x;
        return ;
    }
    ll sum = 1;
    for(ll i = 0; i < fac[step][1]; ++i)
    {
        sum *= fac[step][0];
        dfs(count * sum, step + 1);
    }
    dfs(count, step + 1);
}
inline ll solve2(ll p)
{
    if(p < 1e6 && dp[p]) 
    {
        return dp[p];
    }
    bool ok = f(5, p);
    ll t;
    if(ok) 
    {
        t = p -  1;
    }
    else 
    {
        t = 2 * p + 2;
    }
    l = 0;
    for(ll i = 0; i<s && prime[i] <= t / prime[i]; ++i)
    {
        if(t % prime[i] == 0)
        {
            ll count = 0;
            fac[l][0] = prime[i];
            while(t % prime[i] == 0)
            {
                ++count;
                t /= prime[i];
            }
            fac[l][1] = count;
            ++l;
        }
    }
    if(t > 1)
    {
        fac[l][0] = t;
        fac[l][1] = 1;
        ++l;
    }
    x = 0;
    dfs(1, 0);
    sort(fs, fs + x);
    for(ll i = 0; i < x; ++i)
    {
        matrix m1 = M(fs[i], p);
        if(m1.x1 == m1.x4 && m1.x1 == 1 && m1.x2 == m1.x3 && m1.x2 == 0)
        {
            if(p < 1e6) 
            {
                dp[p] = fs[i];
            }
            return fs[i];
        } 
    }
}
inline ll solve(ll n)
{
    ll ans = 1, cnt;
    for(ll i = 0; i < s && prime[i] <= n/prime[i]; ++i)
    {
        if(n % prime[i] == 0)
        {
            ll count=0;
            while(n % prime[i] == 0)
            {
                ++count;
                n /= prime[i];
            }
            cnt = pow_mod(prime[i], count - 1);
            cnt *= solve2(prime[i]);
            ans = (ans / gcd(ans, cnt)) * cnt;
        }
    }
    if(n > 1)
    {
        cnt = 1;
        cnt *= solve2(n);
        ans = ans / gcd(ans, cnt) * cnt;
    }
    return ans;
}
int main(){
    ll n, MOD, num = 0;
    init_prime();
    matrix_a.x1 = matrix_a.x2 = matrix_a.x3 = 1;  
    matrix_a.x4 = 0;
    matrix_b.x1 = matrix_b.x4 = 1;  
    matrix_b.x2 = matrix_b.x3 = 0;
    dp[2] = 3;
    dp[3] = 8;
    dp[5] = 20;
    scanf("%s", ch + 1);
    len = strlen(ch + 1);
    scanf("%lld", &n);
    MOD = solve(n);
    for(int i = 1; i <= len; ++i)
    {
        num = num * 10 + ch[i] - '0';
        while(num >= MOD) 
        {
            num -= MOD;
        }
    }
    matrix_c = M(num, n);
    printf("%lld", matrix_c.x2); 
    return 0;
}
