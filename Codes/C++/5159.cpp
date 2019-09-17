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
	long long b,p,k=998244353;
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&b,&p);
		printf("%lld\n",quick_pow(2,(b-1)*(p-1),k));
	}
	return 0;
} 
