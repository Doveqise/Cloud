#include<cstdio>
#include<algorithm>
using namespace std;
int v[105],vl[105],f[105][1005];
int main(){
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",v+i,vl+i);
	for(int i=1;i<=m;i++){
		for(int j=t;j>=0;j--) {
		if(j>=v[i]) f[i][j]=max(f[i-1][j-v[i]]+vl[i],f[i-1][j]);
		else f[i][j]=f[i-1][j];
		}
	}
	printf("%d",f[m][t]);
	return 0;
} 
