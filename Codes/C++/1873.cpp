#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
long long n,m;
long long a[maxn];
bool check(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++)if(a[i]>x)sum+=a[i]-x;
	return sum>=m;
}
signed main(){
	long long r=0,l=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);r=max(r,a[i]);}
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
