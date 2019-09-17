#include<bits/stdc++.h>
using namespace std;
int m,n,a[100001];int sum[100001];int c[17];
int b[17];int f[(1<<16)+10];
int maxx;int ans=-1;int tot;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){cin>>c[i]; tot+=c[i];}
    for(int i=1;i<=n;i++){cin>>a[i]; sum[i]=sum[i-1]+a[i];}
    b[1]=1;
    for(int i=2;i<=m;i++) b[i]=b[i-1]<<1;
    maxx=(1<<m)-1;
    for(int i=0;i<=maxx;i++) for(int j=1;j<=m;j++)
		if((i&b[j])){
			int tmp=f[i^b[j]];
			tmp=upper_bound(sum+1,sum+n+1,sum[tmp]+c[j])-sum;
			f[i]=max(f[i],tmp-1);}
    for(int i=0;i<=maxx;i++)
        if(f[i]==n){
            int cnt=0; for(int j=1;j<=m;j++) if(i&b[j]) cnt+=c[j];
			ans=max(ans,tot-cnt);}
        if(ans<0) cout<<-1;
    else cout<<ans;
    return 0;
}
