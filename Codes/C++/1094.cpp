#include<bits/stdc++.h>
using namespace std;
int tong[100005];
signed main(){
	int w,n,ans=0;
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++)scanf("%d",&tong[i]);
	sort(tong,tong+n);
	int head=0,tail=n-1;
	while(head<tail){
		if(tong[head]+tong[tail]<=w){ans++;head++;tail--;}
		else{ans++;tail--;}
	}
	if(head==tail)ans++;
	printf("%d",ans);
	return 0;
}
