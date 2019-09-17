#include<bits/stdc++.h>
using namespace std;
long long a[1000005],ans;
priority_queue<int>que;
signed main(){
	long long n; 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		que.push(-a[i]),que.push(-a[i]);
		ans=ans+a[i]+que.top(),que.pop();
	}
	printf("%lld",ans);
	return 0;
}
