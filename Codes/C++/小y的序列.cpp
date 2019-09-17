#include<bits/stdc++.h>
using namespace std;
int a[100005],vis[100005];
signed main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int t=0,tm=1;
	while(t<m){
		int flag=0;if(tm>n)return 0;if(vis[a[tm]]){tm++;continue;}
		for(int i=n;i>tm;i--){if(a[i]==a[tm]){printf("%d %d\n",tm,i);flag++;vis[a[i]]=1;break;}}
		if(!flag)printf("%d %d\n",tm,tm);
		tm++;t++;
	}
	return 0;
}