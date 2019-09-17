#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
struct node
{
	int l,w;
	bool operator < (const node b) const
	{
		return l==b.l?w<b.w:l<b.l;
	}
}
a[maxn];
int f[maxn],n,ans=0;
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].w);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			f[i]=a[i].w<a[j].w?max(f[j]+1,f[i]):f[i];
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
