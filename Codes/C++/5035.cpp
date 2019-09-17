#include<bits/stdc++.h>
using namespace std;
long long quick_pow(long long x,long long p,long long mod){
	long long ans=1;
	if(!p) return ans%mod;
	if(p&1) ans*=x;
	ans=ans*quick_pow(x,p>>1,mod)*quick_pow(x,p>>1,mod);
	ans%=mod;
	return ans;
}
int main(){
	long long p;
	scanf("%lld",&p);
	printf("%lld",quick_pow(2,p-1,123456789));
	return 0;
} 