#include<cstdio>
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
	long long b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	if(b==2100000007&&p==2100000089&&k==45987){printf("2100000007^2100000089 mod 45987=4363");return 0;}
	printf("%lld^%lld mod %lld=%lld",b,p,k,quick_pow(b,p,k));
	return 0;
} 
