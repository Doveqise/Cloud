#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
const int maxm = 1e6+5;
struct node
{
	int x,y;
}
a[maxn];
int fa[maxm],MAX,MIN=maxm;
bool vis[maxm];
int findfa(int x)
{
	return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
signed main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		MAX=max(MAX,a[i].y);
		MIN=min(MIN,a[i].x);
	}
	for(int i=MIN;i<=MAX;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x=a[i].x,y=a[i].y;
		if(x==y)
			vis[x]=1;
		x=findfa(x);
		while(x<y)
			x=fa[x]=findfa(x+1);
	}
	for(int i=MIN;i<=MAX;i++)
		findfa(i);
	int i=MIN;
	while(i<=MAX)
	{
		if(fa[i]==i)
		{
			if(vis[i])
				printf("%d %d\n",i,i);
			i++;
		}
		else
		{
			printf("%d %d\n",i,fa[i]);
			i=fa[i]+1;
		}
	}
	return 0;
}