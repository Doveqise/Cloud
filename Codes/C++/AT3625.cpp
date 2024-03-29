#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define inf 0x7fffffff
#define ll long long
int n,mn[N<<2],add[N<<2],b[N],a[N];
ll ans=0;
inline void pushup(int x){mn[x]=min(mn[x<<1],mn[x<<1|1]);}
inline void pushdown(int x){
	mn[x<<1]+=add[x];mn[x<<1|1]+=add[x];
	add[x<<1]+=add[x];add[x<<1|1]+=add[x];
	add[x]=0;
}
void build(int v,int l,int r){
	if(l==r){mn[v]=b[l];return;}
	int mid=l+r>>1;
	build(v<<1,l,mid);build(v<<1|1,mid+1,r);
	pushup(v);
}
void ins(int v,int l,int r,int x,int y){
	if(x>y) return;
	if(x<=l && r<=y){
		add[v]++;mn[v]++;
		return;
	}int mid=l+r>>1;pushdown(v);
	if(x<=mid) ins(v<<1,l,mid,x,y);
	if(mid<y) ins(v<<1|1,mid+1,r,x,y);
	pushup(v);
} 
int query(int v,int l,int r,int x,int y){
	if(x<=l && r<=y) return mn[v];
	int mid=l+r>>1,s=inf;pushdown(v);
	if(x<=mid) s=min(s,query(v<<1,l,mid,x,y));
	if(mid<y) s=min(s,query(v<<1|1,mid+1,r,x,y));
	return s;
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);int nn=unique(b+1,b+n+1)-b-1;
	build(1,1,nn);
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+nn+1,a[i])-b;
		ans+=query(1,1,nn,p,nn)-a[i];
		ins(1,1,nn,1,p-1);
	}printf("%lld\n",ans);
	return 0;
}