#include<bits/stdc++.h>
using namespace std;
int v[300],p[300],f[1000000];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",v+i,p+i);
	for(int i=1;i<=m;i++){
		for(int j=n;j>=v[i];j--){
		f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
		}
	}
	printf("%d",f[n]);
	return 0;
} 
