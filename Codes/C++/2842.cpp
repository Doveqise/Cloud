#include<bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9+7;
ll qpow(ll a,ll b,ll mod)
{
	ll ret=1;
	a%=mod;
	for(;b;b>>=1,a=(a*a)%mod)
		if(b&1)
			ret=(ret*a)%mod;
	return ret;
}
signed main()
{
	ll x,k;
	scanf("%lld%lld",&x,&k);
	printf("%lld\n",qpow(x,qpow(x,k-1,mod-1),mod));
	return 0;
}
