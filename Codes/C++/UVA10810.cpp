// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005],ans;
void mergesort(int l,int r){
	if(l==r)return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int xx=0,ll=l,rr=mid+1;
	while(ll<=mid&&rr<=r){
		if(a[ll]<=a[rr]){
			xx++;
			b[xx]=a[ll];
			ll++;
		}
		else {
			xx++;
			b[xx]=a[rr];
			rr++;
			ans+=mid-ll+1;
		}
	}
	while(ll<=mid){
		xx++;
		b[xx]=a[ll];
		ll++;
	}
	while(rr<=r){
		xx++;
		b[xx]=a[rr];
		rr++;
	}
	for(int i=1;i<=xx;i++) a[l+i-1]=b[i];
}
signed main(){
	while(cin>>n&&n)
	{
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		mergesort(1,n);
		printf("%lld\n",ans);
	}
	return 0;
}
