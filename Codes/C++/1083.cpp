#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn],c[maxn],l[maxn],r[maxn],x=-1,n,m;
long long f[maxn],sum;
bool t=1;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&c[i],&l[i],&r[i]);
		f[l[i]]+=c[i];f[r[i]+1]-=c[i];}
	int p=m;
	for(int i=1;i<=n;i++){
		sum+=f[i];
		if(sum>a[i]) while(sum>a[i]){
			f[l[p]]-=c[p];f[r[p]+1]+=c[p];
			if(l[p]<=i&&r[p]>=i) sum-=c[p];
			p--;}
		if(t)x=p,t=0;
		else x=min(x,p);}
	if(x==-1)printf("0");
	else printf("-1\n%d",x+1);
	return 0;
}
