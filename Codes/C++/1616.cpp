#include<cstdio>
#include<algorithm>
using namespace std;
int v[10005],w[10005],f[1000005];
int main(){
	int t,n,ans=0;
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%d%d",w+i,v+i);
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=t;j++){
			f[j]=max(f[j],f[j-w[i]]+v[i]); 
		}
	}
	for(int i=1;i<=t;i++) ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
} 
