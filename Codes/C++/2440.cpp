#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int n,k,ans,tot,flag;
bool check(int x){
	int num=0;
	for(int i=1;i<=n;i++){num+=a[i]/x;}
	return num>=k;
}
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);tot+=a[i];}
	if(tot<k){puts("0");return 0;}
	int minn=0,maxx=tot;
	while(minn<maxx){
		int mid=(maxx+minn)>>1;
		if(check(mid)){ans=mid;minn=mid+1;}
		else maxx=mid;
	}
	printf("%d",ans);
	return 0;
}
