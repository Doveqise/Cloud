#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,t1=0,t2,ans=0;scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&t2);if(t2>t1)ans+=t2-t1;t1=t2;}
	printf("%d",ans);
	return 0;
}
