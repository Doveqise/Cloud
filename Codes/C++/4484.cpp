#include <cstdio>
#include <cstring>
#define mod 998244353
typedef long long ll;
int f[2][134217735] , cnt[134217735];
ll pow(ll x , int y)
{
    ll ans = 1;
    while(y)
    {
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod , y >>= 1;
    }
    return ans;
}
int main()
{
    int n , i , j , k , d , t , pos;
    ll ans = 0 , fac = 1;
    for(int ti=1;ti<=100;ti++){
		n=ti-1;
		f[0][0] = 1;
		for(d = i = 1 ; i <= n ; i ++ , d ^= 1)
		{
			memset(f[d] , 0 , sizeof(int) * (1 << i));
			for(j = 0 ; j < (1 << (i - 1)) ; j ++ )
			{
				f[d][j << 1] = (f[d][j << 1] + f[d ^ 1][j]) % mod , pos = -1;
				for(k = i - 1 ; ~k ; k -- )
				{
					t = ((j >> k) << (k + 1)) | (1 << k) | (j & ((1 << k) - 1));
					if(j & (1 << k)) pos = k;
					if(~pos) t ^= (1 << (pos + 1));
					f[d][t] = (f[d][t] + f[d ^ 1][j]) % mod;
				}
			}
		}
		for(i = 1 ; i < (1 << n) ; i ++ ) cnt[i] = cnt[i - (i & -i)] + 1;
		for(i = 0 ; i < (1 << n) ; i ++ ) ans = (ans + 1ll * f[n & 1][i] * (cnt[i] + 1)) % mod;
		for(i = 1 ; i <= n + 1 ; i ++ ) fac = fac * i % mod;
		printf("%lld," , ans * pow(fac , mod - 2) % mod);
	}
    return 0;
}

1,2,332748119,963583091,956853029,596374698,1077049,250910295,994670774,58783403
,146925824,575040722,64515887,253793270,213054888,466009132,594906749,365881755,
333733002,86564138,545021526,172335309,869600770,203623107,262843070,50489299,26
6327541,30027721,
