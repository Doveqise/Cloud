#include<bits/stdc++.h>
using namespace std;
int s[1005];
signed main(){
	int n,r;scanf("%d%d",&r,&n);
	while(n!=-1){
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)scanf("%d",&s[i]);
		sort(s+1,s+1+n);
		int nows=s[1],ans=1,l=1,ri=1;
		while(nows+r>s[ri]){
			
		}
		printf("%d\n",ans);
		scanf("%d%d",&r,&n);
	}
	return 0;
}
