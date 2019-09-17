#include<bits/stdc++.h>
using namespace std;
int fa[1005];
signed main(){
	long long n,t,ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&fa[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			scanf("%lld",&t);
			if(fa[j]>fa[i]) ans+=t*fa[i];
			else ans+=t*fa[j];
		}
		for(int j=i;j<=n;j++){
			scanf("%lld",&t);
		}
	}
	printf("%lld",ans);
	return 0;
}
