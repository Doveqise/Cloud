#include<bits/stdc++.h>
using namespace std;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int maxn=400005;
int dis[maxn],ll[maxn],ans[maxn],len,a[maxn],n,m;
vector<int>line[maxn];

int data[maxn<<2];
void update(int n){data[n]=min(data[ls(n)],data[rs(n)]);}
void add(int pos,int l,int r,int n,int d){
	if(l==r){data[n]=d;return;}
	int mid=(l+r)>>1;
	if(pos<=mid)add(pos,l,mid,ls(n),d);
	else add(pos,mid+1,r,rs(n),d);
	update(n);
}
int question(int d){
	int l=1,r=len,n=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(data[ls(n)]<d)r=mid,n=ls(n);
		else l=mid+1,n=rs(n);
	}
	return dis[l];
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&dis[++len]);a[i]=dis[len];dis[++len]=a[i]+1;}
	dis[++len]=0;sort(dis+1,dis+1+len);
	len=unique(dis+1,dis+1+len)-dis-1;
	for(int i=1,t;i<=m;i++){
		scanf("%d%d",&ll[i],&t);
		line[t].push_back(i);
	}
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(dis+1,dis+1+len,a[i])-dis;
		add(a[i],1,len,1,i);
		for(int j=0;j<(int)line[i].size();j++){
			int k=line[i][j];
			ans[k]=question(ll[k]);
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}