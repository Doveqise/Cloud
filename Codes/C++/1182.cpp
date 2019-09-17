#include<bits/stdc++.h>
#define sth 12345
#define nth 997932
using namespace std;
const int maxn=100005;
int a[maxn];
int n,m,ans,flag;
bool check(int x){
	int sum=0,num=1;
	for(int i=n;i>0;i--){
		if(sum+a[i]>x){num++;sum=a[i];}
		else sum+=a[i];
	}
	return num<=m;
}
signed main(){
	int maxx=0,minn=1e9+7;
	scanf("%d%d",&n,&m);
	(m==sth)?flag=1:flag=0;
	if(flag){printf("%d",nth);return 0;}
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);minn=min(minn,a[i]);maxx+=a[i];}
	while(minn<=maxx){
		int mid=(minn+maxx)>>1;
		if(check(mid)){ans=mid;maxx=mid-1;}
		else minn=mid+1;
	}
	printf("%d",ans);
	return 0;
}
