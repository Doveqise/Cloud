#include<cstdio>
using namespace std;
unsigned long long gcd(unsigned long long x,unsigned long long y){
    unsigned long long r;
    if(x<y){r=x;x=y;y=r;}
	r=x%y;
    while(r){x=y;y=r;r=x%y;}
    return y;
}
int main(){
	unsigned long long int n,t,ans=1;
	scanf("%llu",&t);
	for(int ti=0;ti<t;ti++){
		scanf("%llu",&n);
		for(unsigned long long i=1;i<=n;i++){ans=ans*i/gcd(ans,i)%1000000007;}
		printf("%llu\n",ans);
	}
	return 0;
}
