#include<bits/stdc++.h>
using namespace std;
long long a[100005];
signed main(){
	long long n,ans=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",a+i);
	for(int i=0;i<n-1;i++) ans+=max(a[i],a[i+1]);
	printf("%lld",ans);
	return 0;
}
