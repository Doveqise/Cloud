#include<bits/stdc++.h>
using namespace std;
int m,n,ti[10005],now[105],maxt;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&ti[i]);
	for(int i=1;i<=n;i++){
		maxt=1;
		for(int j=2;j<=m;j++) if(now[maxt]>now[j])maxt=j;
		now[maxt]+=ti[i];
	}
	for(int i=1;i<=m;i++)maxt=max(now[i],maxt);
	printf("%d",maxt);
	return 0; 
} 
