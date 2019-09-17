#include<bits/stdc++.h>
using namespace std;
int h[20005],k[20005];
signed main(){
	int n,m,pt=0,ans=0,flag=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&h[i]);
	for(int i=0;i<m;i++)scanf("%d",&k[i]);
	sort(h,h+n);sort(k,k+m);
	for(int i=0;i<m;i++){
		if(k[i]>=h[pt]){
			ans+=k[i];
			pt++;
			if(pt==n){
				flag=1;
				break;
			}
		}
	}
	if(!flag)printf("you died!");
	else printf("%d",ans);
	return 0;
} 
