#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5; 
int siz[maxn];
signed main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&siz[i]);
	sort(siz+1,siz+1+n);
	int pos=2;
	for(int i=1;i<=n;i++)
	{
		while(siz[pos]*9<=siz[i]*10&&pos<=n)
			pos++;
		ans+=pos-i-1;
	}
	printf("%d\n",ans);
	return 0;
}
