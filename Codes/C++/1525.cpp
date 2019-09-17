#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int fa[maxn<<1];
struct node
{
	int f,s,val;
	bool operator < (const node b) const
	{
		return val>b.val;
	}
}
N[maxn];
int findfa(int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
signed main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&N[i].f,&N[i].s,&N[i].val);
	}	
	sort(N+1,N+m+1);
	for(int i=1;i<=(n<<1);i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int fax=N[i].f,fay=N[i].s;
		if(findfa(fax)==findfa(fay)||findfa(fax+n)==findfa(fay+n))
		{
			ans=N[i].val;
			break;
		}
		fa[fa[fax+n]]=fa[fay];
		fa[fa[fax]]=fa[fay+n];
	}
	printf("%d\n",ans);
	return 0;
}