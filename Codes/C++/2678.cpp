#include<bits/stdc++.h>
using namespace std;
int l,n,m,ans;
int d[50005];
bool judge(int x){
	int sum=0,p=0,now=0;
	while(p<n+1){
		p++;
		if(d[p]-d[now]<x) sum++;
		else now=p;
	}
	return sum>m?0:1;
}
signed main(){
	scanf("%d%d%d",&l,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	d[n+1]=l;
	int le=1,ri=l;
	while(le<=ri){
		int mid=(le+ri)>>1;
		if(judge(mid)){
			ans=mid;
			le=mid+1;
		}
		else ri=mid-1;
	}
	printf("%d",ans);
	return 0;
}
