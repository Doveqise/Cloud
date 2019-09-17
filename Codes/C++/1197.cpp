#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,k,num;
int fa[maxn<<1],d[maxn<<1],ans[maxn<<1],vis[maxn<<1];
struct edge
{
	int l,r,val;
	bool operator < (const edge b)const
	{
		return val<b.val;
	}
}
a[maxn];
int findfa(int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void merge(int x,int y)
{
	x=findfa(x);
	y=findfa(y);
	if(x!=y)
	{
		fa[x]=y;
		num--;
	}
}
signed main()
{
	scanf("%d%d",&n,&m);
	num=n;
	for(int i=0;i<n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=(edge){x,y,0};
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&d[i]);
		vis[d[i]]=k-i+1;
	}
	for(int i=1;i<=m;i++)
		a[i].val=max(vis[a[i].l],vis[a[i].r]);
	sort(a+1,a+1+m);
	for(int i=0,j=1;i<=k;i++)
	{
		for(;a[j].val==i;j++)
			merge(a[j].l,a[j].r);
		ans[i]=num-k+i;
	}
	for(int i=k;i>=0;i--)
		printf("%d\n",ans[i]);
	return 0;
}