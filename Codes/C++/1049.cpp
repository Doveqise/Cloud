#include<cstdio>
#include<algorithm>
using namespace std;
int V[50],f[50000];
int main(){
	int v,n;
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++) scanf("%d",V+i);
	for(int i=1;i<=n;i++){
		for(int j=v;j>=V[i];j--){
			f[j]=max(f[j],f[j-V[i]]+V[i]); 
		}
	}
	printf("%d",v-f[v]);
	return 0;
} 
