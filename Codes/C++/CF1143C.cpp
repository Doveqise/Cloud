#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int st[maxn],p[maxn],c[maxn];
signed main()
{
	int n,flg=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i],&c[i]);
	for(int i=1;i<=n;i++)
		st[i]=c[i];
	for(int i=1;i<=n;i++)
		if(p[i]>0)
			st[p[i]]&=c[i];
	for(int i=1;i<=n;i++)
		if(st[i])
			printf("%d ",i+1-(flg=1));
	if(!flg)
		puts("-1");
	return 0;
}
